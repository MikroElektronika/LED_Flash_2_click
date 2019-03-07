/*

    __ledflash2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __ledflash2_driver.h
@brief    Led_Flash_2 Driver
@mainpage Led_Flash_2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   LEDFLASH2
@brief      Led_Flash_2 Click Driver
@{

| Global Library Prefix | **LEDFLASH2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2017.**      |
| Developer             | **Djordje Rosic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _LEDFLASH2_H_
#define _LEDFLASH2_H_

/** 
 * @macro T_LEDFLASH2_P
 * @brief Driver Abstract type 
 */
#define T_LEDFLASH2_P    const uint8_t*

/** @defgroup LEDFLASH2_COMPILE Compilation Config */              /** @{ */

//  #define   __LEDFLASH2_DRV_SPI__                            /**<     @macro __LEDFLASH2_DRV_SPI__  @brief SPI driver selector */
   #define   __LEDFLASH2_DRV_I2C__                            /**<     @macro __LEDFLASH2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __LEDFLASH2_DRV_UART__                           /**<     @macro __LEDFLASH2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup LEDFLASH2_VAR Variables */                           /** @{ */

extern const uint8_t _LEDFLASH2_MODE_OFF;     /**<  Turn the LEDs off */
extern const uint8_t _LEDFLASH2_MODE_FLASH;   /**<  Set the LEDs into flash mode */
extern const uint8_t _LEDFLASH2_MODE_TORCH;   /**<  Set the LEDs into torch mode */



extern const uint8_t _LEDFLASH2_CUR_100;  /**<  Set the LED current to 100% */
extern const uint8_t _LEDFLASH2_CUR_90;   /**<  Set the LED current to 90% */
extern const uint8_t _LEDFLASH2_CUR_80;   /**<  Set the LED current to 80% */
extern const uint8_t _LEDFLASH2_CUR_70;   /**<  Set the LED current to 70% */
extern const uint8_t _LEDFLASH2_CUR_63;   /**<  Set the LED current to 63% */
extern const uint8_t _LEDFLASH2_CUR_56;   /**<  Set the LED current to 56% */
extern const uint8_t _LEDFLASH2_CUR_50;   /**<  Set the LED current to 50% */
extern const uint8_t _LEDFLASH2_CUR_44;   /**<  Set the LED current to 44% */
extern const uint8_t _LEDFLASH2_CUR_39;   /**<  Set the LED current to 39% */
extern const uint8_t _LEDFLASH2_CUR_35;   /**<  Set the LED current to 35% */
extern const uint8_t _LEDFLASH2_CUR_31;   /**<  Set the LED current to 31% */
extern const uint8_t _LEDFLASH2_CUR_28;   /**<  Set the LED current to 28% */
extern const uint8_t _LEDFLASH2_CUR_25;   /**<  Set the LED current to 25% */
extern const uint8_t _LEDFLASH2_CUR_22;   /**<  Set the LED current to 22% */
extern const uint8_t _LEDFLASH2_CUR_20;   /**<  Set the LED current to 20% */
extern const uint8_t _LEDFLASH2_CUR_18;   /**<  Set the LED current to 18% */

extern const uint8_t _LEDFLASH2_FTMR_1250;  /**<  Set the flash duration to 1250 ms */
extern const uint8_t _LEDFLASH2_FTMR_1093;  /**<  Set the flash duration to 1093 ms */
extern const uint8_t _LEDFLASH2_FTMR_937;   /**<  Set the flash duration to 937 ms */
extern const uint8_t _LEDFLASH2_FTMR_781;   /**<  Set the flash duration to 781 ms */
extern const uint8_t _LEDFLASH2_FTMR_625;   /**<  Set the flash duration to 625 ms */
extern const uint8_t _LEDFLASH2_FTMR_468;   /**<  Set the flash duration to 468 ms */
extern const uint8_t _LEDFLASH2_FTMR_312;   /**<  Set the flash duration to 312 ms */
extern const uint8_t _LEDFLASH2_FTMR_156;   /**<  Set the flash duration to 156 ms */


                                                                       /** @} */
/** @defgroup LEDFLASH2_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup LEDFLASH2_INIT Driver Initialization */              /** @{ */

#ifdef   __LEDFLASH2_DRV_SPI__
void ledflash2_spiDriverInit(T_LEDFLASH2_P gpioObj, T_LEDFLASH2_P spiObj);
#endif
#ifdef   __LEDFLASH2_DRV_I2C__
void ledflash2_i2cDriverInit(T_LEDFLASH2_P gpioObj, T_LEDFLASH2_P i2cObj, uint8_t slave);
#endif
#ifdef   __LEDFLASH2_DRV_UART__
void ledflash2_uartDriverInit(T_LEDFLASH2_P gpioObj, T_LEDFLASH2_P uartObj);
#endif

                                                                       /** @} */
/** @defgroup LEDFLASH2_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Read register
 *
 * @param[in] regAddress       Register address
 * @retval                     Read data
 *
 * Generic read function reads raw data from any register.
 *
 */
uint8_t ledflash2_readRegister(uint8_t regAddress);

/**
 * @brief Write register
 *
 * @param[in] regAddress       Register address
 * @param[in] regData          Data to write
 *
 * Generic write function writes data into any register.
 *
 */
void ledflash2_writeRegister(uint8_t regAddress, uint8_t regData);

/**
 * @brief Set mode
 *
 * @param[in] mode              Mode to select
 * @param[in] intensity         Led intensity
 * @param[in] flashDuration     Flash duration
 *
 * Control function that sets the click into one of the three available modes.
 * OFF mode requires no additional parameters, and will ignore intensity and
 * duration. 
 * Flash mode will set both the intensity and duration, and will set them to
 * default value (100% intensity, 156 duration) if 0 values are passed instead.
 * Torch mode only requires intensity parameter. It will ignore duration
 * parameter, and will set the intensity to default (100 %) if intensity 
 * parameter is 0.
 */
void ledflash2_setMode(uint8_t mode, uint8_t intensity, uint8_t flashDuration);

/**
 * @brief Toggle flash inhibit function
 *
 * @param[in] pinState       Flash inhibit on or off
 *
 * This function will set the flash inhibit pin to either 1 or 0. It should be
 * used when click is in flash mode, to reduce the flash intensity.
 */
void ledflash2_toggleFlashInhibit(uint8_t pinState);
                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Led_Flash_2_STM.c
    @example Click_Led_Flash_2_TIVA.c
    @example Click_Led_Flash_2_CEC.c
    @example Click_Led_Flash_2_KINETIS.c
    @example Click_Led_Flash_2_MSP.c
    @example Click_Led_Flash_2_PIC.c
    @example Click_Led_Flash_2_PIC32.c
    @example Click_Led_Flash_2_DSPIC.c
    @example Click_Led_Flash_2_AVR.c
    @example Click_Led_Flash_2_FT90x.c
    @example Click_Led_Flash_2_STM.mbas
    @example Click_Led_Flash_2_TIVA.mbas
    @example Click_Led_Flash_2_CEC.mbas
    @example Click_Led_Flash_2_KINETIS.mbas
    @example Click_Led_Flash_2_MSP.mbas
    @example Click_Led_Flash_2_PIC.mbas
    @example Click_Led_Flash_2_PIC32.mbas
    @example Click_Led_Flash_2_DSPIC.mbas
    @example Click_Led_Flash_2_AVR.mbas
    @example Click_Led_Flash_2_FT90x.mbas
    @example Click_Led_Flash_2_STM.mpas
    @example Click_Led_Flash_2_TIVA.mpas
    @example Click_Led_Flash_2_CEC.mpas
    @example Click_Led_Flash_2_KINETIS.mpas
    @example Click_Led_Flash_2_MSP.mpas
    @example Click_Led_Flash_2_PIC.mpas
    @example Click_Led_Flash_2_PIC32.mpas
    @example Click_Led_Flash_2_DSPIC.mpas
    @example Click_Led_Flash_2_AVR.mpas
    @example Click_Led_Flash_2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __ledflash2_driver.h

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