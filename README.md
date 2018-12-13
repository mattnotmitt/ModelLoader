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
Unit tests can be run by using:
```sh
./ModelLoaderTest
```

Test application which loads files and outputs can be run using:
```sh
./ModelLoaderNormal
```
