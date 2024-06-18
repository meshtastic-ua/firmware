// For OLED I2C
#define I2C_SDA 21
#define I2C_SCL 22

// GPS
#undef GPS_RX_PIN
#undef GPS_TX_PIN
#define GPS_RX_PIN 12
#define GPS_TX_PIN 2
#define GPS_UBLOX

#define BUTTON_PIN 39  // The middle button GPIO on the T-Beam
#define BATTERY_PIN 35 // A battery voltage measurement pin, voltage divider connected here to measure battery voltage
#define ADC_CHANNEL ADC1_GPIO35_CHANNEL
#define ADC_MULTIPLIER 1.85 // (R1 = 470k, R2 = 680k)

#define LORA_DIO0 26  // a No connect on the SX1262/SX1268 module
#define LORA_RESET 23 // RST for SX1276, and for SX1262/SX1268
#define LORA_DIO1 33  // IRQ for SX1262/SX1268
#define LORA_DIO2 32  // BUSY for SX1262/SX1268
#define LORA_DIO3     // Not connected on PCB, but internally on the TTGO SX1262/SX1268, if DIO3 is high the TXCO is enabled

#define LORA_SCK 5
#define LORA_MISO 19
#define LORA_MOSI 27
#define LORA_CS 18


#define USE_SX1268
#define NiceRF
#define SX126X_MAX_POWER 22

// common pinouts for SX126X modules
#define SX126X_CS 18 // NSS for SX126X
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET

 //ST7735S TFT LCD
#define HAS_SCREEN 1
#define ST7735S 1 // there are different (sub-)versions of ST7735
#define ST7735_CS 15
#define ST7735_RS 0  // DC
#define ST7735_SDA 13 // MOSI
#define ST7735_SCK 14
#define ST7735_RESET 25
#define ST7735_MISO -1
#define ST7735_BUSY -1
#define ST7735_BL 26
#define ST7735_SPI_HOST HSPI_HOST // SPI2_HOST for S3, auto may work too
#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 16000000
#define TFT_HEIGHT 160
#define TFT_WIDTH 128
#define TFT_OFFSET_X 0
#define TFT_OFFSET_Y 0
#define TFT_INVERT false
#define SCREEN_ROTATE
#define SCREEN_TRANSITION_FRAMERATE 1 // fps
#define DISPLAY_FORCE_SMALL_FONTS