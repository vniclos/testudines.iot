#include "Std_defines.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
//==============================================
// TESTUDINES.IOT
// VIVARIUM CONTROLLER PROJECT IOT
// Vicente Niclos
// TEST 02
// ---------------------------------------------
// CHEKING POWER AND ESP-12E BASIC CIRCUIT
// objetive
// Check correct connection
// Check developing software instalation
// Check correct connec to wifi
// Check web service
// Check button reset factory
// Need Install Arduino IDE
// Need FDDI-USB wire
// Before upload  change values of
// g_WiFiSsid and g_WiFiPassword
// and g_hostname
//----------------------------------------------
const char* g_WiFiSsid = "testudines";     // name of your wifi
const char* g_WiFiPassword = "915265ABCD"; // password of your wifi
const char* g_hostname = "myvivarium";
//----------------------------------------------

ESP8266WebServer server(80);
unsigned long g_interval_now = 0;
String fncWifi_IP4TpToString(IPAddress ipIPAddress)
{
#ifdef STD_DEBUG
  Serial.println("*** ClsStd_NetWifiMng::fncWifi_IP42String(IPAddress sIPAddress)");

#endif
  String zbuff = "";
  zbuff = String(ipIPAddress[0]) + "." + String(ipIPAddress[1]) + "." + String(ipIPAddress[2]) + "." + String(ipIPAddress[3]) ;
  return zbuff;
}
//===================================
// WEB fill html web page root
//===================================
String   fncHtml_buildPage()
{
  String szReply = "<!DOCTYPE html><html><head>";

  szReply += "\<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  szReply += "\n<title>testudines.org vivarium controller</title>";
  szReply += "\n<style>.green{ background-color : #00aa00; width:50px;padding:2px;display:inline-block;} .gray{width:50px; background-color: #aaa; padding:2px;display:inline-block; } ";
  szReply += "\n.button, button {margin:5px;	 display: inline-block;width: 50px;height: 18px;background: #4E9CAF;padding: 5px;  text-align: center;  border-radius: 5px;color: white;  font-weight: bold;}";
  szReply += "\n</style>";
  szReply += "</head><body>";
  szReply += "<input type = \"button\" value = \"Refresh\" onclick = \"javascript:window.location.reload();\" / >";
  szReply += "\n<h2>" + (String) MOD_WEB_Title + "</h2> ";
  szReply += "\n<p>" + (String)MOD_WEB_TitleSub + "</p> ";
  szReply += "\n<p>" + (String)MOD_WEB_text + "</p> ";
  szReply += "\n<h3>Hello World!</h3><p></p>";
  szReply += "\n<fieldset><legend>Network:</legend>";
  szReply += "\nHostname " + String (g_hostname) + "<br/>";
  szReply += "\nWiFi SSID " + String(g_WiFiSsid) + "<br/>";
  szReply += "\nWiFi PASSWORD " + String(g_WiFiPassword) + "<br/>";
  szReply += "\nWiFi MODE W= Work station)<br/>";
  szReply += "\nURL MDNS http:\\ " + String(g_hostname) + ".local  (multicast Domain Name System)<br/>";
  szReply += "\nURL IP http://" + fncWifi_IP4TpToString(WiFi.localIP()) + "<br/>";
  szReply += "\nButon reset Factory pressed ? " + (String) digitalRead(MOD_PIN_RESET);
  szReply += "\n</fieldset>";

  szReply += "\n</body></html>";
  return szReply;
}


//===================================
// WEB Page web root
//===================================
void fncWeb_handleRoot() {
  digitalWrite(MOD_PIN_LED_ESP, 1);

  server.send(200, "text/html", fncHtml_buildPage());
  digitalWrite(MOD_PIN_LED_ESP, 0);
}
//===================================
// WEB Page if url not foud
//===================================
void fncWeb_handleNotFound() {
  digitalWrite(MOD_PIN_LED_ESP, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(MOD_PIN_LED_ESP, 0);
}

//===================================
// Set Config service wifi
//===================================
//
void fncSetupWifi()
{
  Serial.println("fncSetupWifi");
  WiFi.mode(WIFI_STA);

  WiFi.hostname(g_hostname);
  WiFi.begin(g_WiFiSsid, g_WiFiPassword);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(g_WiFiSsid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
//===================================
// Set Config service MDNS
//===================================
void fncSetupMDNS()
{
  Serial.println("fncSetupMDNS");
  if (MDNS.begin(g_hostname)) {
    Serial.println("MDNS responder started at");
    Serial.println("http://" + String(g_hostname) + ".local");
  }
  MDNS.addService("http", "tcp", 80);
}
//===================================
// Set Config service web
//===================================
void fncSetupWeb()
{
  Serial.println("fncSetupWeb");
  server.on("/", fncWeb_handleRoot);
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
  server.onNotFound(fncWeb_handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}
//===================================
// Set Config of services
//===================================
void setup(void) {
  pinMode(MOD_PIN_LED_ESP, OUTPUT);
  digitalWrite(MOD_PIN_LED_ESP, 0);
  Serial.begin(115200);
  Serial.println("Setup");
  fncSetupWifi();
  fncSetupMDNS();
  fncSetupWeb();
  g_interval_now = millis();
}

void loop(void) {
  server.handleClient();
  g_interval_now = millis();
}
