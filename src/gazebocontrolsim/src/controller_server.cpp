#include <ros/ros.h>
#include "actionlib/server/action_server.h"
#include "actionlib/server/server_goal_handle.h"
#include <control_msgs/FollowJointTrajectoryAction.h>

class ControllerServerAction
{
protected:

  ros::NodeHandle nh_;

  actionlib::ActionServer<control_msgs::FollowJointTrajectoryAction>  action_server;
  actionlib::ServerGoalHandle<control_msgs::FollowJointTrajectoryAction> goal_handle_;

  control_msgs::FollowJointTrajectoryResult result_;

public:

  ControllerServerAction(std::string name) :
    action_server(nh_, name, boost::bind(&ControllerServerAction::pubGoalJoints, this, _1), false)
  {
    action_server.start();
  }

  ~ControllerServerAction(void)
  {
  }

  void pubGoalJoints(const actionlib::ServerGoalHandle<control_msgs::FollowJointTrajectoryAction> gh)
  {
    actionlib::ActionServer<control_msgs::FollowJointTrajectoryAction>::Goal goal = *gh.getGoal();

    ROS_INFO("%s %s %s %s", goal.trajectory.points[0].positions[0],goal.trajectory.points[1].positions[0],
        goal.trajectory.points[2].positions[0],goal.trajectory.points[3].positions[0]);
    goal_handle_ = gh;

    goal_handle_.setAccepted();
    result_.error_code = result_.SUCCESSFUL;
    goal_handle_.setSucceeded(result_);
  }

};


int main(int argc, char** argv)
{
  ros::init(argc, argv, "controller_server");

  ControllerServerAction controller_server("j21_controller/follow_joint_trajectory");

  ros::spin();

  return 0;
}
