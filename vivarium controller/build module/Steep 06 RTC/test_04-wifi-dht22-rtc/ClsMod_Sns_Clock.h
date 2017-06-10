
#ifndef CLSMOD_SNS_CLOCK_H
#define CLSMOD_SNS_CLOCK_H
// include the SD library:
#include "arduino.h"
#include "Std_defines.h"
#include <Wire.h> // I2C and TWI library reloj
#include <DS1307.h>
class ClsMod_Sns_Clock
{
public:
   ClsMod_Sns_Clock(void);      // 'empty' constructor
  ~ClsMod_Sns_Clock(void);
  void setup(void);
  void loop(unsigned long g_interval_now);
  void read(void);
   void fncSetDate(uint16_t Year, uint8_t month, uint8_t day);
    void fncSetTime(uint8_t hh, uint8_t mm,uint8_t ss);
    char m_BufferDateTime[30]; // yyyy/mm/dd hh:mm:ss
	char m_aaaammdd[12];
	char m_hhmm[12];
	unsigned int iDayMinuteAct=0;

  private:
	  unsigned long m_interval_previous = 0;
  DS1307 clock;//define a object of DS1307 class
// set up variables using the SD utility library functions:
#ifdef STD_DEBUG_SNS_CLK
  void fncDebug();

#endif
 
};
#endif

