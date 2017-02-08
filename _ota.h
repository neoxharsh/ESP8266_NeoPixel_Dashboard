#ifndef _OTA_H
#define _OTA_H

//This is the OTA SubSystem..

#include <ESP8266mDNS.h>
#ifndef _WIFIUDP_H
#include <WiFiUdp.h>
#endif
#include <ArduinoOTA.h>

void otaInit()
{
  ArduinoOTA.onStart([]() {
    matrix->fillScreen(0);
    Serial.println("Start");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
    ESP.reset();
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    matrix->setNPixelColor((progress / (total / 64)), matrix->Color(255, 0, 0));
    matrix->show();
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
}

void OTAEvent()
{
  ArduinoOTA.handle();
}

#endif
