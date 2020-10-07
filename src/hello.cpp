#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

class Hello : public rclcpp::Node
{
  public:
    Hello() : Node("pub_hello")
    {
      publisher = this->create_publisher<std_msgs::msg::String>("hello_topic",10);

      auto message = std_msgs::msg::String();
      message.data = "Hello There";

      RCLCPP_INFO(this->get_logger(), "Publishing Hello");

      publisher->publish(message);
    }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Hello>());
  rclcpp::shutdown();

  return 0;
}
