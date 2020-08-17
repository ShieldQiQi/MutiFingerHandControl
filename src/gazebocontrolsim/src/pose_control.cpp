#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pose_control");
  ros::NodeHandle nh;

  ros::Publisher joint11_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J11_controller/command", 1);
  ros::Publisher joint12_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J12_controller/command", 1);
  ros::Publisher joint13_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J13_controller/command", 1);
  ros::Publisher joint14_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J14_controller/command", 1);
  ros::Publisher joint15_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J15_controller/command", 1);
  std_msgs::Float64 joint11_state;
  std_msgs::Float64 joint12_state;
  std_msgs::Float64 joint13_state;
  std_msgs::Float64 joint14_state;
  std_msgs::Float64 joint15_state;

  ros::Publisher joint21_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J21_controller/command", 1);
  ros::Publisher joint22_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J22_controller/command", 1);
  ros::Publisher joint23_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J23_controller/command", 1);
  ros::Publisher joint24_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J24_controller/command", 1);
  std_msgs::Float64 joint21_state;
  std_msgs::Float64 joint22_state;
  std_msgs::Float64 joint23_state;
  std_msgs::Float64 joint24_state;

  ros::Publisher joint31_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J31_controller/command", 1);
  ros::Publisher joint32_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J32_controller/command", 1);
  ros::Publisher joint33_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J33_controller/command", 1);
  ros::Publisher joint34_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J34_controller/command", 1);
  std_msgs::Float64 joint31_state;
  std_msgs::Float64 joint32_state;
  std_msgs::Float64 joint33_state;
  std_msgs::Float64 joint34_state;

  ros::Publisher joint41_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J41_controller/command", 1);
  ros::Publisher joint42_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J42_controller/command", 1);
  ros::Publisher joint43_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J43_controller/command", 1);
  ros::Publisher joint44_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J44_controller/command", 1);
  std_msgs::Float64 joint41_state;
  std_msgs::Float64 joint42_state;
  std_msgs::Float64 joint43_state;
  std_msgs::Float64 joint44_state;

  ros::Publisher joint51_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J51_controller/command", 1);
  ros::Publisher joint52_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J52_controller/command", 1);
  ros::Publisher joint53_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J53_controller/command", 1);
  ros::Publisher joint54_pub = nh.advertise<std_msgs::Float64>("/mutifingerhand/J54_controller/command", 1);
  std_msgs::Float64 joint51_state;
  std_msgs::Float64 joint52_state;
  std_msgs::Float64 joint53_state;
  std_msgs::Float64 joint54_state;

  joint11_state.data = 0;
  joint12_state.data = 0;
  joint13_state.data = 0;
  joint14_state.data = 0;
  joint15_state.data = 0;

  joint21_state.data = 0.7;
  joint22_state.data = 0;
  joint23_state.data = 0.3;
  joint24_state.data = 0;

  joint31_state.data = 0.5;
  joint32_state.data = 0;
  joint33_state.data = 0.3;
  joint34_state.data = 0;

  joint41_state.data = 0.3;
  joint42_state.data = 0;
  joint43_state.data = 0;
  joint44_state.data = 0.3;

  joint51_state.data = 0.1;
  joint52_state.data = 0;
  joint53_state.data = 0.3;
  joint54_state.data = 0.3;

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    joint11_pub.publish(joint11_state);
    joint12_pub.publish(joint12_state);
    joint13_pub.publish(joint13_state);
    joint14_pub.publish(joint14_state);
    joint15_pub.publish(joint15_state);

    joint21_pub.publish(joint21_state);
    joint22_pub.publish(joint22_state);
    joint23_pub.publish(joint23_state);
    joint24_pub.publish(joint24_state);

    joint31_pub.publish(joint31_state);
    joint32_pub.publish(joint32_state);
    joint33_pub.publish(joint33_state);
    joint34_pub.publish(joint34_state);

    joint41_pub.publish(joint41_state);
    joint42_pub.publish(joint42_state);
    joint43_pub.publish(joint43_state);
    joint44_pub.publish(joint44_state);

    joint51_pub.publish(joint51_state);
    joint52_pub.publish(joint52_state);
    joint53_pub.publish(joint53_state);
    joint54_pub.publish(joint54_state);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
