# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/iwaly/Skillbox-Homework/hw_30.1.1/cmake-build-debug/_deps/cpr-src"
  "/home/iwaly/Skillbox-Homework/hw_30.1.1/cmake-build-debug/_deps/cpr-build"
  "/home/iwaly/Skillbox-Homework/hw_30.1.1/cmake-build-debug/_deps/cpr-subbuild/cpr-populate-prefix"
  "/home/iwaly/Skillbox-Homework/hw_30.1.1/cmake-build-debug/_deps/cpr-subbuild/cpr-populate-prefix/tmp"
  "/home/iwaly/Skillbox-Homework/hw_30.1.1/cmake-build-debug/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp"
  "/home/iwaly/Skillbox-Homework/hw_30.1.1/cmake-build-debug/_deps/cpr-subbuild/cpr-populate-prefix/src"
  "/home/iwaly/Skillbox-Homework/hw_30.1.1/cmake-build-debug/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/iwaly/Skillbox-Homework/hw_30.1.1/cmake-build-debug/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp/${subDir}")
endforeach()
