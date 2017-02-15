#include <SimpleTimer.h>
extern SimpleTimer timer;
extern WS2812FX *ws2812fx;
void ringAlarm(int h, int m, String ampm ) {
  if (alarmOn == true)
  {
    if (ampm == "PM")
    {
      h = h + 12;
    }

    if (alarmHours == h && alarmMinutes == m && alarmIsRunning == false)
    {
      Blynk.virtualWrite(FX_BUTTON_WIDGET, HIGH);
      ws2812fx->setMode(1);
      ws2812fx->setBrightness(255);
      ws2812fx->setSpeed(255);
      timer.disable(Timer[MSG_TIMER]);
      Blynk.virtualWrite(TEXT_SCROLL_BUTTON_WIDGET, LOW);
      Blynk.virtualWrite(SHOW_TIME_BUTTON_WIDGET, LOW);
      timer.enable(Timer[ALARM_TIMER]);
      timer.enable(Timer[FX_TIMER]);
      Blynk.notify("Wake UP!!!!");
      alarmIsRunning = true;
    }
  }

}


void ringTimer()
{
  tone(BUZZER_PIN, 4400);
  delay(100);
  noTone(BUZZER_PIN);

}



