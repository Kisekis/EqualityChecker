cmake_minimum_required(VERSION 3.23)
project(EqualityChecker)

set(CMAKE_CXX_STANDARD 17)

add_executable(EqualityChecker main.cpp controller.cpp source_code.cpp csv_writer.cpp processer.cpp source_code_reader.cpp)
