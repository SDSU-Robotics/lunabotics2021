#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

using std::placeholders::_1;

class listen : public rclcpp::Node
{
    public:
        listen() : Node("sub_hello")
        {
            subscriber = this->create_subscription<std_msgs::msg::String>(
            "hello_topic", 10, std::bind(&listen::topic_callback, this, _1));
        }

    private:

      void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
      {
          RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      }

      rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber;

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    
    while(rclcpp::ok)
    {
      rclcpp::spin(std::make_shared<listen>());
      rclcpp::RCLCPP_INFO(listen->get_logger(), "Running");
    }

    rclcpp::shutdown();

  return 0;
}