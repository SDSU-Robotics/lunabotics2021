from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='lunabotics2021',
            executable='listen',
            name='launchexample'
        ),
        Node(
            package='lunabotics2021',
            executable='hello',
            name='launchexample'
        )
    ])