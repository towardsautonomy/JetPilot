# JetPilot: Autonomous Driving Software Stack based on JetRacer Platform
  
![](media/JetRacer.jpg)

## Get Started  

### Build JetPilot  

```
git clone https://github.com/towardsautonomy/JetPilot.git --recursive
cd JetPilot/ros2
source ~/ros2_dashing/install/setup.bash
colcon build
```

### Launch JetPilot  

```
cd JetPilot/ros2
source install/setup.bash
ros2 launch jet_drive jet_pilot.launch.py
```

### Launch JetPilot on startup

```
chmod +x scripts/jetpilot_startup.sh
sudo cp scripts/jetpilot_startup.service /etc/systemd/system/ 
sudo systemctl enable jetpilot_startup
sudo systemctl start jetpilot_startup
```
## Modules and Individual Packages

1. Camera: `IMX219-160 Camera`
    - More Details: https://www.waveshare.com/wiki/IMX219-160_Camera  
    - Running this node: ```ros2 launch front_cam front_cam_node.launch.py```  
    - This node publishes the msg `sensor_msgs/Image` on topic `/front_cam/rgb`  
    
1. RPLIDAR A2  
    - ros2 package being used for this device is a modified version of [this](https://github.com/youngday/rplidar_ros2)
    - This device needs access to `/dev/ttyUSB0`. This can be done by adding the user to the group `dialout`.  
      ```sudo adduser jetson dialout``` followed by a reboot.
    - Running this node: ```ros2 run rplidar_ros rplidarNode```.
    - This node publishes the msg `sensor_msgs/LidarScan` on topic `/scan`

1. Gamepad
    - This is used for sending commands to the JetRacer.  
    - Controls:  
      ```
      Select      : Toggles auto-driving on/off
      Start       : Toggles manual-driving on/off
      Left Stick  : Up/Down for +ve/-ve Acceleration
                    Left/Right for Left/Right Steering
      Right Stick : Left/Right for Left/Right Steering
      ```  
    - Running this node: ```ros2 launch joystick joystick_node.launch.py``` 

1. IMU - Adafruit BNO055
    - This module uses the [Adafruit_Python_Extended_Bus](https://github.com/adafruit/Adafruit_Python_Extended_Bus) library which needs to be installed separately.  
    ![](media/BNO055.jpg)
    - Connected to Jetson Nano I2C ports:
        - BNO055 vin -> nano 3.3V
        - BNO055 GND -> nano GND
        - BNO055 SDA -> nano SDA2
        - BNO055 SCL -> nano SDL2
    - Running this node: ```ros2 launch imu_bno055 imu_bno055_node.launch.py``` 
    
1. Jet Drive Moderator  
    - This is responsible for moderating the `steering` and `throttle` commands sent to the JetRacer.  
    - Running this node: ```ros2 launch jet_drive_moderator jet_drive_moderator_node.launch.py``` 
    
1. Jet Drive
    - This module is responsible for applying `steering` and `throttle` to the JetRacer.  
    - Running this node: ```ros2 launch jet_drive jet_drive_node.launch.py``` 
    - For other sensor frames to base link transforms, run: ```ros2 launch jet_drive frame_transforms.launch.py``` 
    - Launch the complete stack: ```ros2 launch jet_drive jet_pilot.launch.py``` 
    - Sometimes `rviz2` complains about no `tf2` data if monitoring from a remote machine. Provide transforms locally by running:  
        ```
        ros2 run tf2_ros static_transform_publisher 0.0 0.0 0.1 1.57 0.0 0.0, base_link imu_link &
        ros2 run tf2_ros static_transform_publisher 0.0 0.0 0.15 1.57 3.14 3.14, base_link laser_link &
        ros2 run tf2_ros static_transform_publisher 0.0 0.0 0.0 0.0 0.0 0.0, laser_frame laser_link &
        ros2 run tf2_ros static_transform_publisher 0.0 0.2 0.12 0.0 0.0 -1.8318, base_link camera_link &
        ```

## Teleoperation without ROS2 dependency

For teleoperation using *Gamepad*, run the script ```scripts/teleoperation.py```. This can also be setup to run at startup as:  

```
sudo cp scripts/teleoperation_startup.service /etc/systemd/system/ 
sudo systemctl enable teleoperation_startup
sudo systemctl start teleoperation_startup
```
