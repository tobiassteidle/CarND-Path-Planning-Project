# CarND-Path-Planning-Project
Self-Driving Car Engineer Nanodegree Program
  
## Video
[![MPC](http://img.youtube.com/vi/H5Z6NXRMo2s/0.jpg)](http://www.youtube.com/watch?v=H5Z6NXRMo2s "Path Planning")

## Rubric points
### Criteria:
-	The car is able to drive at least 4.32 miles without incident.
-	The car drives according to the speed limit.
-	Max Acceleration and Jerk are not Exceeded.
-	Car does not have collisions.
-	The car stays in its lane, except for the time between changing lanes.
-	The car is able to change lanes



### 1. Prediction [method prediction()](./src/Car.cpp#L30)

### 2. Behavior [method prediction_and_behavior()](./src/Car.cpp#L66)

### 3. Trajectory [Lines 255-354()](./src/main.cpp#L255)
The trajectory is generated in the manner described in the „Walkthrough and Q&A“ Video.

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


