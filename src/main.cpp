#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

#include "config.h" // Sustituir con datos de vuestra red
#include "ESP8266_Utils.hpp"
#include "WebSocket.hpp"
#include "ESP8266_Utils_WS.hpp"

void setup(void)
{
	Serial.begin(115200);
	d7["id"]="D7";
	d7["pin"] = 13;
	d7["status"] = false;
	d2["id"]="D2";
	d2["pin"] = 4;
	d2["status"] = false;
	pines["D7"] = d7;
	pines["D2"] = d2;
	pinMode(13, OUTPUT);
	pinMode(4, OUTPUT);
	ConnectWiFi_STA();
	InitWebSockets();
}

void loop(void)
{
	webSocket.loop();
}