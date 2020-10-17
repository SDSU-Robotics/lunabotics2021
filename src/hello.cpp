#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "ctre/Phoenix.h"
#include "ctre/phoenix/platform/Platform.h"
#include "ctre/phoenix/platform/can/PlatformCAN.h"
#include "ctre/phoenix/unmanaged/Unmanaged.h"

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

      std::function<void(const geometry_msgs::msg::Twist::SharedPtr msg)> fcn = std::bind(Hello::topic_callback, std::placeholders::_1, "topic");

      //subscriber = this->create_subscription<geometry_msgs::msg::Twist>(
        //"hello_topic", 10, std::bind(&Hello::topic_callback, this, _1));
      
      RCLCPP_INFO(this->get_logger(), "Publishing Hello");

    }

    private:

      TalonSRX talon = 1;

    void topic_callback(const geometry_msgs::msg::Twist msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard");
    }


    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscriber;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

	ctre::phoenix::platform::can::SetCANInterface("can0");

  while(rclcpp::ok())
  {
    rclcpp::spin(std::make_shared<Hello>());
  }
  
  rclcpp::shutdown();

  return 0;
}
