cmake_minimum_required(VERSION 3.0.2)
project(robot_vision)

 
find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)
find_package(OpenCV REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES robot_vision
#  CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs std_msgs
#  DEPENDS system_lib
)

 

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories( ${catkin_INCLUDE_DIRS})
include_directories( ${OpenCV_INCLUDE_DIRS})

add_executable(imagepub src/imagepub.cpp)
target_link_libraries(imagepub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

