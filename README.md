# Multi-Turtlebot3-Communication-with-Sign-Language-Recognition-via-Microsoft-Kinect-V2

Table of Contents

Description
Takeaway
Helpful Tools
Requirments
Software Versions Used
Downloading Software
Overview
PART ONE - VISUAL STUDIO & ROS
PART TWO - ROS 
PART THREE RUNNING THE PROGRAMS


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
2. This is my powerpoint presentation for this project plus an informal video showing project execution.
https://drive.google.com/open?id=1b6aFNyqh5kpTDeSjU4HXHJXOQLPLrXJQ
https://youtu.be/t0xgeniSS-4
3. Very helpful books for anyone just getting started with ROS. I highly recomend these books, having read it all. 
-Lentin Joseph - Robot Operating System (ROS) for Absolute Beginners Robotics Programming Made Easy-Apress (2018)
-Morgan Quigley, Brian Gerkey, William D. Smart - Programming Robots with ROS_ A Practical Introduction to the Robot Operating System-O'Reilly Media (2015)


Requirments 

Computer running any verision of Windows.
MATLAB with Robotic System Toolbox (Addon) on windows computer. MATLAB is free for only 30 days. At the time of writing this, the application did allow me to renew the trial (additional 30 days). If you are a college student, you may be able to download it for free (indefinetly).
Visual Studio (Any verision that supports referencing another application (e.g. Matlab)). 
Any verision of the Robotic Operating System (ROS) on a computer running Ubuntu.


Software Verisions Used
 
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


Overview:

Below are steps on how to establish a communication betweem windows visual studio and ubuntu ros. 
This requires creating a publisher node (sends data) in visual studio and a subscriber node (recieves data) on the Ubuntu machine running ROS. 
All concepts will be broken down and throughly explained below. 


PART ONE-Visual Studio & MATLAB:

1) Open up visual studio and MATLAB. Start a new C# console project in visual studio. If you cannot find the C# console option, use the link below for instructions how too "Install more tools and features" using the link below. 
https://docs.microsoft.com/en-us/visualstudio/get-started/csharp/tutorial-console?view=vs-2019

2) From your visual studio program, add a reference from your project to the MATLAB COM object. 
Open your project. From the Project menu, select Add Reference. Select the COM tab in the Add Reference dialog box (left hand side). Select the MATLAB application.

This allows you to write MATLAB commands in your C# visual studio program and excecute them from there instead of running them in the MATLAB application. This helps communicate your visual studio program with the MATLAB application. This integration works flawlessly with your C# program. Below is a quote from the MATLAB regarding this. 

"Automation is a COM protocol that allows one application (the controller or client) to control objects exported by another application (the server). MATLAB supports COM Automation server capabilities on Microsoft® Windows® operating systems. Any Windows program that can be configured as an Automation controller can control MATLAB. Some examples are Microsoft Excel® and Microsoft Access™, and many Microsoft Visual Basic® and Microsoft Visual C++® programs." 
Link: https://www.mathworks.com/help/matlab/call-matlab-com-automation-server.html?s_tid=CRUX_lftnav


3)Download the matlabWithRos.cs file from this project or copy and paste the code into your own visual studio program. 
Following is a breakdown of the code. 

Line 14: 
MLApp.MLApp matlab = new MLApp.MLApp();

This references the MATLAB Type Library for C#. It creates a MATLAB instance. You will use this instance to excecute MATLAB commands in your program. 

Line 17 & 18:
string state = matlab.Execute("enableservice('AutomationServer', true)");
Console.WriteLine("AutoServer State: " +state);

We need to make sure that the MATLAB automation server is on. Otherwise, we will not be able to excecute MATLAB commands in visual studio. As explained earlier, this is used to communicate between your visual studio and the MATLAB application. 

excecute: Here we use the matlab instance to access a fuction called 'excecute'. This is used to executes the follwing MATLAB command. 
"enableservice('AutomationServer',true)" is used to Enable the Automation server in the current MATLAB session. 
This return value is either a zero or one and is printed out in next line (line 18). 

"If enable is false, enableservice disables the MATLAB Automation server. state indicates the previous state of the Automation server. If state = 1, MATLAB was an Automation server. If state = 0, MATLAB was not an Automation server....The previous state can be the same as the current state."
https://www.mathworks.com/help/matlab/ref/enableservice.html

Line 16:
state = enableservice('AutomationServer') 

The code is commented out, but can be used to find the current state of the automation server. 

Line 20:
string ex0 = matlab.Execute("rosinit('192.168.1.161');"); //CHANGE IP!!!!!, CHECK THE IP OF LISTENER 

rosinit(hostname) tries to connect to a ROS master at the host name or IP address. This syntax uses 11311 as the default port number. ROS uses this same port number by default. There is no need to change it or specify explictly. You can specify a different port number by changing the syntax to rosinit(hostname,port). You can also specify the URI instead, 
rosinit("http://192.128.4.5:12847)"

We will discuss where you can find the IP address, hostname, and portnumber on your Ubuntu machine later on. For now leave this as is. 
Link: https://www.mathworks.com/help/ros/ref/rosinit.html?searchHighlight=rosinit&s_tid=doc_srchtitle

Line 21: 
string ex1 = matlab.Execute("chatpub = rospublisher('/turtle', 'std_msgs/String');");

This creates a rospublisher object to send messages via a ROS network. The format is as follows, 
pub = rospublisher(topicname,msgtype). This is called a 'node' in ros terminology. Specifically a publisher node. All this node does is it send messages or data to other nodes who want or need this data. The node that is recieving this data is called a subscriber node. 

The topicname here is what you will be using to get the data sent from your visual studio program to the ROS program on Ubuntu. The topic name can be anything you like. The backslash before the name does not necessarily matter. If it is excluded, it will be implictly specified for you. Here the topic name is turtle. 
Following this is the kind of data we will be sending. Here the data is specified as String. Meaning that we will be sending string values to the ROS program. 
chatpub is the name of the publisher node that we have created using the publisher object. You can name this anything you want. We use this variable 'chatpub' to publish data or send messages to the topic called '/turtle'. The type of data or messages we will be sending is of type 'String'. 

Note that in order to create a topic and send data we must first create a publisher node. 

Line 22:
string ex2 = matlab.Execute("msg = rosmessage(chatpub);");

Here we again use the matlab instance in order to run a MATLAB command. We excecute the command to create a message. 
Here we are creating a message object. Prevously, we have created a matlab object 'MLApp' and a publisher object. Now we are creating a message object to store the data that we want to send. There are many different types of data that we can send. But as noted prevously, we want to send data of type 'String'. Therefore, we must specify that we want the message object to store data of type string. We can do this by putting in the name of the publisher node we created earlier 'chatpub' or we can explictly state the message type. To explicatly state the message type, it would look like this:

msg = rosmessage(std_msgs/String);

The name of the message object here is called 'msg'. You can name your object as you see fit. We will be using this object that we named 'msg' to store the data that we want to send.

Other data types that are supported by MATLAB can be stated here. Use the following command to view a list of all possible message types that you can create:
msglist = rosmsg("list") returns a cell array containing all available message types that you can use in MATLAB.
Link: https://www.mathworks.com/help/ros/ref/rosmsg.html#d117e10913


Line 27:
string wh111 = matlab.Execute("msg.Data = 'forward';");

Here we use the message object 'msg' that we created to access a function called 'Data'. We use this function to store the data that we want. The data must be of the message object type, as stated eariler. Our message object here can only store String data. Therefore, we specify what string we want it to store inside single quotation marks ' '. Here we want to store the word 'forward' inside the message object called 'msg. Once this line of code runs, we will have successful stored the data. 
Now all that is left is to send the data.


Line 28:
string wht5 = matlab.Execute("send(chatpub,msg);");

Here we use the send function to send the data we stored in the message object 'msg' to the topic that we specified '/turtle'. This is done by using the message object and the publisher node that we created called 'chatpub'. All this is doing is sending the data 'forward' to the topic called '/turtle'. Now any subscriber node that is subscribed to this topic in the ROS network will recieve the string called 'forward'. We will discuss how to create a subscriber node and how it functions shortly. 

https://www.mathworks.com/help/ros/ref/send.html


Summary:
We created a MATLAB instance to excecute matlab commands. Then we created a publisher node to send SPECIFIC TYPE of data to a topic. Next, we created a message object to store the data of the same type. Lastly, we send the data stored in the message object to the topic of the publisher object. 

Next we will discuss how to create a subscriber node in ROS on the Ubuntu computer. 


PART TWO-ROS:

1) Start the computer that is running the Ubuntu operating system. Make sure that you have ROS installed already. The download link for ROS is stated above under requirments. 

2) First we must create a catkin workspace in ROS. Below is a link you can use to help as well:
http://wiki.ros.org/catkin/Tutorials/create_a_workspace

  1) At a new terminal, enter the following command. 
  $ mkdir -p ~/catkin_ws/src

  This creates a folder called catkin_ws, inside of which is another folder called src. The ROS workspace is also called the     catkin workspace. Do not change the name of the 'src' folder. 
  
  2) After entering the command, switch to the src folder by using the cd command.
  $ cd catkin_ws/src
  This 'cd' command bring you into the src folder, virtually. 
  
  3)The following command initializes a new ROS workspace. If you are not initializing a workspace, you cannot create and       build the packages properly.
  $ catkin_init_workspace 
  
  There is a CMakeLists.txt inside the src folder.
  After initializing the catkin workspace, you can build the workspace. You can able it to build the workspace without any       packages. To build the workspace, switch from the catkin_ws/src folder to the catkin_ws folder.
  $ ~/catkin_ws$ cd catkin_ws
  
  4) The command to build the catkin workspace is catkin_make.
  $ ~/catkin_ws$ catkin_make 
  
  5) After this command, you will have three folders inside your catkin workspace. These folder are build, devel, and src. 
  The src folder is where our packages are kept. If you want to create or build a package, you have to copy those packages to   the src folder. The src folder inside the catkin workspace folder is the place where you can create, or clone, new packages   from repositories. ROS packages only build and create an executable when it is in the src folder. When we execute the         catkin_make command from the workspace folder, it checks inside the src folder and build each packages. We are not concered   about the devel and build folder for right now. 
  
2) Because everytime we open up a new terminal we do not have access to our catkin workspace. This just means that we do not have access to our ROS packages. This means we will not be able run our program, unless we source it.

  1) Open the .bashrc file in the home folder and add the following line at the end of the file.
  Open a new terminal and type 
  $ gedit .bashrc
  Add the following line at the end of .bashrc 
  source ~/catkin_ws/devel/setup.bash
  
3) Next, run the following command to install the executable.
$ catkin_make install

If you do this, you see the install folder in the workspace. This folder keeps the install target files. When we run the executable, it executes from the install folder.

4) Now we need to create a package. ROS software is organized into packages. A package stores all the files used to run our program.
Below is a link to better understand packages:
http://wiki.ros.org/Packages

  1) The following is the command format for creating a package. 
  $ catkin_create_pkg ros_package_name package_dependencies
  
  First you give your package a name. Next, you state all the package dependencies. This tells ROS that this package or         program needs the following files to run the program. You can think of this as the preprocessor statement #include library.
  
  $ catkin_create_pkg turtlebot3_kinect roscpp rospy std_msgs
  This tells ROS that we want to create a package called 'turtlebot3_kinect' and the libraries or packages that we need are roscpp, rospy, and std_msgs. 'roscpp' and 'rospy' are ROS client libraries, roscpp is a C++ library for ROS and rospy is a python library for python. ROS has strong support for these two libraries. There are other languages that ROS supports, some experimental. It is best to stick to these two, since much support has been developed for these two languages. 
  
 Inside the package is the src folder, package.xml, CMakeLists.txt, and the include folder.  
 
 CMakeLists.txt: This file has all the commands to build the ROS source code inside the package and create the executable.
 package.xml: This is basically an XML file. It mainly contains the package dependencies, information, and so forth.
 src: The source code of ROS packages are kept in this folder. Normally, C++ files are kept in the src folder.
 If you want to keep Python scripts, you can create another folder called scripts inside the package folder.
 include: This folder contains the package header files. It can be automatically generated, or third-party library files go in  it.
  
5) Now that we have created a catkin workspace and package. We can begin to create a subscriber node. You can choose to do this in python or c++. I will be using c++. Below is a link to do it in python.
http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28python%29

  1) To create a ROS C++ node, we have to include the following header files. 
  #include "ros/ros.h"
  #include "std_msgs/String.h"

  The ros.h has all the headers required to implement ROS functionalities. We can’t create a ROS node without including this     header file. If we want to include a string message in our code, we can must include 'std_msgs/String.h'.

  2) I have alrady created this node. The folder is called "turtlebot3_kinect". You can download by clicking on this folder,     click on src, and then the file listener.cpp. I will break down the code in this file. 
  
  First you must state the following: 
  
  int main(int argc, char **argv)
  {  }
  
  Before starting any ROS node, the first function called initializes the node. This is a must in any ROS node.
  
  3) After the int main() function, we have to include ros::init(),
  ros::init(argc, argv, "listener"); 
  
  This initializes the ROS node. We can pass the argc, argv command line arguments to the init() function and the name of the     node. The name of the node here is called 'listener'. 
  
  4) After initializing the node, we have to create a NodeHandle instance that starts the ROS node and other operations, like   publishing/subscribing a topic. We are using the ros::NodeHandle instance to create those operations.
  ros::NodeHandle nh;
  
  The rest of the operations in the node use the nh instance. 
  
  5) Next we create a subscriber node.
  ros::Subscriber subscriber_obj = nh.subscribe("/turtle", 1000, sendToTurtlebot);
  
  This uses the node handle instance called 'nh' to call the function subscribe. This function creates the subscriber node for you. To do so, we must state the name of the topic we want to subscribe to. That way when the publisher node publishes or sends data to the topic called '/turtle', we will be able to recieve this data here, using this node. We subscribe to the '/turtle' topic because earlier in our visual studio program we created a publisher node that sends data to a topic called '/turtle'. 
 The last argument 'sendToTurtlebot' is the callback function. The callback function is a user defined function that executes   once a ROS message is received over the topic. Inside the callback, we can manipulate the ROS message—print it or make a       decision based on the message data. So every time data is recieved here the program will automatically call the function 'sendToTurtlebot'. Inside this function we can make decide what we want to happen every time a data or message is recieved. 
 
 The name of the subscriber node here is called 'subscriber_obj'. You can name this whatever you want. 
 
   6) At the very bottom of the program is a command
   ros::spin();
  
  This executes the subscribe callbacks and helps the node remain in a wait state, so it won’t quit until you press     Ctrl+C. This means that when we run the listener.cpp file, the subscriber node will be in a wait state. It will not quit until you hit Ctrl+C. And everything it recieves data from the publisher it, it will excecute the code inside the callback function. 
   
   7)Next, we write the callback function.
   void sendToTurtlebot(const std_msgs::String::ConstPtr& msg) { }
   
   Here our functions returns nothing, as noted by the return type 'void'. The name of the function is 'sendToTurtlebot' and  the arguments for this function is a string. The reason why the parameter takes a string value is because the publisher node in our visual studio program is sending a string. The data being sent to the topic '/turtle' is of type string. So everytime data is recieved, this function is called and it automatically passes the string message to the function parameter. 
   
   8) Inside the callback function all we are doing is printing the string value that has been sent by the publisher node. From the visual studio program we sent the string message 'forward'. Therefore, this is what will get printed onto the terminal once we have recived it. 
   ROS_INFO("I heard: [%s]", msg->data.c_str());
   
   This is the function that accomplishes this. 'msg' is the variable in the parameter that is storing the recieved message 'forward'. We use this variable and get the data to print onto the concole. 
   
   9) In order to run this file 'listener.cpp' we must edit the CMakeList.txt file. We need to add four lines of code to          CMakeLists.txt. This file can be found here in the folder 'turtlebot3_kinect'.
  
  Lines 126-129:
   add_executable(listener src/listener.cpp)
   target_link_libraries(listener
   ${catkin_LIBRARIES}
)

  This creates the executable from the source code. If this processes is successful, we get executable node. Meaning we are ready to excecute this file. 
  
  10) To build the c++ node, open a new terminal and switch to the catkin_ws folder. 
  $ cd ~/catkin_ws
  
  Then execute the catkin_make command to build the node. If everything is correct, you get a message saying that the build was successful
  $ catkin_make
  
  11) Next we run the program. 
    
  1) Open a new terminal and start by running the command roscore. This starts the ROS master. 
  $ roscore
  
  2) The following code excecutes the 'listener.cpp' file. Do this in a NEW terminal. 
  $ rosrun turtlebot3_kinect listener
  
  After rosrun is the name of our package and then the name of the file. This commands starts the listener node. 
  This will be print anything right now becuase we have not started our visual studio program that has the publisher node.
  
  
PART THREE RUNNING THE PROGRAMS:

Now we will run the programs. 

  1) Before we do this we must find the IP address of the Ubuntu machine. To do this, open a new terminal and run the command 
  ifconfig 
  
  2) Once you have your IP address, go into your visual studio program and change the IP address (Line 20). 
  
  3) Make sure that both computers are connected to the same wifi network. 
  
  4) Now we are ready to run the progam. If you have not done so already, run the 'listener' node (Step 11 above). 
  
  5) Run your visual studio program. 
  
  6) You should have recieved a message on the ROS machine. The message is 'forward'. 
  
 7) You can get a list of topics running on ROS by using the following command on your ROS machine. Once you run this you should see that '/turtle' is one of those topics. Do this in a NEW terminal. 
  $ rostopic list
 
 8) To exit the ROS program you can hit control+c. To shut down ROS master you can do the same. 
 
 
Possible issues:

Following is a list of possible issues I predict you may run into:
1) Public wifi: Try using a hotspot or your personal wifi network.
2) Error in 'listener.cpp' file: Fix the error, save your file, and do steps 10 and 11 again.
3) Wrong IP address, hostname, and/or portnumber.



  
  
   
