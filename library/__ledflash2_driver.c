/*

    __ledflash2_driver.c

----------------------------------------------------------------------------- */

#include "__ledflash2_driver.h"
#include "__ledflash2_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __LEDFLASH2_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _LEDFLASH2_MODE_OFF = 0x00;
const uint8_t _LEDFLASH2_MODE_FLASH = 0x01;
const uint8_t _LEDFLASH2_MODE_TORCH = 0x02;


const uint8_t _LEDFLASH2_CUR_100 = 0x00;
const uint8_t _LEDFLASH2_CUR_90 = 0x01;
const uint8_t _LEDFLASH2_CUR_80 = 0x02;
const uint8_t _LEDFLASH2_CUR_70 = 0x03;
const uint8_t _LEDFLASH2_CUR_63 = 0x04;
const uint8_t _LEDFLASH2_CUR_56 = 0x05;
const uint8_t _LEDFLASH2_CUR_50 = 0x06;
const uint8_t _LEDFLASH2_CUR_44 = 0x07;
const uint8_t _LEDFLASH2_CUR_39 = 0x08;
const uint8_t _LEDFLASH2_CUR_35 = 0x09;
const uint8_t _LEDFLASH2_CUR_31 = 0x0A;
const uint8_t _LEDFLASH2_CUR_28 = 0x0B;
const uint8_t _LEDFLASH2_CUR_25 = 0x0C;
const uint8_t _LEDFLASH2_CUR_22 = 0x0D;
const uint8_t _LEDFLASH2_CUR_20 = 0x0E;
const uint8_t _LEDFLASH2_CUR_18 = 0x0F;

const uint8_t _LEDFLASH2_FTMR_1250 = 0xE0;
const uint8_t _LEDFLASH2_FTMR_1093 = 0xC0;
const uint8_t _LEDFLASH2_FTMR_937 = 0xA0;
const uint8_t _LEDFLASH2_FTMR_781 = 0x80;
const uint8_t _LEDFLASH2_FTMR_625 = 0x60;
const uint8_t _LEDFLASH2_FTMR_468 = 0x40;
const uint8_t _LEDFLASH2_FTMR_312 = 0x20;
const uint8_t _LEDFLASH2_FTMR_156 = 0x00;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __LEDFLASH2_DRV_SPI__

void ledflash2_spiDriverInit(T_LEDFLASH2_P gpioObj, T_LEDFLASH2_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __LEDFLASH2_DRV_I2C__

void ledflash2_i2cDriverInit(T_LEDFLASH2_P gpioObj, T_LEDFLASH2_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    ledflash2_setMode(_LEDFLASH2_MODE_OFF, 0, 0);
}

#endif
#ifdef   __LEDFLASH2_DRV_UART__

void ledflash2_uartDriverInit(T_LEDFLASH2_P gpioObj, T_LEDFLASH2_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif


/* ----------------------------------------------------------- IMPLEMENTATION */


uint8_t ledflash2_readRegister(uint8_t regAddress)
{
    uint8_t retVal;
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,&regAddress,1,END_MODE_RESTART);
    hal_i2cRead(_slaveAddress,&retVal,1,END_MODE_STOP);
    return retVal;
}

void ledflash2_writeRegister(uint8_t regAddress, uint8_t regData)
{
    uint8_t dataIn [2];
    dataIn [0] = regAddress;
    dataIn [1] = regData;
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress,&dataIn,2,END_MODE_STOP);
}

void ledflash2_setMode(uint8_t mode, uint8_t intensity, uint8_t flashDuration)
{
    uint8_t writeData;

    if (mode == _LEDFLASH2_MODE_OFF)
    {
        ledflash2_writeRegister(0x00, 0x00);
        
        hal_gpio_anSet(0);
        hal_gpio_rstSet(0);
        hal_gpio_pwmSet(0);
        hal_gpio_intSet(0);
    }
    else if (mode == _LEDFLASH2_MODE_FLASH)
    {
        writeData = 0x10;
        writeData |= intensity;
        writeData |= flashduration;
        ledflash2_writeRegister(0x00, 0x08);
		ledflash2_writeRegister(0x02, 0x00);
        ledflash2_writeRegister(0x01, writeData);

        hal_gpio_anSet(0);
        hal_gpio_rstSet(1);
        hal_gpio_pwmSet(1);
        hal_gpio_intSet(0);
    }
    else if (mode == _LEDFLASH2_MODE_TORCH)
    {
        writeData = 0x10;
        writeData |= intensity;

        ledflash2_writeRegister(0x00, 0x08);
        ledflash2_writeRegister(0x02, writeData);
    
        hal_gpio_anSet(0);
        hal_gpio_rstSet(1);
        hal_gpio_pwmSet(0);
        hal_gpio_intSet(1);
    }
}

void ledflash2_toggleFlashInhibit(uint8_t pinState)
{
    hal_gpio_anSet(pinState);
}


/* -------------------------------------------------------------------------- */
/*
  __ledflash2_driver.c

    This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.

----------------------------------------------------------------------------- */