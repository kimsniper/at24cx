# Set minimum required cmake version
cmake_minimum_required(VERSION 3.12)

# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake) 

# Set name of project (as PROJECT_NAME) and C/C++ standards
project(at24cx C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our peoject for the libraries
pico_sdk_init()

add_executable(at24cx
        example_usage.c
        at24cx_i2c.c
        at24cx_i2c_hal.c
        )

# pull in common dependencies and additional i2c hardware support
target_link_libraries(at24cx pico_stdlib hardware_i2c)

# create map/bin/hex file etc.
pico_add_extra_outputs(at24cx)