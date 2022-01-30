cmake_minimum_required(VERSION 3.21)
project(Philosophers C)

set(CMAKE_C_STANDARD 99)

include_directories(philo/include)

add_executable(Philosophers
        philo/include/philo.h
        philo/src/philosophers.c
        philo/src/utils.c)
