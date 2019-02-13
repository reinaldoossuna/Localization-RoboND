#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

struct goal_pose{
  float x;
  float y;
  float z;
  float orient_x;
  float orient_y;
  float orient_z;
  float orient_w;
};

move_base_msgs::MoveBaseGoal create_goal(struct goal_pose);

struct goal_pose GOAL1= {0.995,
               -2.99,
                 0.0,
                 0.0,
                 0.0,
                 1.0
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "navigation_goals");
    // Spin a thread
    MoveBaseClient ac("move_base", true);

    // Wait for the action server to come up
    ROS_INFO("Waiting for the move_base action server");
    ac.waitForServer(ros::Duration(5));

    ROS_INFO("Connected to move_base server");

    move_base_msgs::MoveBaseGoal goal = create_goal(GOAL1);
    ROS_INFO("Sending goal");
    ac.sendGoal(goal);

    ac.waitForResult();

    if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Excellent! Your robot has reached the goal position.");
    else
        ROS_INFO("The robot failed to reach the goal position");

    return 0;
}

move_base_msgs::MoveBaseGoal create_goal(struct goal_pose g)
{

    move_base_msgs::MoveBaseGoal goal;

    // Send goal pose
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();

    goal.target_pose.pose.position.x = g.x;
    goal.target_pose.pose.position.y = g.y;

    goal.target_pose.pose.orientation.x = g.orient_x;
    goal.target_pose.pose.orientation.y = g.orient_y;
    goal.target_pose.pose.orientation.z = g.orient_z;
    goal.target_pose.pose.orientation.w = g.orient_w;

    return goal;

}
