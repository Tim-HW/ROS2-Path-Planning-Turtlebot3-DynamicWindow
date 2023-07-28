# ROS2-Path-Planning-Turtlebot3-DynamicWindow
ROS2 Package for turtlebot3 to execute local path planning using the dynamic methods.
This package is an excuse to learn C++ and ROS2. Feel free to use it as you want :D

## Installation

```bash
cd ros_ws/src
git clone https://github.com/Tim-HW/ROS2-PotentialField.git
cd ..
colcon build
source install/setup.bash
```

## Dynamic Window paradigm
The Dynamic Window Approach (DWA) is a popular motion planning algorithm used in robotics to plan the movement of a robot in an environment with obstacles. It is specifically designed for mobile robots operating in 2D space and is widely used in applications like mobile robotics, autonomous vehicles, and robotic navigation.
The main objective of the Dynamic Window Approach is to navigate a robot from its current position to a goal position while avoiding obstacles in its path. The algorithm takes into account the robot's current state (position, orientation, velocity) and the surrounding environment to determine the best velocity commands that allow the robot to move safely and efficiently.
Here's a high-level overview of how the Dynamic Window Approach works:

### Here's a step-by-step explanation of the Dynamic Window method:
State Representation: The robot's state is typically represented by its position (x, y), orientation (θ), and velocity (linear velocity v and angular velocity ω).

1. Dynamic Windows: The term "dynamic window" refers to the set of feasible velocities that the robot can achieve. The dynamic window is determined by the robot's maximum and minimum linear and angular velocities. It defines the range of velocities the robot can use to move within the given environment.

2. Collision Checking: The algorithm considers different velocity commands within the dynamic window and predicts the potential future positions of the robot for each command. For each predicted position, collision checking is performed to assess whether the robot will collide with an obstacle.

3. Scoring Function: To select the best velocity command, a scoring function is used. The scoring function takes into account various factors, such as the proximity to the goal, the distance to obstacles, and the closeness to the map boundaries. The purpose of the scoring function is to favor velocity commands that move the robot closer to the goal while avoiding collisions with obstacles.

4. Selecting the Best Command: The command with the highest score from the scoring function is chosen as the best velocity command for the robot to execute. This command is then sent to the robot's motion control system to drive the robot.

5. Iterative Planning: The dynamic window approach is typically used in a continuous loop. As the robot moves and updates its environment perception, it continually reevaluates the dynamic window, collision checks, and scoring function to adjust its velocity commands in real-time.

# Pros and cons of the dynamic window Method:

The Dynamic Window Approach is advantageous as it can efficiently handle dynamic environments, as the robot can quickly adjust its velocity commands based on the current state of the environment. Additionally, it is computationally less intensive compared to some other path planning methods.
However, it is essential to note that the specific implementation details of the DWA may vary depending on the application and the specific requirements of the robotic system.
