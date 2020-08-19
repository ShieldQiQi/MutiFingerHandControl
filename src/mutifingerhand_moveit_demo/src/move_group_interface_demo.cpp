#include <ros/ros.h>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_state/robot_state.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit_visual_tools/moveit_visual_tools.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_group_interface_demo");
  ros::NodeHandle nh;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  //-----------------------------previous setting---------------------------------

  // the planning_group'names come from your robot moveit setting
  static const std::string PLANNING_GROUP = "finger4";
  // set the move_group_interface to control and plan the selected move_group
  moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
  // We will use the PlanningSceneInterface class to add and remove collision objects in our "virtual world" scene
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

  // Raw pointers are frequently used to refer to the planning group for improved performance.
  const moveit::core::JointModelGroup* joint_model_group =
      move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

  // visualizing objects, robots, and trajectories in RViz
  namespace rvt = rviz_visual_tools;
  moveit_visual_tools::MoveItVisualTools visual_tools("world");
  visual_tools.deleteAllMarkers();

  // Remote control is an introspection tool that allows users to step through a high level script
  // via buttons and keyboard shortcuts in RViz
  visual_tools.loadRemoteControl();

  // RViz provides many types of markers, in this demo we will use text, cylinders, and spheres
  Eigen::Isometry3d text_pose = Eigen::Isometry3d::Identity();
  text_pose.translation().z() = 0.75;
  visual_tools.publishText(text_pose, "MoveGroupInterface Demo", rvt::WHITE, rvt::XLARGE);
  // Batch publishing is used to reduce the number of messages being sent to RViz for large visualizations
  visual_tools.trigger();

  // We can print the name of the reference frame for this robot.
  ROS_INFO_NAMED("move_group_interface_demo", "Planning frame: %s", move_group.getPlanningFrame().c_str());
  // We can also print the name of the end-effector link for this group.
  ROS_INFO_NAMED("move_group_interface_demo", "End effector link: %s", move_group.getEndEffectorLink().c_str());
  // We can get a list of all the groups in the robot:
  ROS_INFO_NAMED("move_group_interface_demo", "Available Planning Groups:");
  std::copy(move_group.getJointModelGroupNames().begin(), move_group.getJointModelGroupNames().end(),
            std::ostream_iterator<std::string>(std::cout, ", "));

  // to set a vaild goal for move_group "finger2", use forward kinematic first
  robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
  robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
  ROS_INFO("Model frame: %s", kinematic_model->getModelFrame().c_str());
  moveit::core::RobotStatePtr kinematic_state(new moveit::core::RobotState(kinematic_model));
  kinematic_state->setToDefaultValues();
  const moveit::core::JointModelGroup* kinematic_joint_model_group = kinematic_model->getJointModelGroup(PLANNING_GROUP);
  const std::vector<std::string>& joint_names = kinematic_joint_model_group->getVariableNames();
  // Get Joint Values
  std::vector<double> joint_values;
  kinematic_state->copyJointGroupPositions(kinematic_joint_model_group, joint_values);
  for (std::size_t i = 0; i < joint_names.size(); ++i)
  {
    ROS_INFO("Joint %s: %f", joint_names[i].c_str(), joint_values[i]);
  }
  // set the joint space goal position
  joint_values[0] = 1.0;
  joint_values[1] = -0.2;
  joint_values[2] = 1.2;
  joint_values[3] = 1.2;
  kinematic_state->setJointGroupPositions(kinematic_joint_model_group, joint_values);
  /* Check whether any joint is outside its joint limits */
  ROS_INFO_STREAM("Current state is " << (kinematic_state->satisfiesBounds() ? "valid" : "not valid"));
  /* Enforce the joint limits for this state and check again*/
  kinematic_state->enforceBounds();
  ROS_INFO_STREAM("Current state is " << (kinematic_state->satisfiesBounds() ? "valid" : "not valid"));
  // Forward Kinematics, compute forward kinematics
  //  kinematic_state->setToRandomPositions(kinematic_joint_model_group);
  const Eigen::Isometry3d& end_effector_state = kinematic_state->getGlobalLinkTransform("L44");
  /* Print end-effector pose. Remember that this is in the model frame */
  ROS_INFO_STREAM("Translation: \n" << end_effector_state.translation() << "\n");
  ROS_INFO_STREAM("Rotation: \n" << end_effector_state.rotation() << "\n");
  Eigen::Quaterniond end_effector_quaternion(end_effector_state.rotation());

  //-----------------------------start the demo---------------------------------

  visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to start the demo");
  // plan a motion for this group to a desired pose for the end-effector.
  geometry_msgs::Pose target_pose1;
  target_pose1.orientation.x = end_effector_quaternion.x();
  target_pose1.orientation.y = end_effector_quaternion.y();
  target_pose1.orientation.z = end_effector_quaternion.z();
  target_pose1.orientation.w = end_effector_quaternion.w();
  target_pose1.position.x = end_effector_state.translation().x();
  target_pose1.position.y = end_effector_state.translation().y();
  target_pose1.position.z = end_effector_state.translation().z();
  //  move_group.setPoseTarget(target_pose1);
  move_group.setApproximateJointValueTarget(target_pose1);

  // plan and visualize it but not asking move_group to actually move the robot.
  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
  ROS_INFO_NAMED("move_group_interface_demo", "Visualizing plan 1 (pose goal) %s", success ? "" : "FAILED");

  // Visualizing plans
  ROS_INFO_NAMED("move_group_interface_demo", "Visualizing plan 1 as trajectory line");
  visual_tools.publishAxisLabeled(target_pose1, "pose1");
  visual_tools.publishText(text_pose, "Pose Goal", rvt::WHITE, rvt::XLARGE);
  visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
  visual_tools.trigger();
  visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to continue the demo");

  // Moving to a pose goal
  /* Uncomment below line when working with a real robot */
  move_group.move();

//  // Planning to a joint-space goal
//  // RobotState is the object that contains all the current position/velocity/acceleration data.
//  moveit::core::RobotStatePtr current_state = move_group.getCurrentState();
//  // Next get the current set of joint values for the group.
//  std::vector<double> joint_group_positions;
//  current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
//  // modify the joints, plan to the new joint space goal and visualize the plan.
//  joint_group_positions[0] = 0.0;
//  joint_group_positions[1] = -0.2;
//  joint_group_positions[2] = 1.2;
//  joint_group_positions[3] = 1.2;
//  move_group.setJointValueTarget(joint_group_positions);

//  // lower the allowed maximum velocity and acceleration to 5% of their maximum.
//  // The default values are 10% (0.1).
//  // Set preferred defaults in the joint_limits.yaml file of your robot's moveit_config
//  // or set explicit factors in your code if you need your robot to move faster.
//  move_group.setMaxVelocityScalingFactor(0.05);
//  move_group.setMaxAccelerationScalingFactor(0.05);

//  success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
//  ROS_INFO_NAMED("move_group_interface_demo", "Visualizing plan 2 (joint space goal) %s", success ? "" : "FAILED");
//  // Visualize the plan in RViz
//  visual_tools.deleteAllMarkers();
//  visual_tools.publishText(text_pose, "Joint Space Goal", rvt::WHITE, rvt::XLARGE);
//  visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
//  visual_tools.trigger();
//  visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to continue the demo");


  // End the demo
  ROS_INFO("Demo ended, bye!");
  ros::shutdown();
  return 0;
}
