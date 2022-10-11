/*
 * Copyright (c) 2022, Mezael Docoy
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "at24cx_i2c.h" 
#include "at24cx_i2c_hal.h" 

#include "stdio.h"

void at24cx_i2c_device_register(at24cx_dev_t *dev, uint16_t _dev_chip, uint8_t _i2c_addres){
    dev->dev_chip = _dev_chip;
    dev->byte_size = (128 * _dev_chip) - 1;
    dev->i2c_addres = _i2c_addres;
    dev->status = 0;
    if (at24cx_i2c_hal_test(dev->i2c_addres) == AT24CX_OK){
        dev->status = 1;
    }
    printf("Device registered. Status: %s, Chip: AT24C%d, Address: 0x%02X, Size: %d\n", dev->status ? "Active" : "Inactive",
                                                           dev->dev_chip,
                                                           dev->i2c_addres,
                                                           dev->byte_size);
}

at24cx_err_t at24cx_i2c_byte_write(at24cx_dev_t dev, at24cx_writedata_t dt)
{
    at24cx_err_t err;
    uint8_t data[3];
    data[0] = dt.address >> 8; 
    data[1] = dt.address & 0xFF;
    data[2] = dt.data;

    if(!dev.status) return AT24CX_NOT_DETECTED;
    if(dt.address > dev.byte_size) return AT24CX_INVALID_ADDRESS;

    err = at24cx_i2c_hal_write(dev.i2c_addres, data, sizeof(data));
    at24cx_i2c_hal_ms_delay(AT24CX_WRITE_CYCLE_DELAY); 
    
    return err;
}

at24cx_err_t at24cx_i2c_byte_read(at24cx_dev_t dev, at24cx_writedata_t *dt)
{
    at24cx_err_t err;
    uint8_t reg[2];
    uint8_t data;
    reg[0] = dt->address >> 8;
    reg[1] = dt->address & 0xFF;

    if(!dev.status) return AT24CX_NOT_DETECTED;
    if(dt->address > dev.byte_size) return AT24CX_INVALID_ADDRESS;

    err = at24cx_i2c_hal_read(dev.i2c_addres, reg, sizeof(reg), &data, 1);
    dt->data = data;
    
    return err;
}

at24cx_err_t at24cx_i2c_current_address_read(at24cx_dev_t dev, at24cx_writedata_t *dt)
{
    at24cx_err_t err;
    uint8_t data;
    err = at24cx_i2c_hal_read(dev.i2c_addres, 0, 0, &data, 1);
    dt->data = data;

    return err;
}