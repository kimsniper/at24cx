# AT24CX - ESP-IDF

AT24CX i2c library for ESP-IDF.
ESP-IDF template used for this project: https://github.com/espressif/esp-idf/tree/master/examples/peripherals/i2c/i2c_simple

## Overview

This example demonstrates usage of AT24C128/256 eeprom for reading/writing..

### Hardware Required

To run this example, you should have one ESP32, ESP32-S or ESP32-C based development board as well as a AT24C128/256 (This library works with other AT24CX variants as well). The AT24C128/256 provides 131,072/262,144 bits of serial electrically erasable and programmable read only memory (EEPROM) organized as 16,384/32,768 words of 8 bits each. The device’s cascadable feature allows up to 4 devices to share a common Two-wire bus. You can read the datasheet [here](https://ww1.microchip.com/downloads/en/devicedoc/doc0670.pdf).


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
I (321) example_usage: Initializing AT24CX. . .
Device registered. Status: Active, Chip: AT24C256, Address: 0x50, Size: 32767
I (331) example_usage: eeprom_1 is detected
I (341) example_usage: Write byte demo: This will write value 0 at address 0x00, 1 at address 0x01 and so on
I (351) example_usage: Writing at address 0x00: 0
I (351) example_usage: Writing at address 0x01: 1
I (361) example_usage: Writing at address 0x02: 2
I (361) example_usage: Writing at address 0x03: 3
I (371) example_usage: Writing at address 0x04: 4
I (371) example_usage: Writing at address 0x05: 5
I (381) example_usage: Writing at address 0x06: 6
I (391) example_usage: Writing at address 0x07: 7
I (391) example_usage: Writing at address 0x08: 8
I (401) example_usage: Writing at address 0x09: 9
I (401) example_usage: Read byte demo: Obtain values from addresses 0x00 to 0x09, values should be from 0 to 9 respectively
I (411) example_usage: Reading at address 0x00: 0
I (421) example_usage: Reading at address 0x01: 1
I (421) example_usage: Reading at address 0x02: 2
I (431) example_usage: Reading at address 0x03: 3
I (441) example_usage: Reading at address 0x04: 4
I (441) example_usage: Reading at address 0x05: 5
I (451) example_usage: Reading at address 0x06: 6
I (451) example_usage: Reading at address 0x07: 7
I (461) example_usage: Reading at address 0x08: 8
I (461) example_usage: Reading at address 0x09: 9
I (471) example_usage: Read byte at current address demo: Obtain values from addresses
I (481) example_usage: Overwrite address 0x04 with the same value to set the current address which will be 0x05
I (491) example_usage: Writing at address 0x04: 4
I (491) example_usage: Now read current address which is 0x05, value should be 5
I (501) example_usage: Reading at current address: 5
I (511) example_usage: Page write demo: Write 64 bytes at once from 0x00 to 0x3F
I (521) example_usage: Writing 64 bytes from 0x00 to 0x3F
I (521) example_usage: Read 64 bytes from 0x00 to 0x3F
I (531) example_usage: Reading at address 0x00: 0
I (531) example_usage: Reading at address 0x01: 1
I (541) example_usage: Reading at address 0x02: 2
I (541) example_usage: Reading at address 0x03: 3
I (551) example_usage: Reading at address 0x04: 4
I (551) example_usage: Reading at address 0x05: 5
I (561) example_usage: Reading at address 0x06: 6
I (561) example_usage: Reading at address 0x07: 7
I (571) example_usage: Reading at address 0x08: 8
I (571) example_usage: Reading at address 0x09: 9
I (581) example_usage: Reading at address 0x0A: 10
I (591) example_usage: Reading at address 0x0B: 11
I (591) example_usage: Reading at address 0x0C: 12
I (601) example_usage: Reading at address 0x0D: 13
I (601) example_usage: Reading at address 0x0E: 14
I (611) example_usage: Reading at address 0x0F: 15
I (611) example_usage: Reading at address 0x10: 16
I (621) example_usage: Reading at address 0x11: 17
I (621) example_usage: Reading at address 0x12: 18
I (631) example_usage: Reading at address 0x13: 19
I (631) example_usage: Reading at address 0x14: 20
I (641) example_usage: Reading at address 0x15: 21
I (651) example_usage: Reading at address 0x16: 22
I (651) example_usage: Reading at address 0x17: 23
I (661) example_usage: Reading at address 0x18: 24
I (661) example_usage: Reading at address 0x19: 25
I (671) example_usage: Reading at address 0x1A: 26
I (671) example_usage: Reading at address 0x1B: 27
I (681) example_usage: Reading at address 0x1C: 28
I (681) example_usage: Reading at address 0x1D: 29
I (691) example_usage: Reading at address 0x1E: 30
I (691) example_usage: Reading at address 0x1F: 31
I (701) example_usage: Reading at address 0x20: 32
I (711) example_usage: Reading at address 0x21: 33
I (711) example_usage: Reading at address 0x22: 34
I (721) example_usage: Reading at address 0x23: 35
I (721) example_usage: Reading at address 0x24: 36
I (731) example_usage: Reading at address 0x25: 37
I (731) example_usage: Reading at address 0x26: 38
I (741) example_usage: Reading at address 0x27: 39
I (741) example_usage: Reading at address 0x28: 40
I (751) example_usage: Reading at address 0x29: 41
I (751) example_usage: Reading at address 0x2A: 42
I (761) example_usage: Reading at address 0x2B: 43
I (771) example_usage: Reading at address 0x2C: 44
I (771) example_usage: Reading at address 0x2D: 45
I (781) example_usage: Reading at address 0x2E: 46
I (781) example_usage: Reading at address 0x2F: 47
I (791) example_usage: Reading at address 0x30: 48
I (791) example_usage: Reading at address 0x31: 49
I (801) example_usage: Reading at address 0x32: 50
I (801) example_usage: Reading at address 0x33: 51
I (811) example_usage: Reading at address 0x34: 52
I (811) example_usage: Reading at address 0x35: 53
I (821) example_usage: Reading at address 0x36: 54
I (831) example_usage: Reading at address 0x37: 55
I (831) example_usage: Reading at address 0x38: 56
I (841) example_usage: Reading at address 0x39: 57
I (841) example_usage: Reading at address 0x3A: 58
I (851) example_usage: Reading at address 0x3B: 59
I (851) example_usage: Reading at address 0x3C: 60
I (861) example_usage: Reading at address 0x3D: 61
I (861) example_usage: Reading at address 0x3E: 62
I (871) example_usage: Reading at address 0x3F: 63
```
