#ifndef ClsMod_Act_Relay_H
#define ClsMod_Act_Relay_H
#include "arduino.h"
#include "Std_defines.h"
#include <ESP8266WiFi.h>
#define RELAY_ON LOW 
#define RELAY_OFF HIGH
class ClsMod_Act_Relay
{
public:
	ClsMod_Act_Relay(void);      // 'empty' constructor
	~ClsMod_Act_Relay(void);
	unsigned short m_Id = 0;
	void setup(unsigned short usPinRele,unsigned short usId);
	void loop(unsigned long uiIngtervalNow);


	// unsigned short  m_iPrgFlag_SwithcInt;    // 1 = Conectar, 0 = Desconectar. (Dispositivo Condidionado a unicamente intervalo de tiempo)
	unsigned short fncGetSts();
	void  fncSetSts(unsigned short bStatusOnOff);
	
private:
	unsigned long m_interval_previous = 0;
	unsigned short m_pinRele = 0;
	unsigned short m_stdDefault = 0;
#ifdef STD_DEBUG_ACT_RELAY
	void fncDebug();
#endif
};
#endif







