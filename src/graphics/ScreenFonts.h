#pragma once

#include "graphics/fonts/OLEDDisplayFontsUA.h"

#if (defined(USE_EINK) || defined(T_DECK) || defined(EINK_UA) || defined(ILI9341_DRIVER) || defined(ST7735_CS) || defined(ST7789_CS) || defined(HX8357_CS)) &&          \
    !defined(DISPLAY_FORCE_SMALL_FONTS)
// The screen is bigger so use bigger fonts
#define FONT_SMALL ArialMT_Plain_16_UA  // Height: 19
#define FONT_MEDIUM ArialMT_Plain_24_UA // Height: 28
#define FONT_LARGE ArialMT_Plain_24_UA  // Height: 28
#else
#define FONT_SMALL ArialMT_Plain_10_UA
#define FONT_MEDIUM ArialMT_Plain_16_UA
#define FONT_LARGE ArialMT_Plain_24_UA
#endif

#define _fontHeight(font) ((font)[1] + 1) // height is position 1

#define FONT_HEIGHT_SMALL _fontHeight(FONT_SMALL)
#define FONT_HEIGHT_MEDIUM _fontHeight(FONT_MEDIUM)
#define FONT_HEIGHT_LARGE _fontHeight(FONT_LARGE)