# ROS tf

This repository is a simple demonstration of tf(2) usage in ROS 1.

## Content

- [Publish Statis Transform](#Publish-Statis-Transform)

## Publish Statis Transform

**TF2 (Recommended)**  
```xml
<launch>
    <node pkg="tf2_ros" type="static_transform_publisher" name="parent_frame_to_child_frame" args="1 0 0 0 0 0 parent_frame child_frame" />
</launch>
```
Explanation: `static_transform_publisher x y z yaw pitch roll parent_frame child_frame`

**TF1**  
```xml
<launch>
   <node pkg="tf" type="static_transform_publisher" name="parent_frame_to_child_frame" args="1 0 0 0 0 0 parent_frame child_frame 100" />
</launch>
```
Explanation: `static_transform_publisher x y z yaw pitch roll parent_frame child_frame publish_hz`

## TF2 Broadcaster

