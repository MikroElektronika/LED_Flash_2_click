/*
Example for LED_Flash_2 Click

    Date          : Feb 2018.
    Author        : MikroE Team

Test configuration dsPIC :
    
    MCU                : P33FJ256GP710A
    Dev. Board         : EasyPIC Fusion v7
    dsPIC Compiler ver : v7.0.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes pins, i2c peripheral, and logger.
- Application Initialization - Initializes driver, and sets the click into "OFF"
mode.
- Application Task - This function will demonstrate how to use the flash mode,
and the torch mode, with different power settings. It will then turn the click
off.

IMPORTANT NOTE: LED lights can be very bright, even on lowest power settings.
Avoid looking directly into the light when click is in operation.

*/

#include "Click_Led_Flash_2_types.h"
#include "Click_Led_Flash_2_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_OUTPUT );
    
    mikrobus_i2cInit( _MIKROBUS1, &_LEDFLASH2_I2C_CFG[0] );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );

    Delay_ms(100);
}

void applicationInit()
{
    ledflash2_i2cDriverInit( (T_LEDFLASH2_P)&_MIKROBUS1_GPIO, (T_LEDFLASH2_P)&_MIKROBUS1_I2C, 0x5A );
    ledflash2_setMode(_LEDFLASH2_MODE_OFF, 0, 0);
    mikrobus_logWrite("Initialized...", _LOG_LINE);
}

void applicationTask()
{
    Delay_ms(1000);
    mikrobus_logWrite("Do not look directly into the led lights.", _LOG_LINE);
    mikrobus_logWrite("Triggering flash in 5...", _LOG_LINE);
    Delay_ms(1000);
    mikrobus_logWrite("4...", _LOG_LINE);
    Delay_ms(1000);
    mikrobus_logWrite("3...", _LOG_LINE);
    Delay_ms(1000);
    mikrobus_logWrite("2...", _LOG_LINE);
    Delay_ms(1000);
    mikrobus_logWrite("1...", _LOG_LINE);
    Delay_ms(1000);
    mikrobus_logWrite("Cheese!", _LOG_LINE);
    
    ledflash2_setMode(_LEDFLASH2_MODE_FLASH, _LEDFLASH2_CUR_100, _LEDFLASH2_FTMR_312);
    
    Delay_ms(350);
    ledflash2_setMode(_LEDFLASH2_MODE_OFF, 0, 0);
    Delay_ms(2000);
    mikrobus_logWrite("Switching to the torch mode in a moment...", _LOG_LINE);
    Delay_ms(2000);
    ledflash2_setMode(_LEDFLASH2_MODE_TORCH, _LEDFLASH2_CUR_100, 0);
    Delay_ms(5000);
    mikrobus_logWrite("Dimming the torch light...", _LOG_LINE);
    ledflash2_setMode(_LEDFLASH2_MODE_TORCH, _LEDFLASH2_CUR_18, 0);
    Delay_ms(5000);
    mikrobus_logWrite("Switching off...", _LOG_LINE);
    ledflash2_setMode(_LEDFLASH2_MODE_OFF, 0, 0);
}

void main()
{
    systemInit();
    applicationInit();

    applicationTask();
}
