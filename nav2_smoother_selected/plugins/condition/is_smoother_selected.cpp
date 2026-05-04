#include <string>
#include <vector>
#include "nav2_smoother_selected/plugins/condition/is_smoother_selected.hpp"

namespace nav2_behavior_tree
{

IsSmootherSelectedCondition::IsSmootherSelectedCondition(
  const std::string & condition_name,
  const BT::NodeConfiguration & conf)
: BT::ConditionNode(condition_name, conf)
{
  node_ = config().blackboard->get<rclcpp::Node::SharedPtr>("node");
}

BT::NodeStatus IsSmootherSelectedCondition::tick()
{
  config().blackboard->get<std::string>("selected_smoother", selected_smoother_);
  RCLCPP_INFO(node_->get_logger(), "Selected smoother ? %s", selected_smoother_.c_str());
  if (selected_smoother_ != "disabled") {
    RCLCPP_INFO(node_->get_logger(), "Selected smoother was %s", selected_smoother_.c_str());
    return BT::NodeStatus::SUCCESS;
  }
  RCLCPP_INFO(node_->get_logger(), "Selected smoother was disabled, it was:  %s", selected_smoother_.c_str());
  return BT::NodeStatus::FAILURE;
}

}  // namespace nav2_behavior_tree

#include "behaviortree_cpp_v3/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<nav2_behavior_tree::IsSmootherSelectedCondition>("IsSmootherSelected");
}

