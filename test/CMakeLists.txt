##################################################################
#                          ExampleTest                           #
##################################################################
add_executable(ExampleTest ExampleTest.cpp)
target_link_libraries(ExampleTest PRIVATE gtest gmock)
add_test(NAME ExampleTest COMMAND ExampleTest)