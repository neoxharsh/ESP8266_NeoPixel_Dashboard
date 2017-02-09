#ifndef _TIMER_H
#define _TIMER_H

#include <SimpleTimer.h>

#include <WiFiUdp.h>

SimpleTimer timer;
void blynkInitEvent();
void blynkCheckEvent();
void syncTime();
void timerInit()
{
  Timer[MSG_TIMER] =  timer.setInterval(10, MSGEvent);
  timer.disable(Timer[MSG_TIMER]);
  Timer[FX_TIMER]  =  timer.setInterval(10, FXEvent);
  timer.disable(Timer[FX_TIMER]);
  timer.setInterval(10, TimeUpdateEvent);
  timer.setTimeout(5000, TimeAutoStartEvent);
  timer.setInterval(10000, blynkCheckEvent);
  timer.setInterval(86400000,syncTime);
}


void timerDisabler(int index)
{
  for (int x = 0; x < TOTAL_TIMER - 1; x++)
  {
    if (x != index)
    {
      timer.disable(Timer[x]);
    }
  }
}

#endif
