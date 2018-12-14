# ModelLoader
## H62PEP Project Repo for Group 21
This repo contains a C++ library which is able to load and save a proprietary model format for display in a QT/VTK CAD preview application which will be developed in semester two.

## Setup
```sh
mkdir build
cd build
cmake ..
make [optional: ModelLoader | ModelLoaderTest | ModelLoaderNormal] -jN # N specifies number of threads to make with
```

## Running
Unit tests can be run by using (omit the grep pipe at the end if you want to see debug output):
```sh
./ModelLoaderTest --use-colour yes | grep -Ev "INFO|DEBUG|TRACE" --color=never
```

Test application which loads files and outputs can be run using (edit or omit the grep to view debug info including full details on loaded cells, vertices and mats):
```sh
./ModelLoaderNormal | grep -Ev "DEBUG|TRACE"
```

## OpenGL
Preliminary OpenGL/GLUT support can be found in the glut branch.
