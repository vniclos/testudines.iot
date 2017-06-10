
#include "ClsMod_Act_Relay.h"

// 1 Mode Manual
// 2 Mode Automatic
ClsMod_Act_Relay::ClsMod_Act_Relay(void) {
	m_stdDefault = RELAY_OFF;
    m_pinRele = 0;
};


ClsMod_Act_Relay::~ClsMod_Act_Relay(void) {}

void ClsMod_Act_Relay::setup(unsigned short usPinRele, unsigned short usId)
{
  //,RL_OFF, DEF_MOD_PRGRELMODE_MANUALOFF,,,
  // por omision apagado, en el bucle se calcuara el estado correcto.
  m_pinRele = usPinRele;    // Pin al que esta conectado el rele

  m_Id = usId;
  digitalWrite(m_pinRele, RELAY_OFF);
  pinMode(m_pinRele, OUTPUT);


}
void  ClsMod_Act_Relay::loop(unsigned long uiIngtervalNow){


	if (uiIngtervalNow < m_interval_previous)
	{
		m_interval_previous = 0;
	}
	if (uiIngtervalNow - m_interval_previous < INTERVAL_RELAY)
	{

		return;
	}
	m_interval_previous = uiIngtervalNow;
	// Aqui actualiazar tares a intervalos
	
#ifdef STD_DEBUG_ACT_RELAY
	
	//fncDebug();
#endif
	
}
unsigned short  ClsMod_Act_Relay::fncGetSts() {

  if( digitalRead(m_pinRele)== RELAY_ON) return RELAY_ON;
  return RELAY_OFF;
  
}
void ClsMod_Act_Relay::fncSetSts( unsigned short bStatusOnOff) {
	unsigned short usRELAY_ON = RELAY_ON;
#ifdef STD_DEBUG_ACT_RELAY

	Serial.print("Relay pin ");
	Serial.print(m_pinRele);
	Serial.print(" Status ");
	Serial.print(digitalRead(m_pinRele));
	Serial.print(" CHANGE TO  ");
	Serial.println(digitalRead(bStatusOnOff));
	
#endif
	
  if (bStatusOnOff == 0)
  {
    digitalWrite (m_pinRele, RELAY_OFF);
	Serial.println("off");
  }

else if(bStatusOnOff == 1) {
	Serial.println("on");
  digitalWrite (m_pinRele, RELAY_ON);

 
}


}
#ifdef STD_DEBUG_ACT_RELAY
void ClsMod_Act_Relay::fncDebug()
{
	
	Serial.print("Relay pin ");
	Serial.print(m_pinRele);
	Serial.print( " Status ");
	Serial.println(digitalRead(m_pinRele));
	
}
#endif
