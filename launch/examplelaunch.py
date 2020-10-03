from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='lunabotics2021',
            namespace='subscriber',
            executable='listen',
            name='launchexample'
        ),
        Node(
            package='lunabotics2021',
            namespace='publisher',
            executable='hello',
            name='launchexample'
        )
    ])