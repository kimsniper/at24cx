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

#include "at24cx_i2c_hal.h" 

//Hardware Specific Components
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"


at24cx_err_t at24cx_i2c_hal_init()
{
    int err = AT24CX_OK;

    // This example will use I2C0 on the default SDA and SCL pins (4, 5 on a Pico)
    i2c_init(i2c_default, 400 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    return err == AT24CX_OK ? AT24CX_OK :  AT24CX_ERR;
}

at24cx_err_t at24cx_i2c_hal_read(uint8_t address, uint8_t *reg, uint16_t reg_count, uint8_t *data, uint16_t data_count)
{
    int err = AT24CX_OK;

    if(i2c_write_blocking(i2c_default, address, reg, reg_count, true) != reg_count) err += AT24CX_ERR;
    if(i2c_read_blocking(i2c_default, address, data, data_count, false) != data_count) err += AT24CX_ERR;

    return err == AT24CX_OK ? AT24CX_OK :  AT24CX_ERR;
}

at24cx_err_t at24cx_i2c_hal_write(uint8_t address, uint8_t *data, uint16_t count)
{
    int err = AT24CX_OK;

    if(i2c_write_blocking(i2c_default, address, data, count, false) != count) err += AT24CX_ERR;

    return err == AT24CX_OK ? AT24CX_OK :  AT24CX_ERR;
}

at24cx_err_t at24cx_i2c_hal_test(uint8_t address)
{
    int err = AT24CX_OK;
    uint8_t test_data = 1;
    if(i2c_write_blocking(i2c_default, address, &test_data, 1, false) == PICO_ERROR_GENERIC ) err += AT24CX_ERR;

    return err == AT24CX_OK ? AT24CX_OK :  AT24CX_ERR;
}

void at24cx_i2c_hal_ms_delay(uint32_t ms) {
    sleep_ms (ms);
}