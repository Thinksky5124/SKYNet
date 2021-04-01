cmake_minimum_required(VERSION 3.16) 

# set the project name 
project(AutoGrad VERSION 1.0) 

# include header file
include_directories(
${PROJECT_SOURCE_DIR} ../../SKYImage/option/include/
)

target_link_libraries(svd_demo ${ARMADILLO_LIB_DIRS} armadillo)

# add the executable 
add_executable(AutoGrad autograd.cpp)