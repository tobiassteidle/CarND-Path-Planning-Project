//
//  Car.hpp
//  path_planning
//
//  Created by Tobias Steidle on 20.05.18.
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
#include <vector>

using namespace std;

const double MAX_SPEED = 49.5;
const double MAX_ACCELERATION = .224;
const double SECURITY_DISTANCE = 30;

enum Lane {UNKNOWN=-1, LEFT=0, MIDDLE=1, RIGHT=2};

struct target_info {
  bool left;
  bool ahead;
  bool right;
};

class Car {
  
  private:
    double speed_difference;
  
    Lane lane_for_d(const int d);
    target_info prediction(int prev_size, double car_s, const vector<vector<double>>& sensor_fusion);
  
  public:
    Car();
  
    void prediction_and_behavior(int prev_size, double car_s, const vector<vector<double>>& sensor_fusion);
    void update_veclocity();
  
    Lane lane;
    double reference_velocity;
};

#endif /* Car_hpp */
