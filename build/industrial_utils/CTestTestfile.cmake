# CMake generated Testfile for 
# Source directory: /home/ziye01/xhAbb/src/industrial_core/industrial_utils
# Build directory: /home/ziye01/xhAbb/build/industrial_utils
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_industrial_utils_gtest_utest_inds_utils "/home/ziye01/xhAbb/build/industrial_utils/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/ziye01/xhAbb/build/industrial_utils/test_results/industrial_utils/gtest-utest_inds_utils.xml" "--return-code" "/home/ziye01/xhAbb/devel/.private/industrial_utils/lib/industrial_utils/utest_inds_utils --gtest_output=xml:/home/ziye01/xhAbb/build/industrial_utils/test_results/industrial_utils/gtest-utest_inds_utils.xml")
set_tests_properties(_ctest_industrial_utils_gtest_utest_inds_utils PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/catkin/cmake/test/gtest.cmake;98;catkin_run_tests_target;/opt/ros/noetic/share/catkin/cmake/test/gtest.cmake;37;_catkin_add_google_test;/home/ziye01/xhAbb/src/industrial_core/industrial_utils/CMakeLists.txt;24;catkin_add_gtest;/home/ziye01/xhAbb/src/industrial_core/industrial_utils/CMakeLists.txt;0;")
subdirs("gtest")
