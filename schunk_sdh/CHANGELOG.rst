^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package schunk_sdh
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.5.1 (2014-03-20)
------------------
* removed a lot of code related to packages not available in hydro anymore
* fixed dependency
* added libusb dependency
* Merge branch 'groovy_dev' into feature/catkin
* overwrite link if exists
* changed custom_command to custom_target for dependencies
* Merge branch 'feature/catkin' of github.com:abubeck/schunk_modular_robotics into feature/catkin
* changed library to be an imported library
* cmake based shared library linking
* added genmsg
* deleted deprecated file
* fixed linking error of SDH and CAN libraries
* Initial catkinization. Still a linking error in sdh lib.
* Added mapping of joint_values to koint_names
* updated DSA polling policy
* updated SDHLibrary version 0.0.2.6 for i386
* Revert "removed ESD support flags"
  This reverts commit 34fb0db2b990423d7d0efc95602a1119835c8b53.
* updated to SDHLibrary version 0.0.2.6, currenty only for x86_64!
* dsa: added push stop on start
* removed ESD support flags
* dsa: proper shutdown
* dsa: fixed frequency setting
* init topic in contructor
* dsa: added push mode frequency
* dsa: implemented polling mode
* dsa: debug output, logic fixes
* dsa: error counter decrement logic
* dsa: clean-up
* dsa: added reorder parameter
* dsa: added various parameters, auto-publish feature
* dsa: switched to timer callbacks
* dsa: error count in diagnostics msg
* dsa: node handle passing in constructor
* dsa_only compiles
* dsa_only: 60 Hz loop
* dsa_only: removed services
* schunk_sdh: added error counter in dsa_only
* splitted version of sdh/dsa driver
* add effort to joint_states
* added brics velocity interface to schunk_sdh
* fixed warning
* whitespace
* schunk_sdh: stop hand on mode change
* schunk_sdh: read operation mode from paramter server
* schunk_sdh: reordered tactile data to match joint state order
* schunk_sdh: added some more sanity checks
* schunk_sdh: renamed set_velocities to set_velocities_raw
* schunk_sdh: fixed joint order
* schunk_sdh: fixed mode switching
* schunk_sdh: init with position mode as default
* call to MoveHand is not needed because SetAxisTargetVelocity takes effect immediately
* schunk_sdh: added set_velocities topic and velocity control mode
* schunk_sdh: set_operation_mode switches the SDH controller as well
* schunk_sdh: operation mode is a member variable now
* Merge pull request `#2 <https://github.com/ipa320/schunk_modular_robotics/issues/2>`_ from ipa-fxm/master
  JointTrajectoryAction -> FollowJointTrajectoryAction
* Addapted the sdh driver for sdh without sensors
* switched from pr2_controllers_msgs::JointTrajectoryAction to control_msgs::FollowJointTrajectory
* remap recover service to init
* Merge pull request `#3 <https://github.com/ipa320/schunk_modular_robotics/issues/3>`_ from abubeck/master
  fuerte support, compatible with electric
* fuerte migration
* removed unused files
* sdh library version 0.0.2.18 for 32-bit
* setup cob3-4
* added diagnotic topic for initialization states for sdh
* chancged action to private namespace
* using private namespace
* using private namespace
* renamed to schunk
* moved sdh to schunk repository
* Contributors: Alexander Bubeck, Felix Messmer, Florian Weißhardt, Jan Fischer, Mathias Lüdtke, abubeck, ipa-fmw, ipa-fxm, ipa-mdl, robot
