![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Led_Flash_2 Click

- **CIC Prefix**  : LEDFLASH2
- **Author**      : Djordje Rosic
- **Verison**     : 1.0.0
- **Date**        : Nov 2017

---

### Software Support

We provide a library for the Led_Flash_2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2219/led-flash-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library for LED Flash 2 click contains generic read / write functions. It also 
contains control function (setMode), that can set click into any of the three possible modes 
of operation, as well as a function that can toggle Flash inhibit pin on/off.

Key functions :

- ``` uint8_t ledflash2_readRegister(uint8_t regAddress) ``` - generic read register function
- ``` void ledflash2_writeRegister(uint8_t regAddress, uint8_t regData) ``` - generic write register function
- ``` ledflash2_setMode(_LEDFLASH2_MODE_FLASH, _LEDFLASH2_CUR_100, _LEDFLASH2_FTMR_312); ``` - sets the operation mode
- ``` void ledflash2_toggleFlashInhibit(uint8_t pinState) ``` - toggles the Flash inhibit pin on/off

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes pins, i2c peripheral, and logger.
- Application Initialization - Initializes driver, and sets the click into "OFF"
  mode.
- Application Task - (Code snippet) This function will demonstrate how to use the flash mode,
  and the torch mode, with different power settings. It will then turn the click
  off.

IMPORTANT NOTE: LED lights can be very bright, even on lowest power settings.
Avoid looking directly into the light when click is in operation.


```.c
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
```


The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2219/led-flash-2-click) page.

Other mikroE Libraries used in the example:

- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
