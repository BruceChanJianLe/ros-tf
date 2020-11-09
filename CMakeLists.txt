cmake_minimum_required(VERSION 3.0.2)
project(ros-tf)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  tf2_ros
)

catkin_package(
 INCLUDE_DIRS include
#  LIBRARIES ros-tf
#  CATKIN_DEPENDS geometry_msgs roscpp rospy std_msgs tf2_ros
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(broadcaster_node
  src/broadcaster_node.cpp
  src/broadcaster.cpp
)

target_link_libraries(broadcaster_node ${catkin_LIBRARIES})

add_executable(broadcaster_node_debug
  src/broadcaster_node.cpp
  src/broadcaster.cpp
)

target_link_libraries(broadcaster_node_debug ${catkin_LIBRARIES})