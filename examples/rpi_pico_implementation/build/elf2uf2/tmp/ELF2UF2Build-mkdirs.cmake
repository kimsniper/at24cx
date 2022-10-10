# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/VSARM/sdk/pico/pico-sdk/tools/elf2uf2"
  "C:/Espressif/frameworks/esp-idf-v4.4.2/esp/AT24CX/examples/rpi_pico_implementation/build/elf2uf2"
  "C:/Espressif/frameworks/esp-idf-v4.4.2/esp/AT24CX/examples/rpi_pico_implementation/build/elf2uf2"
  "C:/Espressif/frameworks/esp-idf-v4.4.2/esp/AT24CX/examples/rpi_pico_implementation/build/elf2uf2/tmp"
  "C:/Espressif/frameworks/esp-idf-v4.4.2/esp/AT24CX/examples/rpi_pico_implementation/build/elf2uf2/src/ELF2UF2Build-stamp"
  "C:/Espressif/frameworks/esp-idf-v4.4.2/esp/AT24CX/examples/rpi_pico_implementation/build/elf2uf2/src"
  "C:/Espressif/frameworks/esp-idf-v4.4.2/esp/AT24CX/examples/rpi_pico_implementation/build/elf2uf2/src/ELF2UF2Build-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Espressif/frameworks/esp-idf-v4.4.2/esp/AT24CX/examples/rpi_pico_implementation/build/elf2uf2/src/ELF2UF2Build-stamp/${subDir}")
endforeach()
