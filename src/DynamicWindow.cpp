#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <memory>


using std::placeholders::_1;

class dynamicWindows : public rclcpp::Node
{
  public:
    dynamicWindows()
    : Node("dynamic_windows_node")
    {
      subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "odom", 10, std::bind(&dynamicWindows::topic_callback, this, _1));
    }

  private:
    void topic_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
    
        auto x = msg->pose.pose.position.x;
        RCLCPP_INFO(this->get_logger(), "I heard: %f",x);
    }
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<dynamicWindows>());
  rclcpp::shutdown();
  return 0;
}