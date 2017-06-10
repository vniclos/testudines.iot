#ifndef _STD_DEFINES_H
#define _SDT_DEFINES_H
#define MOD_WEB_Title "Testudines.iot -Vivarium Controller"
#define MOD_WEB_TitleSub "Steep 03- TEST 03 - Integration of: "
#define MOD_WEB_text "ESP-12E, with wifi, web, reset button and DHT22 (Temp-Hum)"


//----------------------------------------------
// HARDWARE MOUDLE PINS
//----------------------------------------------
#define MOD_PIN_LED_ESP 13       // internal led of ESP-12
#define MOD_PIN_RESET 16         // Reset factory button
#define MOD_PIN_DHT22 2          // Sensor temperature humidity

// remember vcc clock and relay go to 5v
//-----------------------------------------------
// HARDWARE OTHER VALUES
//-----------------------------------------------

#define MOD_SNS_DHTTYPE DHT22
//----------------------------------------------
// INTERVALS
//----------------------------------------------
// for do large live and eficiency

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
#define STD_DEBUG_SNS_DHT          // SENSOR DHT22

#endif

