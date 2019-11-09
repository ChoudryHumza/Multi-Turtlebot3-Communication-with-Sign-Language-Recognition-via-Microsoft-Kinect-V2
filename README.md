# Multi-Turtlebot3-Communication-with-Sign-Language-Recognition-via-Microsoft-Kinect-V2

Table of Contents




Description

The Microsoft Kinect V2 camera interprets a sign language gesture that is done in ASL (American Sign Language). This program is implemented in visual studio on a computer running windows. Once this gesture is picked up, it sends a command based on the gesture to another computer running Linux Ubuntu. This is where the ROS master is running. Once the command or string is recieved by the ROS master, it communicates this to the turtlebot3. The turtlebot3 then excecutes this command. 
For example, in order to tell the robot to go forward, you can do a sign or gesture (in ASL) in front of the Microsoft Kinect. This would be interpreted by the visual studio program, which would then send a "go forward" command to the ROS program running on another machine. The ROS program would then send this command to the turtlebot3, which would then excecute this command and start moving forward at a set speed, until a command to stop it is sent. 

There are two parts to this project. The first part is sign language recognition using Microsoft Kinect V2. This part is done by my research partner Benjamin Jenney. Instructions on how to implement this are on Benjamins github page (link below). The second part is communicating with ROS running on a separate machine from the visual studio program running on a windows computer. It also involves creating a ROS package to communicate with the turtlebot. This part is done by me and is illustrated in depth here. 


Link to sign language recognition via Microsoft Kinect V2 (Benjamin Jenney Project) 
https://github.com/BenjaminJenney/ASL_Navigation_of_NAO_Robot


Takeaway

Even if you are not implementing this entire project, there are certain things you can takeaway to implement into your own project.  Below is a list of things you can learn to do from this project.
1. How to communicate between a computer running windows and another running ubuntu. In order to accomplish communication with ROS.  
2. Use ROS via matlab on windows. Independent of a ROS distribution and ubuntu. Ros master running on matlab.   
3. Understand how to implement multiple turtlebot3's on a single ros master, on a computer running Ubuntu. 

Helpful Tools

1. Beginner ROS tutorials. To get an understanding of ROS concepts with turtlebot3.  
https://drive.google.com/open?id=17emlH6L7_blEymenJEvQoIVju6Mz8Z43
2. This is my powerpoint presentation for this project (Including informal video showing project execution).
https://drive.google.com/open?id=1b6aFNyqh5kpTDeSjU4HXHJXOQLPLrXJQ
3. Very helpful books for anyone just getting started with ROS. I highly recomend these books, having read it all. 
-Lentin Joseph - Robot Operating System (ROS) for Absolute Beginners Robotics Programming Made Easy-Apress (2018)
-Morgan Quigley, Brian Gerkey, William D. Smart - Programming Robots with ROS_ A Practical Introduction to the Robot Operating System-O'Reilly Media (2015)


Requirments 

Computer running any verision of Windows.
MATLAB with Robotic System Toolbox (Addon) on windows computer. MATLAB is free for only 30 days. At the time of writing this, the application did allow me to renew the trial (additional 30 days). If you are a college student, you may be able to download it for free (indefinetly).
Visual Studio (Any verision that supports referencing another application (e.g. Matlab)). 
Any verision of the Robotic Operating System (ROS) on a computer running Ubuntu.


Software Verision Used
 
 These are the verisions of the software that was used during implementation and testing of this project. 
 ROS Kinetic Kame 
 Ubuntu 16.04 LTS
 Windows 10
 MATLAB R2019b 
 Visual Studio 2019
 
 
Downloading Software

ROS 
 Follow the instructions provided in the link below to download ROS Kinetic Kame. 
 http://wiki.ros.org/kinetic/Installation/Ubuntu
 You can also use another distribution (version) of ROS as well. Link below. Click on the desired distribution and follow the the installtion instructions.  
 http://wiki.ros.org/Distributions
 
 Visual Studio 2019 
 https://visualstudio.microsoft.com/vs/
 
 MATLAB R2019b + Robotic System Toolbox. Make sure you check off to include the addon "Robotic System Toolbox" with MATLAB download.  
 https://www.mathworks.com/products/robotics.html
 
 Ubuntu 16.04 LTS
 http://releases.ubuntu.com/16.04/
 
 Turtlebot3 dependent packages to control the robot. 
 6.2.2.3 Install Dependent Packages ONLY. Do not continue on to 6.2.2.4 USB Settings. Unless you know what your doing. I will explain everything in detail. As in, how to establish communication with turtlebot and your computer. 
 If you have not built your turtlebot and need to do a full setup (hardware and software). Please follow the full instruction set provided in the link below (From 1 to 6) to get started.
 http://emanual.robotis.com/docs/en/platform/turtlebot3/joule_setup/






