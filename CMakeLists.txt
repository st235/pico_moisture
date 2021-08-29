cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pi_plants_moisture C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(plants_moisture
    src/app.cpp

    # hardware
    src/hardware/Pin.h

    src/hardware/AnalogPin.h
    src/hardware/AnalogPin.cpp
)

pico_enable_stdio_usb(plants_moisture 1)
pico_enable_stdio_uart(plants_moisture 1)

pico_add_extra_outputs(plants_moisture)

target_link_libraries(plants_moisture pico_stdlib hardware_adc)
