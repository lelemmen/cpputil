# cpputil v1.6.0

[![Build Status](https://travis-ci.org/GQCG/cpputil.svg?branch=master)](https://travis-ci.org/GQCG/cpputil)

A C++ library that includes utility functions that do not belong in our other, more specific, libraries.



## Dependencies

[![Boost Dependency](https://img.shields.io/badge/Boost-1.65.1+-000000.svg)](http://www.boost.org)
[![Eigen3 Dependency](https://img.shields.io/badge/Eigen-3.3.4+-000000.svg)](http://eigen.tuxfamily.org/index.php?title=Main_Page)



## Installation

To install this library:
1. clone the master branch, which contains the latest release:

        git clone git@github.com:GQCG/cpputil.git --branch master --single-branch
        cd cpputil

2. perform an out-of-source cmake build:

        mkdir build && cd build
        cmake -DINSTALLATION_PREFIX=prefix ..
        make && make test && sudo make install

    where
    * `prefix` is the installation prefix (defaulted to `/usr/local`) you want the library to be installed at:
        * the library `libcpputil.a` will be installed in `prefix/cpputil/lib`
        * the header files (and cmake files, see Usage) will be installed in `prefix/cpputil/include`



## Usage
Basic usage of this library can be found in the `tests` directory. If you use CMake in other projects, you can add the following CMake command to the CMakeLists.txt-file:

    find_package(cpputil 1.6.0)

CMake then provides the commands `cpputil_INCLUDE_DIRS` to be used in your `target_include_directories` and the library `cpputil` to be used in your `target_link_libraries`.
