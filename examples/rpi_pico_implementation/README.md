# AT24CX - PICO-SDK

AT24CX i2c library for PICO-SDK.
PICO-SDK template used for this project: https://github.com/raspberrypi/pico-examples/tree/master/i2c/mpu6050_i2c

## Overview

This example demonstrates usage of AT24C512 eeprom for reading/writing.

### Hardware Required

To run this example, you should have one RP2040 based development board (such as Rapsberry Pi Pico) as well as a AT24C512 (This library works with other AT24CX variants as well). AT24C512 provides 524,288 bits of serial electrically erasable and programmable read only memory (EEPROM) organized as 65,536 words of 8 bits each. You can read the datasheet [here](http://ww1.microchip.com/downloads/en/devicedoc/doc1116.pdf).

#### Pin Assignment:

|                  | SDA                      | SCL                      |
| ---------------- | ------------------------ | ------------------------ |
| PICO I2C Master  | PICO_DEFAULT_I2C_SDA_PIN | PICO_DEFAULT_I2C_SCL_PIN |
| AT24CX           | SDA                      | SCL                      |


Note: There’s no need to add an external pull-up resistors for SDA/SCL pin, because the driver will enable the internal pull-up resistors.

### Build and Flash

mkdir build

cd build

cmake -G "MinGW Makefiles" ..

make

## Example Output

```bash

```
