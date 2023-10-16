#ifndef _H_PINOUT_
#define _H_PINOUT_

// RGB ws2812b
#define PIN_RGB_CTRL  21

// Power and charging
#define PIN_CHG_STAT  22
#define PIN_QI_STAT   19
#define PIN_QI_EN     20
#define PIN_BAT_VOLT  34

// IMU I2C
#define PIN_I2C_SCL   8
#define PIN_I2C_SDA   7

// LCD SPI
#define PIN_LCD_RST   27
#define PIN_LCD_DC    0
#define PIN_LCD_BL    4
#define PIN_LCD_CS    -1  // CS is tied low by hardware
#define PIN_LCD_SDA   14
#define PIN_LCD_SCL   13

// TOUCH I2C
#define PIN_TOUCH_INT 32
#define PIN_TOUCH_RST 33
#define PIN_TOUCH_SCL 26
#define PIN_TOUCH_SDA 25

#endif