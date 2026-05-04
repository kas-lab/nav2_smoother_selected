#ifndef NAV2_BEHAVIOR_TREE__PLUGINS__CONDITION__IS_SMOOTHER_SELECTED_CONDITION_HPP_
#define NAV2_BEHAVIOR_TREE__PLUGINS__CONDITION__IS_SMOOTHER_SELECTED_CONDITION_HPP_

#include <string>

#include "behaviortree_cpp_v3/condition_node.h"
#include <rclcpp/rclcpp.hpp>

namespace nav2_behavior_tree
{

/**
 * @brief A BT::ConditionNode that returns SUCCESS when goal is
 * updated on the blackboard and FAILURE otherwise
 */
class IsSmootherSelectedCondition : public BT::ConditionNode
{
public:
  /**
   * @brief A constructor for nav2_behavior_tree::IsSmootherSelected
   * @param condition_name Name for the XML tag for this node
   * @param conf BT node configuration
   */
  IsSmootherSelectedCondition(
    const std::string & condition_name,
    const BT::NodeConfiguration & conf);

  IsSmootherSelectedCondition() = delete;

  /**
   * @brief The main override required by a BT action
   * @return BT::NodeStatus Status of tick execution
   */
  BT::NodeStatus tick() override;

  /**
   * @brief Creates list of BT ports
   * @return BT::PortsList Containing node-specific ports
   */
  static BT::PortsList providedPorts()
  {
    return {};
  }

private:
  std::string selected_smoother_;
  rclcpp::Node::SharedPtr node_;
};

}  // namespace nav2_behavior_tree

#endif  // NAV2_BEHAVIOR_TREE__PLUGINS__CONDITION__IS_SMOOTHER_SELECTED_CONDITION_HPP_
