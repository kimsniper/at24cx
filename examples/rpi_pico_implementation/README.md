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
Initializing AT24CX. . .
Device registered. Status: Active, Chip: AT24C512, Address: 0x50, Size: 65535

eeprom_1 is detected

Write byte demo: This will write value 0 at address 0x00, 1 at address 0x01 and so on

Writing at address 0x00: 0
Writing at address 0x01: 1
Writing at address 0x02: 2
Writing at address 0x03: 3
Writing at address 0x04: 4
Writing at address 0x05: 5
Writing at address 0x06: 6
Writing at address 0x07: 7
Writing at address 0x08: 8
Writing at address 0x09: 9

Read byte demo: Obtain values from addresses 0x00 to 0x09, values should be from 0 to 9 respectively

Reading at address 0x00: 0
Reading at address 0x01: 1
Reading at address 0x02: 2
Reading at address 0x03: 3
Reading at address 0x04: 4
Reading at address 0x05: 5
Reading at address 0x06: 6
Reading at address 0x07: 7
Reading at address 0x08: 8
Reading at address 0x09: 9

Read byte at current address demo: Obtain values from addresses
Overwrite address 0x04 with the same value to set the current address which will be 0x05

Writing at address 0x04: 4

Now read current address which is 0x05, value should be 5
Reading at current address: 5

```
