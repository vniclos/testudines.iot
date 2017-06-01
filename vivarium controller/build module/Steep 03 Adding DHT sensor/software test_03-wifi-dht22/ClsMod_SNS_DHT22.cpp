#include "ClsMod_Sns_DHT22.h"

ClsMod_Sns_DHT22::ClsMod_Sns_DHT22(void) {}
ClsMod_Sns_DHT22::~ClsMod_Sns_DHT22(void) {}

void ClsMod_Sns_DHT22::setup() {
	 m_fHum = 999.99; // humidity float
	 m_fTempC = 999.99; // temperature celsius
	 m_fTempF =999.99; // temperature farenheit
	
	 sprintf(m_cTemC, "%S", m_Error99);
	 sprintf(m_cTemF, "%S", m_Error99);
	 sprintf(m_cHum, "%S", m_Error99);
}
bool ClsMod_Sns_DHT22::loop(unsigned long g_interval_now) {
	


	if (g_interval_now < m_interval_dht_previous)
	{
		m_interval_dht_previous = 0;
}
  if (g_interval_now- m_interval_dht_previous <INTERVAL_DHT22)
  {

    return true;
  }
  m_interval_dht_previous = g_interval_now;

	m_fHum = m_DHT.readHumidity();
	m_fTempC = m_DHT.readTemperature(false); //celsius
	m_fTempF = m_DHT.readTemperature(true);  //Farenheit

		if (isnan(m_fHum) || isnan(m_fTempC) || isnan(m_fTempF)) {
			Serial.println("DHT read:FAIL, take before values");
			return false;
		}
		Serial.println("DHT read: ok");

		// para representar dos decimales
		if (isnan(m_fTempC)) m_fTempC = 999;
		if (isnan(m_fTempF)) m_fTempF = 999;
		if (isnan(m_fHum)) m_fHum = 999;

		
		dtostrf(m_fTempF,6, 2, m_cTemF);


		dtostrf(m_fTempC, 6, 2, m_cTemC);
		dtostrf(m_fHum, 6, 2, m_cHum);
#ifdef   STD_DEBUG_SNS_DHT
		fncDebug();
#endif

		return true;
	}
#ifdef   STD_DEBUG_SNS_DHT
void ClsMod_Sns_DHT22::fncDebug()
{


	Serial.print("T:");
	Serial.println(m_fTempC);
	Serial.print("H:");
	Serial.println(m_fHum);



}
#endif