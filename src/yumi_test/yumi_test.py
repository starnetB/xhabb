from __future__ import print_function
import fractions
import threading
from six.moves import input

import sys
import copy
import rospy 
import moveit_commander
import moveit_msgs.msg
import geometry_msgs

from functools import partial
from threading import Thread
import time

try:
    from math import pi,tau,dist,fabs,cos
except:
    from math import pi,fabs,cos,sqrt



class my_Thread(threading.Thread):
    def __init__(self,add):
        threading.Thread.__init__(self)
        self.add=add
    
    def run(self):
        for arc in self.add:
            print(threading.current_thread().getName() +" "+ arc)



class MoveGroupPythonInterfaceTutorial(threading.Thread):
    """MoveGroupPythonInterfaceTutorial"""
    def __init__(self):
        threading.Thread.__init__(self)

        robot = moveit_commander.RobotCommander()
        scene = moveit_commander.PlanningSceneInterface()
        group_name_L = "left_arm"
        move_group_L= moveit_commander.MoveGroupCommander(group_name_L)

        group_name_R = "right_arm"
        move_group_R= moveit_commander.MoveGroupCommander(group_name_R)

        group_name = "both_arms"
        move_group = moveit_commander.MoveGroupCommander(group_name)
        
        display_trajectory_publisher = rospy.Publisher(
            "/move_group/display_planned_path",
            moveit_msgs.msg.DisplayTrajectory,
            queue_size=20,
        )

        planning_frame_L = move_group_L.get_planning_frame()
        print("============ Planning frame_L: %s" % planning_frame_L)
        planning_frame_R = move_group_R.get_planning_frame()
        print("============ Planning frame_R: %s" % planning_frame_R)

        eef_link_L = move_group_L.get_end_effector_link()
        print("============ End effector link_L: %s" % eef_link_L)
        eef_link_R = move_group_R.get_end_effector_link()
        print("============ End effector link_R: %s" % eef_link_R)

        eef_link =move_group.has_end_effector_link()
        print("============ End effector link_R: %s" % eef_link)

        group_names = robot.get_group_names()
        print("============ Available Planning Groups:", robot.get_group_names())

        print("============ Printing robot_left_arm state")
        print(robot.get_current_state())

        # print(move_group.get_current_state())
        # print("")

        # Misc variables
        # self.box_name = ""
        self.robot = robot
        self.scene = scene
        self.move_group_L = move_group_L
        self.move_group_R = move_group_R
        self.move_group = move_group
        self.display_trajectory_publisher = display_trajectory_publisher
        self.planning_frame = planning_frame_L
        self.planning_frame = planning_frame_R

        self.eef_link_L = eef_link_L
        self.eef_link_R = eef_link_R

        self.group_names = group_names
    

    def go_to_joint_state(self):
        move_group_L = self.move_group_L
        move_group_R = self.move_group_R
        move_group=self.move_group

        # joint_goal_L=move_group_L.get_current_joint_values()
        # joint_goal_L[0]-=tau/8
        # joint_goal_R=move_group_R.get_current_joint_values()
        # joint_goal_R[0]-=tau/8
        joint_goal=move_group.get_current_joint_values()
        print(len(joint_goal))
        # joint_goal[0]-=tau/8
        # joint_goal[7]-=tau/8

        move_group.go(joint_goal,wait=True)
        move_group.stop()
    

    def go_to_pose_goal(self):
        waypoints=[]
        move_group=self.move_group_L
        wpose=move_group.get_current_pose().pose
        wpose.position.z -= 0.01  # First move up (z)
        waypoints.append(copy.deepcopy(wpose))
    
    def run(self):
        for arc in self.add:
            print(threading.current_thread().getName() +" "+ arc)



def main():
    tutorial = MoveGroupPythonInterfaceTutorial()
    tutorial.go_to_joint_state();
    


if __name__=="__main__":
    main()
    # my_tuple=("K","W","S")
    # mythread=my_Thread(my_tuple)
    # mythread.start()

