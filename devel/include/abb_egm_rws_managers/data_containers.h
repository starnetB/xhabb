/***********************************************************************************************************************
 *
 * Copyright (c) 2020, ABB Schweiz AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with
 * or without modification, are permitted provided that
 * the following conditions are met:
 *
 *    * Redistributions of source code must retain the
 *      above copyright notice, this list of conditions
 *      and the following disclaimer.
 *    * Redistributions in binary form must reproduce the
 *      above copyright notice, this list of conditions
 *      and the following disclaimer in the documentation
 *      and/or other materials provided with the
 *      distribution.
 *    * Neither the name of ABB nor the names of its
 *      contributors may be used to endorse or promote
 *      products derived from this software without
 *      specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ***********************************************************************************************************************
 */

#ifndef ABB_EGM_RWS_MANAGERS_DATA_CONTAINERS_H
#define ABB_EGM_RWS_MANAGERS_DATA_CONTAINERS_H

#include <map>
#include <string>
#include <vector>

#include <abb_libegm/egm_controller_interface.h>
#include <abb_librws/rws_state_machine_interface.h>

#include "abb_egm_rws_managers_export.h"

#include "robot_controller_description.pb.h" // Generated by Google Protocol Buffer compiler protoc.

namespace abb
{
namespace robot
{

/**
 * \brief Representation of a robot controller's system.
 *
 * Intended to be collected via RWS during initialization.
 */
struct SystemData
{
  /**
   * \brief Important system configurations.
   */
  struct Configurations
  {
    /**
     * \brief 'Mechanical Unit Group' instances.
     */
    std::vector<rws::cfg::sys::MechanicalUnitGroup> mechanical_unit_groups;

    /**
     * \brief 'Mechanical Unit' instances.
     */
    std::vector<rws::cfg::moc::MechanicalUnit> mechanical_units;

    /**
     * \brief 'Robot' instances.
     */
    std::vector<rws::cfg::moc::Robot> robots;

    /**
     * \brief 'Single' instances.
     */
    std::vector<rws::cfg::moc::Single> singles;

    /**
     * \brief 'Joint' instances.
     */
    std::vector<rws::cfg::moc::Joint> joints;

    /**
     * \brief 'Arm' instances.
     */
    std::vector<rws::cfg::moc::Arm> arms;

    /**
     * \brief 'Transmission' instances.
     */
    std::vector<rws::cfg::moc::Transmission> transmissions;
  };

  /**
   * \brief Extra mechanical unit info (complementary to the configuration instances).
   */
  struct MechanicalUnit
  {
    /**
     * \brief Static info.
     */
    rws::RWSInterface::MechanicalUnitStaticInfo static_info;

    /**
     * \brief Dynamic info (i.e. can change during runtime).
     */
    rws::RWSInterface::MechanicalUnitDynamicInfo dynamic_info;
  };

  /**
   * \brief RAPID task info.
   */
  struct RAPIDTask : public rws::RWSInterface::RAPIDTaskInfo
  {
    /**
     * \brief Default constructor.
     */
    RAPIDTask(const rws::RWSInterface::RAPIDTaskInfo& info,
              const std::vector<rws::RWSInterface::RAPIDModuleInfo>& modules)
    :
    RAPIDTaskInfo{info},
    modules{modules}
    {}

    /**
     * \brief The task's modules.
     */
    std::vector<rws::RWSInterface::RAPIDModuleInfo> modules;
  };

  /**
   * \brief IP address to the robot controller.
   */
  std::string ip_address;

  /**
   * \brief Port number used by the robot controller's RWS server.
   */
  unsigned short port_number;

  /**
   * \brief General info about the system.
   */
  rws::RWSInterface::SystemInfo system;

  /**
   * \brief System configurations.
   */
  Configurations configurations;

  /**
   * \brief Extra info about mechancial units.
   */
  std::map<std::string, MechanicalUnit> mechanical_units_extra;

  /**
   * \brief RAPID tasks defined in the system.
   */
  std::vector<RAPIDTask> rapid_tasks;
};

/**
 * \brief Representation of a robot controller's system's state.
 *
 * Intended to be collected via RWS during runtime.
 */
struct SystemStateData
{
  /**
   * \brief State of a mechanical unit.
   */
  struct MechanicalUnit
  {
    /**
     * \brief Indicator for if the unit is active or not.
     */
    bool active;

    /**
     * \brief The unit's current joint target.
     */
    rws::JointTarget joint_target;
  };

  /**
   * \brief State of a RobotWare StateMachine Add-In RAPID instance.
   */
  struct SateMachine
  {
    /**
     * \brief The RAPID task running the instance.
     */
    std::string rapid_task;

    /**
     * \brief The current state of the instance.
     */
    rws::RAPIDNum sm_state;

    /**
     * \brief The current EGM action of the instance.
     */
    rws::RAPIDNum egm_action;
  };

  /**
   * \brief Resets all state data.
   */
  void reset()
  {
    system_name.clear();
    motors_on = rws::TriBool::UNKNOWN_VALUE;
    auto_mode = rws::TriBool::UNKNOWN_VALUE;
    rapid_running = rws::TriBool::UNKNOWN_VALUE;
    mechanical_units.clear();
    rapid_tasks.clear();
    state_machines.clear();
  }

  /**
   * \brief Name of the robot controller's active system.
   */
  std::string system_name;

  /**
   * \brief Indicator for if the motors are on, off or unknown.
   */
  rws::TriBool motors_on;

  /**
   * \brief Indicator for if the mode is auto, manual or unknown.
   */
  rws::TriBool auto_mode;

  /**
   * \brief Indicator for if RAPID is running, stopped or unknown.
   */
  rws::TriBool rapid_running;

  /**
   * \brief State data for all known mechanical units.
   */
  std::map<std::string, MechanicalUnit> mechanical_units;

  /**
   * \brief State data for all known RAPID tasks.
   */
  std::vector<rws::RWSInterface::RAPIDTaskInfo> rapid_tasks;

  /**
   * \brief State data for all known RobotWare StateMachine Add-In RAPID instances.
   */
  std::vector<SateMachine> state_machines;
};

/**
 * \brief Representation of data concerning a single EGM channel.
 */
struct EGMChannelData
{
  /**
   * \brief Name of the channel.
   */
  std::string name;

  /**
   * \brief Port number used by the channel.
   */
  unsigned short port_number;

  /**
   * \brief Indicator for if the channel was activated or deactivated.
   */
  bool was_activated_or_deactivated;

  /**
   * \brief Indicator for if the channel is active.
   */
  bool is_active;

  /**
   * \brief Indicator for if the RAPID execution status has changed.
   */
  bool rapid_execution_status_changed;

  /**
   * \brief Indicator for if the EGM client's state has changed.
   */
  bool egm_client_state_changed;

  /**
   * \brief The channel's latest input.
   *
   * Note: The inputs are from the external EGM server's perspective,
   *       i.e. output from the robot controller is input to the server.
   */
  egm::wrapper::Input input;
};

/**
 * \brief Representation of a robot controller's motion data.
 *
 * Intended to be collected/controlled via RWS and/or EGM during runtime.
 */
struct MotionData
{
  /**
   * \brief State of a joint.
   */
  struct JointState
  {
    /**
     * \brief Position in [radians] or [m].
     */
    double position;

    /**
     * \brief Velocity in [radians/s] or [m/s] (this is only intended for EGM).
     */
    double velocity;

    /**
     * \brief Effort in [Nm] or [N] (this is only used as a placeholder).
     */
    double effort;
  };

  /**
   * \brief Command for a joint (this is only intended for EGM).
   */
  struct JointCommand
  {
    /**
     * \brief Position in [radians] or [m].
     */
    double position;

    /**
     * \brief Velocity in [radians/s] or [m/s].
     */
    double velocity;
  };

  /**
   * \brief Motion data for a joint.
   */
  struct Joint
  {
    /**
     * \brief The joint's (standardized) name.
     */
    std::string name;

    /**
     * \brief Indicator for rotational or linear motion.
     */
    bool rotational;

    /**
     * \brief Lower limit in [radians] or [m].
     */
    double lower_limit;

    /**
     * \brief Upper limit in [radians] or [m].
     */
    double upper_limit;

    /**
     * \brief State of the joint.
     */
    JointState state;

    /**
     * \brief Command for the joint.
     */
    JointCommand command;
  };

  /**
   * \brief Motion data for a mechanical unit.
   */
  struct MechanicalUnit
  {
    /**
     * \brief The unit's name.
     */
    std::string name;

    /**
     * \brief The unit's type.
     */
    MechanicalUnit_Type type;

    /**
     * \brief Indicator for if the unit is active or not.
     */
    bool active;

    /**
     * \brief The unit's joints.
     */
    std::vector<Joint> joints;

    /**
     * \brief Indicator for if the unit is supported by EGM or not.
     */
    bool supported_by_egm;
  };

  /**
   * \brief Motion data for a mechanical unit group.
   */
  struct MechanicalUnitGroup
  {
    /**
     * \brief The groups's name.
     */
    std::string name;

    /**
     * \brief The group's mechanical units.
     */
    std::vector<MechanicalUnit> units;

    /**
     * \brief Data concerning the (optional) EGM channel that could be used by the group.
     */
    EGMChannelData egm_channel_data;
  };

  /**
   * \brief Motion data for all known mechanical unit groups.
   */
  std::vector<MechanicalUnitGroup> groups;
};

}
}

#endif
