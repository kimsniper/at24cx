# AT24CX - ESP-IDF

AT24CX i2c library for ESP-IDF.
ESP-IDF template used for this project: https://github.com/espressif/esp-idf/tree/master/examples/peripherals/i2c/i2c_simple

## Overview

This example demonstrates usage of AT24C512 eeprom for reading/writing..

### Hardware Required

To run this example, you should have one ESP32, ESP32-S or ESP32-C based development board as well as a AT24C512 (This library works with other AT24CX variants as well). AT24C512 provides 524,288 bits of serial electrically erasable and programmable read only memory (EEPROM) organized as 65,536 words of 8 bits each. You can read the datasheet [here](http://ww1.microchip.com/downloads/en/devicedoc/doc1116.pdf).


#### Pin Assignment:

**Note:** The following pin assignments are used by default, you can change these in the `menuconfig` .

|                  | SDA             | SCL           |
| ---------------- | -------------- | -------------- |
| ESP I2C Master   | I2C_MASTER_SDA | I2C_MASTER_SCL |
| AT24CX         | SDA            | SCL            |


For the actual default value of `I2C_MASTER_SDA` and `I2C_MASTER_SCL` see `Example Configuration` in `menuconfig`.

**Note: ** There’s no need to add an external pull-up resistors for SDA/SCL pin, because the driver will enable the internal pull-up resistors.

### Build and Flash

Enter `idf.py -p PORT flash monitor` to build, flash and monitor the project.

(To exit the serial monitor, type ``Ctrl-]``.)

See the [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) for full steps to configure and use ESP-IDF to build projects.

## Example Output

```bash
I (327) example_usage: Initializing AT24CX. . .
Device registered. Status: Active, Chip: AT24C512, Address: 0x50, Size: 65535
I (337) example_usage: eeprom_1 is detected
I (347) example_usage: Write byte demo: This will write value 0 at address 0x00, 1 at address 0x01 and so on
I (357) example_usage: Writing at address 0x00: 0
I (357) example_usage: Writing at address 0x01: 1
I (367) example_usage: Writing at address 0x02: 2
I (367) example_usage: Writing at address 0x03: 3
I (377) example_usage: Writing at address 0x04: 4
I (377) example_usage: Writing at address 0x05: 5
I (387) example_usage: Writing at address 0x06: 6
I (397) example_usage: Writing at address 0x07: 7
I (397) example_usage: Writing at address 0x08: 8
I (407) example_usage: Writing at address 0x09: 9
I (407) example_usage: Read byte demo: Obtain values from addresses 0x00 to 0x09, values should be from 0 tRV5C387Ao 9 respectively
I (417) example_usage: Reading at address 0x00: 0
I (427) example_usage: Reading at address 0x01: 1
I (427) example_usage: Reading at address 0x02: 2
I (437) example_usage: Reading at address 0x03: 3
I (447) example_usage: Reading at address 0x04: 4
I (447) example_usage: Reading at address 0x05: 5
I (457) example_usage: Reading at address 0x06: 6
I (457) example_usage: Reading at address 0x07: 7
I (467) example_usage: Reading at address 0x08: 8
I (467) example_usage: Reading at address 0x09: 9
I (477) example_usage: Read byte at current address demo: Obtain values from addresses
I (487) example_usage: Overwrite address 0x04 with the same value to set the current address which will be 0x05
I (497) example_usage: Writing at address 0x04: 4
I (497) example_usage: Now read current address which is 0x05, value should be 5
I (507) example_usage: Reading at current address: 5
I (517) example_usage: Page write demo: Write 128 bytes at once from 0x00 to 0x7f
I (527) example_usage: Writing 128 bytes from 0x00 to 0x7F
I (527) example_usage: Read 128 bytes from 0x00 to 0x7f
I (537) example_usage: Reading at address 0x00: 0
I (537) example_usage: Reading at address 0x01: 1
I (547) example_usage: Reading at address 0x02: 2
I (547) example_usage: Reading at address 0x03: 3
I (557) example_usage: Reading at address 0x04: 4
I (557) example_usage: Reading at address 0x05: 5
I (567) example_usage: Reading at address 0x06: 6
I (567) example_usage: Reading at address 0x07: 7
I (577) example_usage: Reading at address 0x08: 8
I (587) example_usage: Reading at address 0x09: 9
I (587) example_usage: Reading at address 0x0A: 10
I (597) example_usage: Reading at address 0x0B: 11
I (597) example_usage: Reading at address 0x0C: 12
I (607) example_usage: Reading at address 0x0D: 13
I (607) example_usage: Reading at address 0x0E: 14
I (617) example_usage: Reading at address 0x0F: 15
I (617) example_usage: Reading at address 0x10: 16
I (627) example_usage: Reading at address 0x11: 17
I (627) example_usage: Reading at address 0x12: 18
I (637) example_usage: Reading at address 0x13: 19
I (647) example_usage: Reading at address 0x14: 20
I (647) example_usage: Reading at address 0x15: 21
I (657) example_usage: Reading at address 0x16: 22
I (657) example_usage: Reading at address 0x17: 23
I (667) example_usage: Reading at address 0x18: 24
I (667) example_usage: Reading at address 0x19: 25
I (677) example_usage: Reading at address 0x1A: 26
I (677) example_usage: Reading at address 0x1B: 27
I (687) example_usage: Reading at address 0x1C: 28
I (687) example_usage: Reading at address 0x1D: 29
I (697) example_usage: Reading at address 0x1E: 30
I (707) example_usage: Reading at address 0x1F: 31
I (707) example_usage: Reading at address 0x20: 32
I (717) example_usage: Reading at address 0x21: 33
I (717) example_usage: Reading at address 0x22: 34
I (727) example_usage: Reading at address 0x23: 35
I (727) example_usage: Reading at address 0x24: 36
I (737) example_usage: Reading at address 0x25: 37
I (737) example_usage: Reading at address 0x26: 38
I (747) example_usage: Reading at address 0x27: 39
I (747) example_usage: Reading at address 0x28: 40
I (757) example_usage: Reading at address 0x29: 41
I (767) example_usage: Reading at address 0x2A: 42
I (767) example_usage: Reading at address 0x2B: 43
I (777) example_usage: Reading at address 0x2C: 44
I (777) example_usage: Reading at address 0x2D: 45
I (787) example_usage: Reading at address 0x2E: 46
I (787) example_usage: Reading at address 0x2F: 47
I (797) example_usage: Reading at address 0x30: 48
I (797) example_usage: Reading at address 0x31: 49
I (807) example_usage: Reading at address 0x32: 50
I (807) example_usage: Reading at address 0x33: 51
I (817) example_usage: Reading at address 0x34: 52
I (827) example_usage: Reading at address 0x35: 53
I (827) example_usage: Reading at address 0x36: 54
I (837) example_usage: Reading at address 0x37: 55
I (837) example_usage: Reading at address 0x38: 56
I (847) example_usage: Reading at address 0x39: 57
I (847) example_usage: Reading at address 0x3A: 58
I (857) example_usage: Reading at address 0x3B: 59
I (857) example_usage: Reading at address 0x3C: 60
I (867) example_usage: Reading at address 0x3D: 61
I (867) example_usage: Reading at address 0x3E: 62
I (877) example_usage: Reading at address 0x3F: 63
I (887) example_usage: Reading at address 0x40: 64
I (887) example_usage: Reading at address 0x41: 65
I (897) example_usage: Reading at address 0x42: 66
I (897) example_usage: Reading at address 0x43: 67
I (907) example_usage: Reading at address 0x44: 68
I (907) example_usage: Reading at address 0x45: 69
I (917) example_usage: Reading at address 0x46: 70
I (917) example_usage: Reading at address 0x47: 71
I (927) example_usage: Reading at address 0x48: 72
I (937) example_usage: Reading at address 0x49: 73
I (937) example_usage: Reading at address 0x4A: 74
I (947) example_usage: Reading at address 0x4B: 75
I (947) example_usage: Reading at address 0x4C: 76
I (957) example_usage: Reading at address 0x4D: 77
I (957) example_usage: Reading at address 0x4E: 78
I (967) example_usage: Reading at address 0x4F: 79
I (967) example_usage: Reading at address 0x50: 80
I (977) example_usage: Reading at address 0x51: 81
I (977) example_usage: Reading at address 0x52: 82
I (987) example_usage: Reading at address 0x53: 83
I (997) example_usage: Reading at address 0x54: 84
I (997) example_usage: Reading at address 0x55: 85
I (1007) example_usage: Reading at address 0x56: 86
I (1007) example_usage: Reading at address 0x57: 87
I (1017) example_usage: Reading at address 0x58: 88
I (1017) example_usage: Reading at address 0x59: 89
I (1027) example_usage: Reading at address 0x5A: 90
I (1027) example_usage: Reading at address 0x5B: 91
I (1037) example_usage: Reading at address 0x5C: 92
I (1047) example_usage: Reading at address 0x5D: 93
I (1047) example_usage: Reading at address 0x5E: 94
I (1057) example_usage: Reading at address 0x5F: 95
I (1057) example_usage: Reading at address 0x60: 96
I (1067) example_usage: Reading at address 0x61: 97
I (1067) example_usage: Reading at address 0x62: 98
I (1077) example_usage: Reading at address 0x63: 99
I (1077) example_usage: Reading at address 0x64: 100
I (1087) example_usage: Reading at address 0x65: 101
I (1097) example_usage: Reading at address 0x66: 102
I (1097) example_usage: Reading at address 0x67: 103
I (1107) example_usage: Reading at address 0x68: 104
I (1107) example_usage: Reading at address 0x69: 105
I (1117) example_usage: Reading at address 0x6A: 106
I (1117) example_usage: Reading at address 0x6B: 107
I (1127) example_usage: Reading at address 0x6C: 108
I (1127) example_usage: Reading at address 0x6D: 109
I (1137) example_usage: Reading at address 0x6E: 110
I (1147) example_usage: Reading at address 0x6F: 111
I (1147) example_usage: Reading at address 0x70: 112
I (1157) example_usage: Reading at address 0x71: 113
I (1157) example_usage: Reading at address 0x72: 114
I (1167) example_usage: Reading at address 0x73: 115
I (1167) example_usage: Reading at address 0x74: 116
I (1177) example_usage: Reading at address 0x75: 117
I (1187) example_usage: Reading at address 0x76: 118
I (1187) example_usage: Reading at address 0x77: 119
I (1197) example_usage: Reading at address 0x78: 120
I (1197) example_usage: Reading at address 0x79: 121
I (1207) example_usage: Reading at address 0x7A: 122
I (1207) example_usage: Reading at address 0x7B: 123
I (1217) example_usage: Reading at address 0x7C: 124
I (1217) example_usage: Reading at address 0x7D: 125
I (1227) example_usage: Reading at address 0x7E: 126
I (1237) example_usage: Reading at address 0x7F: 127
```
