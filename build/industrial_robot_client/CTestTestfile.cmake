# CMake generated Testfile for 
# Source directory: /home/ziye01/xhAbb/src/industrial_core/industrial_robot_client
# Build directory: /home/ziye01/xhAbb/build/industrial_robot_client
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_industrial_robot_client_gtest_utest_robot_client "/home/ziye01/xhAbb/build/industrial_robot_client/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/ziye01/xhAbb/build/industrial_robot_client/test_results/industrial_robot_client/gtest-utest_robot_client.xml" "--return-code" "/home/ziye01/xhAbb/devel/.private/industrial_robot_client/lib/industrial_robot_client/utest_robot_client --gtest_output=xml:/home/ziye01/xhAbb/build/industrial_robot_client/test_results/industrial_robot_client/gtest-utest_robot_client.xml")
set_tests_properties(_ctest_industrial_robot_client_gtest_utest_robot_client PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/catkin/cmake/test/gtest.cmake;98;catkin_run_tests_target;/opt/ros/noetic/share/catkin/cmake/test/gtest.cmake;37;_catkin_add_google_test;/home/ziye01/xhAbb/src/industrial_core/industrial_robot_client/CMakeLists.txt;161;catkin_add_gtest;/home/ziye01/xhAbb/src/industrial_core/industrial_robot_client/CMakeLists.txt;0;")
add_test(_ctest_industrial_robot_client_roslaunch-check_test_roslaunch_test.xml "/home/ziye01/xhAbb/build/industrial_robot_client/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/ziye01/xhAbb/build/industrial_robot_client/test_results/industrial_robot_client/roslaunch-check_test_roslaunch_test.xml.xml" "--return-code" "/usr/bin/cmake -E make_directory /home/ziye01/xhAbb/build/industrial_robot_client/test_results/industrial_robot_client" "/opt/ros/noetic/share/roslaunch/cmake/../scripts/roslaunch-check -o \"/home/ziye01/xhAbb/build/industrial_robot_client/test_results/industrial_robot_client/roslaunch-check_test_roslaunch_test.xml.xml\" \"/home/ziye01/xhAbb/src/industrial_core/industrial_robot_client/test/roslaunch_test.xml\" ")
set_tests_properties(_ctest_industrial_robot_client_roslaunch-check_test_roslaunch_test.xml PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/roslaunch/cmake/roslaunch-extras.cmake;66;catkin_run_tests_target;/home/ziye01/xhAbb/src/industrial_core/industrial_robot_client/CMakeLists.txt;169;roslaunch_add_file_check;/home/ziye01/xhAbb/src/industrial_core/industrial_robot_client/CMakeLists.txt;0;")
subdirs("gtest")