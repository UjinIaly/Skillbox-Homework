# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/iwaly/Skillbox-Homework/hw_32.1/cmake-build-debug/_deps/json-src"
  "/home/iwaly/Skillbox-Homework/hw_32.1/cmake-build-debug/_deps/json-build"
  "/home/iwaly/Skillbox-Homework/hw_32.1/cmake-build-debug/_deps/json-subbuild/json-populate-prefix"
  "/home/iwaly/Skillbox-Homework/hw_32.1/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/tmp"
  "/home/iwaly/Skillbox-Homework/hw_32.1/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
  "/home/iwaly/Skillbox-Homework/hw_32.1/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src"
  "/home/iwaly/Skillbox-Homework/hw_32.1/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/iwaly/Skillbox-Homework/hw_32.1/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/${subDir}")
endforeach()
