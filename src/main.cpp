#include <SPI.h>
#include <Wire.h>
#include <pinout.h>
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include <Arduino_GFX_Library.h>

SPIClass TFT_SPI(VSPI);
Adafruit_NeoPixel rgbled(2, PIN_RGB_CTRL, NEO_GRB + NEO_KHZ800);
int brightness = 0;
bool direction;
Arduino_ESP32SPI bus(PIN_LCD_DC, GFX_NOT_DEFINED, PIN_LCD_SCL, PIN_LCD_SDA, GFX_NOT_DEFINED, HSPI, false);
Arduino_ST7789 gfx(&bus, PIN_LCD_RST, 0 /* rotation */, true /* IPS */, 240, 480, 0, 0);

void setup()
{
    pinMode(PIN_QI_EN, OUTPUT);
    pinMode(PIN_LCD_RST, OUTPUT);
    pinMode(PIN_LCD_DC, OUTPUT);
    pinMode(PIN_LCD_BL, OUTPUT);
    pinMode(PIN_TOUCH_RST, OUTPUT);

    pinMode(PIN_QI_STAT, INPUT);
    pinMode(PIN_CHG_STAT, INPUT);
    pinMode(PIN_TOUCH_INT, INPUT);

    pinMode(PIN_BAT_VOLT, ANALOG);

    digitalWrite(PIN_QI_EN, LOW);   // Enable Wireless Charging
    digitalWrite(PIN_LCD_BL, HIGH); // LCD Backlight ON
    gfx.begin(40000000);
    rgbled.begin();
    rgbled.setBrightness(100);
}

void loop()
{
    brightness += direction ? 1 : -1;
    if (brightness >= 255)
    {
        direction = false;
    }
    else if (brightness <= 0)
    {
        direction = true;
    }

    if (digitalRead(PIN_CHG_STAT) == LOW)
    {
        rgbled.setPixelColor(0, brightness, brightness, brightness);
    }
    else
    {
        rgbled.setPixelColor(0, 0, 0, 0);
    }

    if (digitalRead(PIN_QI_STAT) == LOW)
    {
        rgbled.setPixelColor(1, brightness, brightness, brightness);
    }
    else
    {
        rgbled.setPixelColor(1, 0, 0, 0);
    }
    rgbled.show();
    gfx.fillScreen(WHITE);
    delay(10);
    gfx.fillScreen(BLACK);
}