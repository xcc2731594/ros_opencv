#include<ros/ros.h>
#include<cv_bridge/cv_bridge.h>
#include<sensor_msgs/image_encodings.h>
#include<image_transport/image_transport.h>

#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<stdio.h>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "image_publisher");
    ros::NodeHandle n; 
    // ros::Time time = ros::Time::now();
    ros::Rate loop_rate(30);

     // 定义节点句柄   
    image_transport::ImageTransport it(n);
    image_transport::Publisher pub = it.advertise("video_image", 5);
    sensor_msgs::ImagePtr msg;
        
    // opencv准备读取视频
    cv::VideoCapture cap;
    cap.open(argv[1]);  

    if( !cap.isOpened() )
    {
        ROS_INFO("Read Video failed!\n");
        return 0;
    }
    
    while(n.ok())
    {
        if(cap.grab())
        {
            cv::Mat frame;
            cap.retrieve(frame);
            cv_bridge::CvImage out_msg;
            out_msg.header.stamp = ros::Time::now();
            out_msg.encoding = sensor_msgs::image_encodings::BGR8;
            out_msg.image = frame;
            pub.publish(out_msg.toImageMsg());
        }
        loop_rate.sleep();
    }
    
    cap.release();
    
    return 0;
}
