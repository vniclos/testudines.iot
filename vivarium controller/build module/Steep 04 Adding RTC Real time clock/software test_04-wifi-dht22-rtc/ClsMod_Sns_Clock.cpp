#include "ClsMod_Sns_Clock.h"
ClsMod_Sns_Clock::ClsMod_Sns_Clock(void) {};
ClsMod_Sns_Clock::~ClsMod_Sns_Clock(void) {};

void ClsMod_Sns_Clock::setup(void) {
	Wire.begin(0, MOD_PIN_CLOCK_I2C_SLC);
	delay(100);
#ifdef STD_DEBUG_SNS_CLK_RESET
	fncSetDate(STD_DEBUG_SNS_CLK_YY, STD_DEBUG_SNS_CLK_MM, STD_DEBUG_SNS_CLK_DD);
	fncSetTime(STD_DEBUG_SNS_CLK_HH, STD_DEBUG_SNS_CLK_MN, 0);
#endif
	delay(100);
	clock.begin();
	delay(100);
	read();
};
void ClsMod_Sns_Clock::fncSetDate(uint16_t  Year, uint8_t month, uint8_t day) {
	Serial.println("fncSetDate");
	clock.fillByYMD(Year, month, day);
	clock.setTime();

}
void ClsMod_Sns_Clock::fncSetTime(uint8_t hh, uint8_t mm, uint8_t ss) {
	Serial.println("fncSetTime");
	clock.fillByHMS(hh, mm, ss);
	clock.setTime();

}

void ClsMod_Sns_Clock::read(void) {
	Serial.println("lsMod_Sns_Clock::read(void)");
	// Serial.println("Get time ");
	clock.getTime();
	delay(100);
	iDayMinuteAct = clock.hour * 60 + clock.minute;
	sprintf(m_BufferDateTime, "%04d/%02d/%02d; %02d:%02d:%02d",
		clock.year + 2000, clock.month, clock.dayOfMonth, clock.hour, clock.minute, clock.second);
	sprintf(m_aaaammdd, "%04d-%02d-%02d", clock.year+2000, clock.month, clock.dayOfMonth);
	sprintf(m_hhmm, "%02d:%02d", clock.hour, clock.minute);
#ifdef STD_DEBUG_SNS_CLK
	fncDebug();
		#endif
};
void  ClsMod_Sns_Clock::loop(unsigned long g_interval_now)
{
	if (g_interval_now < m_interval_previous)
	{
		m_interval_previous = 0;
	}
	if (g_interval_now - m_interval_previous < INTERVAL_DHT22)
	{

		return;
	}
	m_interval_previous = g_interval_now;
	read();
}

#ifdef STD_DEBUG_SNS_CLK
// PRINT TO SERIAL DEBUG VALUES.
void ClsMod_Sns_Clock::fncDebug()
{
	Serial.println("----");
	Serial.print("year");
	Serial.println(clock.year);
	Serial.print("Month");
	Serial.println(clock.month);
	Serial.print("day");
	Serial.println(clock.dayOfMonth);
	Serial.print("hour ");
	Serial.println(clock.hour);
	Serial.print("minute ");
	Serial.println(clock.minute);

	Serial.println(m_BufferDateTime);
	Serial.println(m_aaaammdd);
	Serial.println(m_hhmm);
	Serial.println("----");
}
#endif