WebSocketsServer webSocket = WebSocketsServer(81);

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t lenght)
{
  String out;
  switch (type)
  {
  case WStype_DISCONNECTED:
    break;
  case WStype_CONNECTED:
    pines["action"]=0;
    serializeJson(pines, out);
    webSocket.sendTXT(num, out);
    break;
  case WStype_TEXT:
    ProcessRequest((const char *)payload);
    serializeJson(pines, out);
    // webSocket.sendTXT(num, out);
    webSocket.broadcastTXT(out);
    break;
  }
}

void InitWebSockets()
{
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  Serial.println("WebSocket server started");
}