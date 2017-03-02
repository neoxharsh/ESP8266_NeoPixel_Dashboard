#ifndef _BLYNK_H
#define _BLYNK_H


WidgetTerminal terminal(TEXT_SENDER_WIDGET);

#include <ESP8266WiFi.h>
#include "_blynkWidgets.h"
#include "AsyncPing.h"

AsyncPing ping;

//Check if internet is up an running.
bool pingCheck = false;

//Forward declaration of the function.
void blynkSync();

void blynkInit()
{
  matrix->fillScreen(0);
  matrix->show();
  Blynk.config(auth);
  if ( Blynk.connect())
  {
    blynkConnected = true;
  }
  Serial.println("Blynk Config End");
  blynkSync();

  ping.on(false, [](const AsyncPingResponse & response) {
    if (response.total_recv > 0)
    {
      Serial.println("Ping Sucessfull");
      pingCheck = true;
    }
    else
    {
      pingCheck = false;
      Serial.println("Ping UnSucessfull");
    }

    return true; //doesn't matter
  });
}

//Check if Blynk needs to be connected or not, only if internet is up and running, not only wifi.
void blynkCheckEvent()
{

  if (blynkConnected == false && pingCheck == false)
  {
    ping.begin("8.8.8.8");
  }

  if (blynkConnected == false && pingCheck == true)
  {
    Blynk.connect();
  }
}


//Initial Blynk Widget state
void blynkSync()
{
  Blynk.virtualWrite(BRIGHTNESS_WIDGET, brightness);
  Blynk.virtualWrite(TEXT_SCROLL_BUTTON_WIDGET, LOW);
  Blynk.virtualWrite(FX_BUTTON_WIDGET, LOW);
  Blynk.virtualWrite(EFFECTS_WIDGET, 1);
  Blynk.virtualWrite(MSG_SPEED_WIDGET, textSpeed);
  Blynk.virtualWrite(FX_SPEED_WIDGET, fxSpeed);
  Blynk.virtualWrite(OTA_BUTTON_WIDGET, LOW);
  Blynk.virtualWrite(WIFI_CONFIG_BUTTON_WIDGET, LOW);
  Blynk.virtualWrite(SHOW_TIME_BUTTON_WIDGET, LOW);
  Blynk.virtualWrite(ALARM_BUTTON_WIDGET, LOW);
  terminal.println(F(" "));
  terminal.flush();
  Serial.println("Terminal Flush");

}

#endif
