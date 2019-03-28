cmake_minimum_required(VERSION 3.13)
project(CodingTomorrow)

set(CMAKE_CXX_STANDARD 17)

add_executable(CodingTomorrow main.cpp Object.cpp Object.hpp Car.cpp Car.hpp Pedestrian.cpp Pedestrian.hpp Passenger.cpp Passenger.hpp)