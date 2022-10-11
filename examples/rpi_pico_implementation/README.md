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

Read byte at current address demo:
Overwrite address 0x04 with the same value to set the current address which will be 0x05

Writing at address 0x04: 4

Now read current address which is 0x05, value should be 5
Reading at current address: 5

Page write demo: Write 128 bytes at once from 0x00 to 0x7f
Writing 128 bytes from 0x00 to 0x7F

Read 128 bytes from 0x00 to 0x7f
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
Reading at address 0x0A: 10
Reading at address 0x0B: 11
Reading at address 0x0C: 12
Reading at address 0x0D: 13
Reading at address 0x0E: 14
Reading at address 0x0F: 15
Reading at address 0x10: 16
Reading at address 0x11: 17
Reading at address 0x12: 18
Reading at address 0x13: 19
Reading at address 0x14: 20
Reading at address 0x15: 21
Reading at address 0x16: 22
Reading at address 0x17: 23
Reading at address 0x18: 24
Reading at address 0x19: 25
Reading at address 0x1A: 26
Reading at address 0x1B: 27
Reading at address 0x1C: 28
Reading at address 0x1D: 29
Reading at address 0x1E: 30
Reading at address 0x1F: 31
Reading at address 0x20: 32
Reading at address 0x21: 33
Reading at address 0x22: 34
Reading at address 0x23: 35
Reading at address 0x24: 36
Reading at address 0x25: 37
Reading at address 0x26: 38
Reading at address 0x27: 39
Reading at address 0x28: 40
Reading at address 0x29: 41
Reading at address 0x2A: 42
Reading at address 0x2B: 43
Reading at address 0x2C: 44
Reading at address 0x2D: 45
Reading at address 0x2E: 46
Reading at address 0x2F: 47
Reading at address 0x30: 48
Reading at address 0x31: 49
Reading at address 0x32: 50
Reading at address 0x33: 51
Reading at address 0x34: 52
Reading at address 0x35: 53
Reading at address 0x36: 54
Reading at address 0x37: 55
Reading at address 0x38: 56
Reading at address 0x39: 57
Reading at address 0x3A: 58
Reading at address 0x3B: 59
Reading at address 0x3C: 60
Reading at address 0x3D: 61
Reading at address 0x3E: 62
Reading at address 0x3F: 63
Reading at address 0x40: 64
Reading at address 0x41: 65
Reading at address 0x42: 66
Reading at address 0x43: 67
Reading at address 0x44: 68
Reading at address 0x45: 69
Reading at address 0x46: 70
Reading at address 0x47: 71
Reading at address 0x48: 72
Reading at address 0x49: 73
Reading at address 0x4A: 74
Reading at address 0x4B: 75
Reading at address 0x4C: 76
Reading at address 0x4D: 77
Reading at address 0x4E: 78
Reading at address 0x4F: 79
Reading at address 0x50: 80
Reading at address 0x51: 81
Reading at address 0x52: 82
Reading at address 0x53: 83
Reading at address 0x54: 84
Reading at address 0x55: 85
Reading at address 0x56: 86
Reading at address 0x57: 87
Reading at address 0x58: 88
Reading at address 0x59: 89
Reading at address 0x5A: 90
Reading at address 0x5B: 91
Reading at address 0x5C: 92
Reading at address 0x5D: 93
Reading at address 0x5E: 94
Reading at address 0x5F: 95
Reading at address 0x60: 96
Reading at address 0x61: 97
Reading at address 0x62: 98
Reading at address 0x63: 99
Reading at address 0x64: 100
Reading at address 0x65: 101
Reading at address 0x66: 102
Reading at address 0x67: 103
Reading at address 0x68: 104
Reading at address 0x69: 105
Reading at address 0x6A: 106
Reading at address 0x6B: 107
Reading at address 0x6C: 108
Reading at address 0x6D: 109
Reading at address 0x6E: 110
Reading at address 0x6F: 111
Reading at address 0x70: 112
Reading at address 0x71: 113
Reading at address 0x72: 114
Reading at address 0x73: 115
Reading at address 0x74: 116
Reading at address 0x75: 117
Reading at address 0x76: 118
Reading at address 0x77: 119
Reading at address 0x78: 120
Reading at address 0x79: 121
Reading at address 0x7A: 122
Reading at address 0x7B: 123
Reading at address 0x7C: 124
Reading at address 0x7D: 125
Reading at address 0x7E: 126
Reading at address 0x7F: 127
```