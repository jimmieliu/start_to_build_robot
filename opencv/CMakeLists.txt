cmake_minimum_required(VERSION 2.8)
project(OpenCVLesson)

# opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
message(STATUS OpenCV_LIBS: ${OpenCV_LIBS})
# eigen3
find_package(Eigen3 REQUIRED NO_MODULE)

# file(GLOB_RECURSE my_c_list RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
file(GLOB my_c_list RELATIVE ${CMAKE_SOURCE_DIR} "./*.cpp")
# message(STATUS CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR})
# message(STATUS my_c_list: ${my_c_list})
foreach(file_path ${my_c_list})
  string(REPLACE ".cpp" "" new_name ${file_path})
  get_filename_component(filename ${new_name} NAME)
  # message(STATUS file_path: ${file_path}, new_name:${new_name}, filename:${filename})
  add_executable(${filename} ${file_path})
  target_link_libraries(${filename} ${OpenCV_LIBS})
  target_link_libraries(${filename} Eigen3::Eigen)
endforeach()

