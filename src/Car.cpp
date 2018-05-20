//
//  Car.cpp
//  path_planning
//
//  Created by Tobias Steidle on 20.05.18.
//

#include "Car.hpp"

Car::Car(double reference_velocity, int initial_lane) {
  this->reference_velocity = reference_velocity;
  this->lane = initial_lane;
}


