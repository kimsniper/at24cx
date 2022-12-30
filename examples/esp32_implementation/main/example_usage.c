#include <stdio.h>
#include "esp_log.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//AT24CX components
#include "at24cx_i2c.h"
#include "at24cx_i2c_hal.h"

//Change this macro based on your chip size
#define AT24CX_SIZE     256

static const char *TAG = "example_usage";

at24cx_dev_t eeprom_1;

void app_main(void)
{    
    at24cx_i2c_hal_init();

    ESP_LOGI(TAG, "Initializing AT24CX. . .");

    //Register device
    at24cx_i2c_device_register(&eeprom_1, AT24CX_SIZE, I2C_ADDRESS_AT24CX);
    
    //Check if eeprom_1 is active
    ESP_LOGI(TAG, "eeprom_1 is %s", eeprom_1.status ? "detected" : "not detected");

    ESP_LOGI(TAG, "Write byte demo: This will write value 0 at address 0x00, 1 at address 0x01 and so on");
    for(int i=0;i<10;i++)
    {
        at24cx_writedata_t dt = {
            .address = i,
            .data = i
        };
        
        if (at24cx_i2c_byte_write(eeprom_1, dt) == AT24CX_OK) ESP_LOGI(TAG, "Writing at address 0x%02X: %d", dt.address, dt.data);
        else ESP_LOGE(TAG, "Device write error!");
    }
    
    ESP_LOGI(TAG, "Read byte demo: Obtain values from addresses 0x00 to 0x09, values should be from 0 to 9 respectively");
    for(int i=0;i<10;i++)
    {
        at24cx_writedata_t dt = {
            .address = i,
        };
        if (at24cx_i2c_byte_read(eeprom_1, &dt) == AT24CX_OK) ESP_LOGI(TAG, "Reading at address 0x%02X: %d", dt.address, dt.data);
        else ESP_LOGE(TAG, "Device read error!");
    }

    ESP_LOGI(TAG, "Read byte at current address demo: Obtain values from addresses");
    ESP_LOGI(TAG, "Overwrite address 0x04 with the same value to set the current address which will be 0x05");
    at24cx_writedata_t dt = {
            .address = 0x04,
            .data = 4
        };
    if (at24cx_i2c_byte_write(eeprom_1, dt) == AT24CX_OK) ESP_LOGI(TAG, "Writing at address 0x%02X: %d", dt.address, dt.data);
    else ESP_LOGE(TAG, "Device write error!");

    ESP_LOGI(TAG, "Now read current address which is 0x05, value should be 5");
    if (at24cx_i2c_current_address_read(eeprom_1, &dt) == AT24CX_OK) ESP_LOGI(TAG, "Reading at current address: %d", dt.data);
    else ESP_LOGE(TAG, "Device read error!");

    ESP_LOGI(TAG, "Page write demo: Write %d bytes at once from 0x00 to 0x%02X", eeprom_1.page_write_size, eeprom_1.page_write_size-1);
    at24cx_writedata_t dt_multi;
    dt_multi.address = 0;
    for(int i=0;i<eeprom_1.page_write_size;i++) dt_multi.data_multi[i] = i;
    if(at24cx_i2c_page_write(eeprom_1, dt_multi) == AT24CX_OK) ESP_LOGI(TAG, "Writing %d bytes from 0x00 to 0x%02X", eeprom_1.page_write_size, eeprom_1.page_write_size-1);
    else ESP_LOGE(TAG, "Device write error!");
    ESP_LOGI(TAG, "Read %d bytes from 0x00 to 0x%02X", eeprom_1.page_write_size, eeprom_1.page_write_size-1);
    for(int i=0;i<eeprom_1.page_write_size;i++)
    {
        at24cx_writedata_t dt = {
            .address = i,
        };
        if (at24cx_i2c_byte_read(eeprom_1, &dt) == AT24CX_OK) ESP_LOGI(TAG, "Reading at address 0x%02X: %d", dt.address, dt.data);
        else ESP_LOGE(TAG, "Device read error!");
    }
}
