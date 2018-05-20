//
//  Car.hpp
//  path_planning
//
//  Created by Tobias Steidle on 20.05.18.
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>

class Car {
  
  private:

  
  public:
    Car(double reference_velocity, int initial_lane);
  
    int lane;
    double reference_velocity;
  
};

#endif /* Car_hpp */
