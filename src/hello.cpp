//#include "std_msgs/msg/string.hpp"
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

class Hello : public rclcpp::Node
{
  public:
    Hello() : Node("pub_hello")
    {

      //RCLCPP_INFO(this->get_logger(), "Publishing Hello");

    }

    TalonSRX talon = 1;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::Rate loopRate(10);

	ctre::phoenix::platform::can::SetCANInterface("can0");
  //ctre::phoenix::platform::can::StartAll();

  while(rclcpp::ok())
  {
    rclcpp::spin_some(std::make_shared<Hello>());
    loopRate.sleep();
  }
  
  rclcpp::shutdown();

  return 0;
}
