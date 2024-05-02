#pragma once

#include "graphics/fonts/OLEDDisplayFontsUA.h"

#ifdef OLED_RU
#include "graphics/fonts/OLEDDisplayFontsRU.h"
#endif

#ifdef OLED_UA
#include "graphics/fonts/OLEDDisplayFontsUA.h"
#endif

#ifdef EINK_UA
#include "graphics/fonts/EInkDisplayFontsUA.h"
#endif

#ifdef TD_UA
#include "graphics/fonts/TDDisplayFontsUA.h"
#endif

// The screen is bigger so use bigger fonts
#if (defined(USE_EINK) || defined(ILI9341_DRIVER) || defined(ST7735_CS) || defined(ST7789_CS) || defined(TD_UA) || defined(EINK_UA)) &&                                \
    !defined(DISPLAY_FORCE_SMALL_FONTS)
        #define FONT_SMALL ArialMT_Plain_16_UA
        #define FONT_MEDIUM ArialMT_Plain_24_UA 
        #define FONT_LARGE ArialMT_Plain_24_UA
#else
        #define FONT_SMALL ArialMT_Plain_10_UA
        #define FONT_MEDIUM ArialMT_Plain_16_UA 
        #define FONT_LARGE ArialMT_Plain_24_UA
#endif

#define fontHeight(font) ((font)[1] + 1) // height is position 1

#define FONT_HEIGHT_SMALL fontHeight(FONT_SMALL)
#define FONT_HEIGHT_MEDIUM fontHeight(FONT_MEDIUM)
#define FONT_HEIGHT_LARGE fontHeight(FONT_LARGE)
