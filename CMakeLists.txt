cmake_minimum_required(VERSION 3.16.3)

if(CMAKE_CXX_STANDARD EQUAL "11" )
   message(FATAL_ERROR "CMAKE_CXX_STANDARD:STRING=11 is not supported in ITK version 5.3 and greater.")
endif()

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14) # Supported values are ``14``, ``17``, and ``20``.
endif()
if(NOT CMAKE_CXX_STANDARD_REQUIRED)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()
if(NOT CMAKE_CXX_EXTENSIONS)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

project(MorphologicalContourInterpolation)

if(NOT ITK_SOURCE_DIR)
  find_package(ITK 4.9 REQUIRED)
  list(APPEND CMAKE_MODULE_PATH ${ITK_CMAKE_DIR})
  include(ITKModuleExternal)
else()
  set(ITK_DIR ${CMAKE_BINARY_DIR})
  itk_module_impl()
endif()

itk_module_examples()
