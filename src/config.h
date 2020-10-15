const char *ssid = "GonzalezCORP2.4";
const char *password = "4HumDiJoUnDia_Unsapito?";
const char *hostname = "ESP8266_1";

IPAddress ip(192, 168, 0, 17);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

StaticJsonDocument<1024> pines;
StaticJsonDocument<200> d7;
StaticJsonDocument<200> d2;