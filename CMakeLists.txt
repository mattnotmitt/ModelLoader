cmake_minimum_required(VERSION 3.12)
project(ModelLoader)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc src lib)
add_library(ModelLoader src/Cell.cpp src/Hexahedron.cpp
src/Material.cpp src/Model.cpp src/Pyramid.cpp src/Tetrahedron.cpp
src/Vec3.cpp inc/Cell.h inc/Hexahedron.h inc/Material.h inc/Model.h
inc/Pyramid.h inc/Tetrahedron.h inc/Vec3.h src/Matrix.cpp inc/Matrix.h)

add_executable(ModelLoaderTest test/test.cpp src/Cell.cpp src/Hexahedron.cpp
src/Material.cpp src/Model.cpp src/Pyramid.cpp src/Tetrahedron.cpp
src/Vec3.cpp inc/Cell.h inc/Hexahedron.h inc/Material.h inc/Model.h
inc/Pyramid.h inc/Tetrahedron.h inc/Vec3.h src/Matrix.cpp inc/Matrix.h
test/ModelTest.cpp test/Vec3Test.cpp)
target_include_directories(ModelLoader PUBLIC lib inc src)

add_executable(ModelLoaderTest test/test.cpp src/Cell.cpp src/Hexahedron.cpp src/Material.cpp src/Model.cpp src/Pyramid.cpp src/Tetrahedron.cpp src/Vec3.cpp inc/Cell.h inc/Hexahedron.h inc/Material.h inc/Model.h inc/Pyramid.h inc/Tetrahedron.h inc/Vec3.h test/ModelTest.cpp test/Vec3Test.cpp)

add_executable(ModelLoaderNormal src/main.cpp src/Cell.cpp src/Hexahedron.cpp src/Material.cpp src/Model.cpp src/Pyramid.cpp src/Tetrahedron.cpp src/Vec3.cpp inc/Cell.h inc/Hexahedron.h inc/Material.h inc/Model.h inc/Pyramid.h inc/Tetrahedron.h inc/Vec3.h src/main.cpp)
