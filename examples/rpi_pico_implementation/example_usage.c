/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

//AT24CX components
#include "at24cx_i2c.h"
#include "at24cx_i2c_hal.h"
#include "dev_reg.h"

at24cx_dev_t eeprom_1;

int main() {
    stdio_init_all();
    int err;
    
    err = at24cx_i2c_hal_init();

    printf("Initializing AT24CX. . .\n");

    device_register(&eeprom_1, 65535, I2C_ADDRESS_AT24CX);
    
    //Check if eeprom_1 is active
    printf("eeprom_1 is %s\n", eeprom_1.status ? "detected" : "not detected");

    //Write byte demo
    for(int i=0;i<10;i++)
    {
        at24cx_writedata_t dt = {
            .address = i,
            .data = i
        };
        if (at24cx_i2c_byte_write(eeprom_1, dt) == AT24CX_OK) printf("Writing at address 0x%02X: %d\n", dt.address, dt.data);
        else printf("Device write error!\n");
        at24cx_i2c_hal_ms_delay(5); // Self-time write cycle
    }

    //Read byte demo
    for(int i=0;i<10;i++)
    {
        at24cx_writedata_t dt = {
            .address = i,
        };
        if (at24cx_i2c_byte_read(eeprom_1, &dt) == AT24CX_OK) printf("Reading at address 0x%02X: %d\n", dt.address, dt.data);
        at24cx_i2c_hal_ms_delay(5); // Self-time write cycle
    }
}
