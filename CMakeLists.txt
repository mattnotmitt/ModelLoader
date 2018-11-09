cmake_minimum_required(VERSION 3.12)
project(ModelLoader)

set(CMAKE_CXX_STANDARD 14)
include_directories(inc src lib)

add_library(ModelLoader src/test.cpp src/Cell.cpp src/Hexahedron.cpp src/Material.cpp src/Model.cpp src/Pyramid.cpp src/Tetrahedron.cpp src/Vec3.cpp inc/Cell.h inc/Hexahedron.h inc/Material.h inc/Model.h inc/Pyramid.h inc/Tetrahedron.h inc/Vec3.h)
target_include_directories(ModelLoader PUBLIC lib inc src)

add_executable(ModelLoaderTest src/test.cpp src/Cell.cpp src/Hexahedron.cpp src/Material.cpp src/Model.cpp src/Pyramid.cpp src/Tetrahedron.cpp src/Vec3.cpp inc/Cell.h inc/Hexahedron.h inc/Material.h inc/Model.h inc/Pyramid.h inc/Tetrahedron.h inc/Vec3.h)
target_include_directories(ModelLoader PUBLIC lib inc src)
