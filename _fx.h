#ifndef _FX_H
#define _FX_H

#include <WS2812FX.h>

//Constructor for the Fx service
WS2812FX *ws2812fx = new WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//Init the FX Service
void fxInit()
{
  ws2812fx->init();
  ws2812fx->setBrightness(brightness);
  ws2812fx->setSpeed(fxSpeed);
}

//This event is trigerred whenever the FX call are made.
void FXEvent()
{
  if (State != START_STATE)
  {
    ws2812fx->service();
  }
}

#endif
