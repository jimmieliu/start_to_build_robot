# Description 描述
OpenCV lessons so far relavent to the repo's target. It will be updated gradually.

# Lessons 课程 (so far)
- 0. Open Image and Basic Data Structure. 打开图像，和基本图像数据结构 

# Build 编译
Lessons are written in c++ like common industrial programs. Building tool is CMake, check CMakeLists.txt for configs.
Steps to build:
本课程根据工业界普遍做法——用c++编写。编译工具是CMake，具体配置见CMakeLists.txt。
编译步骤：

1. cmake . # If any change made to CMakeLists. 如果修改了CMakeLists，或者需要对c++增加依赖库
2. make # If only c++ files changed. 如果只修改了c++文件


## A Mapping of Type to Numbers in OpenCV [linkto](http://ninghang.blogspot.com/2012/11/list-of-mat-type-in-opencv.html)
| | C1 | C2 | C3 | C4
|---|---|---|---|---|
|CV_8U|	0|	8|	16|	24
|CV_8S|	1|	9|	17|	25
|CV_16U| 2|	10|	18|	26
|CV_16S| 3|	11|	19|	27
|CV_32S| 4|	12|	20|	28
|CV_32F| 5|	13|	21|	29
|CV_64F| 6|	14|	22|	30
