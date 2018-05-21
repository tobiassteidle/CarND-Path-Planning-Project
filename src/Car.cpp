//
//  Car.cpp
//  path_planning
//
//  Created by Tobias Steidle on 20.05.18.
//

#include "Car.hpp"
#include <math.h>

Car::Car() {
  this->lane = MIDDLE;
  this->speed_difference = 0;
  this->reference_velocity = 0;
}

Lane Car::lane_for_d(const int d) {
  
  if(d > 0 && d < 4) {
    return LEFT;
  } else if(d > 4 && d < 8) {
    return MIDDLE;
  } else if(d > 8 && d < 12) {
    return RIGHT;
  }
  
  return UNKNOWN;
}

target_info Car::prediction(int prev_size, double car_s, const vector<vector<double>>& sensor_fusion) {
  target_info info;
  info.left = false;
  info.ahead = false;
  info.right = false;
   
  for(int i = 0; i < sensor_fusion.size(); i++) {
    float d = sensor_fusion[i][6];
    double vx = sensor_fusion[i][3];
    double vy = sensor_fusion[i][4];
    double check_speed = sqrt(vx * vx + vy * vy);
    double check_car_s = sensor_fusion[i][5];
    
    check_car_s += ((double)prev_size * .02 * check_speed);
    
    // get lane of target
    Lane target_lane = lane_for_d(d);
    
    // continue if lane not known
    if(target_lane == UNKNOWN) {
      continue;
    }
    
    // detected target positions
    if(target_lane == this->lane) {
      info.ahead |= check_car_s > car_s && check_car_s - car_s < SECURITY_DISTANCE;
    } else if(target_lane - this->lane == -1) {
      info.left |= car_s - SECURITY_DISTANCE < check_car_s && car_s + SECURITY_DISTANCE > check_car_s;
    } else if(target_lane - this->lane == 1) {
      info.right |= car_s - SECURITY_DISTANCE < check_car_s && car_s + SECURITY_DISTANCE > check_car_s;
    }
  }  
  
  return info;
}

void Car::prediction_and_behavior(int prev_size, double car_s, const vector<vector<double>>& sensor_fusion) {
  target_info target = this->prediction(prev_size, car_s, sensor_fusion);
  
  this->speed_difference = 0;
  
  // if target ahead
  if(target.ahead) {
    
    // try change to left lane
    if(!target.left && this->lane > 0) {
      this->lane = Lane(this->lane - 1);
      
    // try change to right lane
    } else if(!target.right && this->lane != 2) {
      this->lane = Lane(this->lane + 1);
      
    // slow down if necessary
    } else {
      this->speed_difference -= MAX_ACCELERATION;
    }
  } else {
    
    // try to go back to the middle line
    if(this->lane != MIDDLE) {
      if((this->lane == LEFT && !target.right) || (this->lane == RIGHT && !target.left)) {
        this->lane = MIDDLE;
      }
    }
    
    // accelerate to max speed
    if(this->reference_velocity < MAX_SPEED) {
      this->reference_velocity += MAX_ACCELERATION;
    }
  }
}

void Car::update_veclocity() {
  this->reference_velocity += this->speed_difference;
  if(this->reference_velocity > MAX_SPEED) {
    this->reference_velocity = MAX_SPEED;
  } else if(this->reference_velocity < MAX_ACCELERATION) {
    this->reference_velocity = MAX_ACCELERATION;
  }
}
