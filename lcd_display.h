// lcd_display.h
#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <Adafruit_SSD1306.h>

void initLCD();
void updateLCD(long heartRate);

extern Adafruit_SSD1306 display;

#endif
