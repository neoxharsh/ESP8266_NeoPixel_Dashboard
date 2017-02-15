#ifndef _RTC_H
#define _RTC_H


//Defines the min function as somewhere the function stops working.
#define min(a,b) ((a)<(b)?(a):(b))
#define countof(a) (sizeof(a) / sizeof(a[0]))

#include <Wire.h> // must be included here so that Arduino library object file references work
#include <RtcDS1307.h>
#include <SimpleTimer.h>
extern SimpleTimer timer;

void ringAlarm(int,int,String);

RtcDS1307<TwoWire> Rtc(Wire);

//Defines the init of RTC
void rtcInit()
{
  Rtc.Begin();
  pinMode (BUZZER_PIN, OUTPUT);
}

//Prints the date and time to the console
void printDateTime(const RtcDateTime& dt)
{
  char datestring[20];

  snprintf_P(datestring,
             countof(datestring),
             PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
             dt.Month(),
             dt.Day(),
             dt.Year(),
             dt.Hour(),
             dt.Minute(),
             dt.Second() );
  Serial.print(datestring);
}

//Events fired in the background to update the time variable and properly format it to be displayed on the Display
void TimeUpdateEvent()
{
  RtcDateTime now = Rtc.GetDateTime();
  int hour = now.Hour();
  int minutes = now.Minute();
  int seconds = now.Second();
  String AMPM = "AM";
  if (hour == 0)
  {
    hour = 12;
  }
  if (hour > 12)
  {
    hour -= 12;
    AMPM = "PM";
  }
  timeIs = String(hour) + ":" + String(minutes) + AMPM;
  // Serial.println(timeIs + String(seconds));
  ringAlarm(hour,minutes,AMPM);
}

//Event that is fired once the unit starts.
void TimeAutoStartEvent()
{

  if (State == START_STATE)
  {
    Blynk.virtualWrite(SHOW_TIME_BUTTON_WIDGET, HIGH);
    Blynk.virtualWrite(TEXT_SCROLL_BUTTON_WIDGET, HIGH);
    State = TIME_STATE;

    timer.enable(Timer[MSG_TIMER]);
    x    = matrix->width();
    matrix->setBrightness(brightness);
  }
}

#endif
