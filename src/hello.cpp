#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "ctre/Phoenix.h"
#include "ctre/phoenix/platform/Platform.h"
#include "ctre/phoenix/platform/can/PlatformCAN.h"
#include "ctre/phoenix/unmanaged/Unmanaged.h"
#include <string>
#include "rclcpp/node.hpp"
#include "ctre/phoenix/MotorControl/ControlMode.h"

using namespace std;
using namespace ctre::phoenix;
using namespace ctre::phoenix::platform;
using namespace ctre::phoenix::motorcontrol;
using namespace ctre::phoenix::motorcontrol::can;

using std::placeholders::_1;

class Hello : public rclcpp::Node
{
  public:
    Hello() : Node("pub_hello")
    {
      
      subscriber = this->create_subscription<geometry_msgs::msg::Twist>(
        "topic", 10, std::bind(&Hello::topic_callback, this, _1));
      
      RCLCPP_INFO(this->get_logger(), "Node Running");
      
    }

    private:

    void topic_callback(const geometry_msgs::msg::Twist::SharedPtr) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard");
    }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscriber;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Hello>();

  TalonSRX talon = 2;

	ctre::phoenix::platform::can::SetCANInterface("can0");

  talon.Set(ControlMode::PercentOutput, 1);
  
  while(true)
  {
  
    ctre::phoenix::unmanaged::Unmanaged::FeedEnable(100);
  }

  while(rclcpp::ok())
  {

    rclcpp::spin(node);
  }
  
  rclcpp::shutdown();

  return 0;
}
