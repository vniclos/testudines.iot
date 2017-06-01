#ifndef _STD_DEFINES_H
#define _SDT_DEFINES_H
#define MOD_WEB_Title "Testudines.IOT VIVARIUM CONTROLLER"
#define MOD_WEB_TitleSub "Steep 05 -Test 05 - Integration of "
#define MOD_WEB_text "ESP-12E, With wifi, web, reset factory button, DHT22, clock DS1307 RTC and 4 relays module"


//----------------------------------------------
// HARDWARE MOUDLE PINS
//----------------------------------------------
#define MOD_PIN_LED_ESP 13       // internal led of ESP-12
#define MOD_PIN_RESET 16         // Reset factory button
#define MOD_PIN_DHT22 2          // Sensor temperature humidity
#define MOD_PIN_CLOCK_I2C_SLC 4  // CLOCK RTC PIN SLC
#define MOD_PIN_CLOCK_I2C_SDA 0  // CLOCK RTC PIN SDA
#define MOD_PIN_RELE_0 5         // RELAY 0 PIN
#define MOD_PIN_RELE_1 14        // RELAY 1 PIN
#define MOD_PIN_RELE_2 12        // RELAY 2 PIN
#define MOD_PIN_RELE_3 10        // RELAY 3 PIN no usar 13 es el blue led
// remember vcc clock and relay go to 5v
//-----------------------------------------------
// HARDWARE OTHER VALUES
//-----------------------------------------------

#define MOD_SNS_DHTTYPE DHT22
//----------------------------------------------
// INTERVALS
//----------------------------------------------
// for do large live and eficiency
#define INTERVAL_RELAY 5000
#define INTERVAL_DHT22 5000
//----------------------------------------------
// DEBUG
// ---------------------------------------------
// For compile with serial debug
// rename adding  _ at end for compile
// without debug options
// Example STD_DEBUG_SNS_DHT  chante to 
// STD_DEBUG_SNS_DHT_
// ---------------------------------------------
// DEBUG TO SERIAL PORT AND SOME RESET VALUES
#define STD_DEBUG                  // OPEN SERIAL PORT
#define STD_DEBUG_SNS_DHT_          // SENSOR DHT22
#define STD_DEBUG_ACT_RELAY        // RELAY
#define STD_DEBUG_SNS_CLK_          // CLOK
#define STD_DEBUG_SNS_CLK_RESET    // RESSET DATE TIME ON SETUP
#define STD_DEBUG_SNS_CLK_YY 2017  // YEAR
#define STD_DEBUG_SNS_CLK_MM 7     // MM MONTH
#define STD_DEBUG_SNS_CLK_DD 1     // DAY
#define STD_DEBUG_SNS_CLK_HH 1     // HOUR
#define STD_DEBUG_SNS_CLK_MN 1     // MN minute
#endif

