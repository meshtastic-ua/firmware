// For OLED LCD
#define I2C_SDA 21
#define I2C_SCL 22
// GPS
#undef GPS_RX_PIN
#undef GPS_TX_PIN
// #define GPS_TX_PIN 12 // not connected
// #define GPS_RX_PIN 15
#define GPS_UBLOX
#define BUTTON_PIN 39 // The middle button GPIO on the T-Beam
// #define BATTERY_PIN 35 // A battery voltage measurement pin, voltage divider connected here to measure battery voltage
#define ADC_CHANNEL ADC1_GPIO35_CHANNEL
#define ADC_MULTIPLIER 1.85 // (R1 = 470k, R2 = 680k)
#define EXT_PWR_DETECT 4    // Pin to detect connected external power source for LILYGO® TTGO T-Energy T18 and other DIY boards
// #define EXT_NOTIFY_OUT 12   // Overridden default pin to use for Ext Notify Module (#975).
#define LED_PIN 2     // add status LED (compatible with core-pcb and DIY targets)
#define LORA_DIO0     // a No connect on the SX1262/SX1268 module
#define LORA_RESET 27 // RST for SX1276, and for SX1262/SX1268
#define LORA_DIO1 12  // IRQ for SX1262/SX1268
#define LORA_DIO2 14  // BUSY for SX1262/SX1268
#define LORA_DIO3     // Not connected on PCB, but internally on the TTGO SX1262/SX1268, if DIO3 is high the TXCO is enabled
// #define RF95_SCK 18
// #define RF95_MISO 19
// #define RF95_MOSI 23
// #define RF95_NSS 5
#define LORA_SCK 18
#define LORA_MISO 19
#define LORA_MOSI 23
#define LORA_CS 5
// supported modules list
// #define USE_RF95 // RFM95/SX127x
// #define USE_SX1262
// #define USE_SX1268
// #define USE_LLCC68
// #define SX126X_E22
// supported modules list
// #define USE_RF95 // RFM95/SX127x
#define USE_SX1262
#define USE_SX1268
// #define USE_LLCC68
// common pinouts for SX126X modules
#define SX126X_CS 18 // NSS for SX126X
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET
#define SX126X_RXEN 32
#define SX126X_TXEN 33
// RX/TX for RFM95/SX127x
// #define RF95_RXEN 32
// #define RF95_TXEN 33
#ifdef EBYTE_E22
// Internally the TTGO module hooks the SX126x-DIO2 in to control the TX/RX switch
// (which is the default for the sx1262interface code)
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#endif