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
I (407) example_usage: Read byte demo: Obtain values from addresses 0x00 to 0x09, values should be from 0 to 9 respectively
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
```
