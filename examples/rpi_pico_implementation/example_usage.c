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

    //Register device
    device_register(&eeprom_1, 512, I2C_ADDRESS_AT24CX);
    
    //Check if eeprom_1 is active
    printf("\neeprom_1 is %s\n", eeprom_1.status ? "detected" : "not detected");

    printf("\nWrite byte demo: This will write value 0 at address 0x00, 1 at address 0x01 and so on\n\n");
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
    
    printf("\nRead byte demo: Obtain values from addresses 0x00 to 0x09, values should be from 0 to 9 respectively\n\n");
    for(int i=0;i<10;i++)
    {
        at24cx_writedata_t dt = {
            .address = i,
        };
        if (at24cx_i2c_byte_read(eeprom_1, &dt) == AT24CX_OK) printf("Reading at address 0x%02X: %d\n", dt.address, dt.data);
        else printf("Device read error!\n");
        //at24cx_i2c_hal_ms_delay(5); // Self-time write cycle
    }

    printf("\nRead byte at current address demo: Obtain values from addresses\n");
    printf("Overwrite address 0x04 with the same value to set the current address which will be 0x05\n\n");
    at24cx_writedata_t dt = {
            .address = 0x04,
            .data = 4
        };
    if (at24cx_i2c_byte_write(eeprom_1, dt) == AT24CX_OK) printf("Writing at address 0x%02X: %d\n", dt.address, dt.data);
    else printf("Device write error!\n");

    printf("\nNow read current address which is 0x05, value should be 5\n");
    if (at24cx_i2c_current_address_read(eeprom_1, &dt) == AT24CX_OK) printf("Reading at current address: %d\n", dt.data);
    else printf("Device read error!\n");
}
