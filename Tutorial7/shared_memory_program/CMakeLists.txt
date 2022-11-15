cmake_minimum_required(VERSION 3.10)
project(SharedMemoryDemo)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(sender sender.c)
add_executable(reciever reciever.c)

