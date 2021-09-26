# ros_opencv
ros工程中使用opencv 调用摄像头rtsp读取图像数据并发布
1.

    mkdir -p catkin_ws/src

    cd src

    catkin_init_workspace

    cd ..

    catkin_make
    
 2.
    cd src

    catkin_create_pkg robot_vision roscpp std_msgs cv_bridge image_transport sensor_msgs

    cd ..

    catkin_make

