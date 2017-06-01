
#ifndef _CLSMOD_SNS_DIGITAL_h
#define _CLSMOD_SNS_DIGITAL_h
#include <Arduino.h>
#include <DHT.h>
#include "Std_defines.h"


class ClsMod_Sns_DHT22
{
private:
	// pin al que esta conectado el sensor
	uint8_t m_pin = 0;
	DHT m_DHT=DHT (MOD_PIN_DHT22, MOD_SNS_DHTTYPE, 20);
	const char* m_Error99 = "99,99";
 unsigned long m_interval_dht_previous = 0;
 void fncDebug();
public:
	ClsMod_Sns_DHT22(void);
	~ClsMod_Sns_DHT22(void);
	float m_fHum = 0.0; // humidity float
	float m_fTempC = 0.0; // temperature celsius
	float m_fTempF = 0.0; // temperature farenheit
	char  m_cTemC[6]; // char temperature celsius 2 decimals
	char  m_cTemF[6]; // char temperature celsius 2 decimals
	char  m_cHum[6];// char humidity 2 decimals
	void setup(); // en este caso no hace nada
	bool loop(unsigned long ulIngtervalNow);
};
#endif
