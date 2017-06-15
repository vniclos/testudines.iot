#ifndef _STD_DEFINES_H
#define _SDT_DEFINES_H
#define MOD_WEB_Title "Testudines.iot -Vivarium Controller"
#define MOD_WEB_TitleSub "Steep 02- TEST 02 - Integration of: "
#define MOD_WEB_text "ESP-12E, with wifi and web and reset button"


//----------------------------------------------
// HARDWARE MOUDLE PINS
//----------------------------------------------
#define MOD_PIN_LED_ESP 13       // internal blue led in ESP-12E Module
#define MOD_PIN_RESET 16         // Reset factory button


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


#endif

