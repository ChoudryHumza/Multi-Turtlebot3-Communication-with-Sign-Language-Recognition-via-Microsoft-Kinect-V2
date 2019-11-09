# Multi-Turtlebot3-Communication-with-Sign-Language-Recognition-via-Microsoft-Kinect-V2

Table of Contents




Description

The Microsoft Kinect V2 camera interprets a sign language gesture that is done in ASL (American Sign Language). This program is implemented in visual studio on a computer running windows. Once this gesture is picked up, it sends a command based on the gesture to another computer running Linux Ubuntu. This is where the ROS master is running. Once the command or string is recieved by the ROS master, it communicates this to the turtlebot3. The turtlebot3 then excecutes this command. 
For example, in order to tell the robot to go forward, you can do a sign or gesture (in ASL) in front of the Microsoft Kinect. This would be interpreted by the visual studio program, which would then send a "go forward" command to the ROS program running on another machine. The ROS program would then send this command to the turtlebot3, which would then excecute this command and start moving forward at a set speed, until a command to stop it is sent. 

There are two parts to this project. The first part is sign language recognition using Microsoft Kinect V2. This part is done by my research partner Benjamin Jenney. Instructions on how to do implement this are on Benjamins github page (link below). The second part is communicating with ROS running on a separate machine from the visual studio program running on a windows computer. It also involves creating a ROS package to communicate with the turtlebot. This part is done by me and is illustrated in depth here. 

Link to sign language recognition via Microsoft Kinect V2 (Benjamin Jenney Project  
https://github.com/BenjaminJenney/ASL_Navigation_of_NAO_Robot
