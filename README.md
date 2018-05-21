# CarND-Path-Planning-Project
Self-Driving Car Engineer Nanodegree Program
  
## Video
[![MPC](http://img.youtube.com/vi/e103ScHK6bw/0.jpg)](http://www.youtube.com/watch?v=e103ScHK6bw "Path Planning")

## Rubric points
### Criteria:
-	The car is able to drive at least 4.32 miles without incident.
-	The car drives according to the speed limit.
-	Max Acceleration and Jerk are not Exceeded.
-	Car does not have collisions.
-	The car stays in its lane, except for the time between changing lanes.
-	The car is able to change lanes

### The implementation of the project consists of 3 parts:

#### 1. Prediction [method prediction()](./src/Car.cpp#L30)
The Prediction section determines which lane another vehicle is on. First, the value "d" is read out from the sensor data. This value can be used to determine whether a vehicle is on the "left", "middle" or "right" lane.
The system then checks whether the detected vehicle is moving within a safety distance of 30m.
If a vehicle is detected on a lane within the safety distance, the lane is marked as impassable.

#### 2. Behavior [method prediction_and_behavior()](./src/Car.cpp#L66)
The Behavior section defines how the vehicle reacts in certain situations.
If another road user is directly in front of the vehicle, the system first checks whether it is possible to change to the left-hand lane. If this is blocked, an attempt is made to change to the right-hand lane. If this is also not possible, the vehicle brakes and remains on the same lane.
If the lane can be changed, it will be executed.
If there is no vehicle ahead, an attempt is made to change back to the middle lane.

#### 3. Trajectory [Lines 255-354](./src/main.cpp#L255)
The trajectory is generated in the manner described in the „Walkthrough and Q&A“ Video.

### Weaknesses of the current implementation:
If changing to another lane is not possible, the vehicle brakes again and again and thus increases the distance to the vehicle in front. It would be better to adjust to the speed of the car in front in order not to slow down and accelerate again and again.

The vehicle does not currently check on which lane the traffic is running faster. This means that if the vehicle can change to the left or right lane, it is primarily changed to the left lane. Even if the traffic on the right lane would run faster. 

The vehicle also has difficulties if another vehicle suddenly intervenes directly in front of the vehicle in this case it can come to collisions, because the intervention is not detected fast enough and also the braking is too slow in this case.
If another road user intervenes directly in front of the vehicle, the limit value ("Max Jerk") should be exceeded in an emergency.

### Conclusion:
The current implementation was sufficient to reach the required distance of 4.32 miles without an accident, but still offers significant improvement potential due to the weaknesses. 

## Dependencies

* cmake >= 3.5
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `install-mac.sh` or `install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).


