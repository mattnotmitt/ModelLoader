cmake_minimum_required(VERSION 3.12)
project(ModelLoader)

set(CMAKE_CXX_STANDARD 14)

add_library(ModelLoader Vector3D.cpp Vector3D.h Cell.cpp Cell.h Material.cpp Material.h Model.cpp Model.h)