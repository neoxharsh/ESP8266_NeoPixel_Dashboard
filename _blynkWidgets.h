#ifndef _BLYNKWIDGETS_H
#define _BLYNKWIDGETS_H

//This are all the Blynk Widget callbacks.
void wifiReset();

BLYNK_WRITE(BRIGHTNESS_WIDGET)
{
  brightness = param.asInt();
  if (State == MSG_STATE || State == TIME_STATE)
  {
    matrix->setBrightness(brightness);
  }
  if (State == FX_STATE)
  {
    ws2812fx->setBrightness(brightness);
  }
}

BLYNK_WRITE(COLOR_PICKER_WIDGET)
{
  red = param[0].asInt();
  green = param[1].asInt();
  blue = param[2].asInt();

  if (State == MSG_STATE)
  {
    matrix->setTextColor(matrix->Color(red, green, blue) );
  }
  if (State == FX_STATE)
  {
    ws2812fx->setColor(red, green, blue);
  }
}

BLYNK_WRITE(TEXT_SENDER_WIDGET)
{
  msg = param.asStr();
}

BLYNK_WRITE(TEXT_SCROLL_BUTTON_WIDGET)
{

  if (param.asInt() == HIGH)
  {
    State = MSG_STATE;
    timerDisabler(MSG_TIMER);
    timer.enable(Timer[MSG_TIMER]);

    x    = matrix->width();
    matrix->setBrightness(brightness);

    Blynk.virtualWrite(FX_BUTTON_WIDGET, LOW);
  }
  else
  {
    if (State != START_STATE)
    {
      State = START_STATE;
      Blynk.virtualWrite(SHOW_TIME_BUTTON_WIDGET, LOW);
      timer.disable(Timer[MSG_TIMER]);

      matrix->fillScreen(0);
      matrix->show();
    }
  }

}

BLYNK_WRITE(FX_BUTTON_WIDGET)
{
  if (param.asInt() == HIGH)
  {
    State = FX_STATE;

    timerDisabler(FX_TIMER);
    timer.enable(Timer[FX_TIMER]);

    ws2812fx->start();
    Blynk.virtualWrite(TEXT_SCROLL_BUTTON_WIDGET, LOW);
    Blynk.virtualWrite(SHOW_TIME_BUTTON_WIDGET, LOW);

  }
  else
  {
    if (State != START_STATE)
    {
      State = START_STATE;

      timer.disable(Timer[FX_TIMER]);

      ws2812fx->stop();
    }
  }


}

BLYNK_WRITE(EFFECTS_WIDGET)
{
  fxMode = param.asInt();

  ws2812fx->setMode(fxMode - 1);
}

BLYNK_WRITE(MSG_SPEED_WIDGET)
{
  textSpeed = param.asInt();
}

BLYNK_WRITE(FX_SPEED_WIDGET)
{
  fxSpeed = param.asInt();
  ws2812fx->setSpeed(fxSpeed);
}

BLYNK_WRITE(OTA_BUTTON_WIDGET)
{
  if (param.asInt() == HIGH)
  {
    State = OTA_STATE;
    for (int i = 0; i < TOTAL_TIMER; i++)
    {
      if (i != OTA_TIMER && timer.isEnabled(Timer[i]))
      {
        timer.disable(Timer[i]);
      }
    }
    if (otaInitilized == LOW)
    {
      matrix->setBrightness(brightness);
      matrix->fillScreen(0);
      matrix->setTextColor(matrix->Color(150, 150, 150));
      matrix->setCursor(1, 1);
      matrix->print("O");
      matrix->show();
      ArduinoOTA.begin();
      Timer[OTA_TIMER] = timer.setInterval(1, OTAEvent);
      otaInitilized = HIGH;
      Blynk.virtualWrite(TEXT_SCROLL_BUTTON_WIDGET, 0);
      Blynk.virtualWrite(FX_BUTTON_WIDGET, 0);
    }
    else
    {
      Blynk.virtualWrite(TEXT_SCROLL_BUTTON_WIDGET, 0);
      Blynk.virtualWrite(FX_BUTTON_WIDGET, 0);
      timer.enable(Timer[OTA_TIMER]);
    }
  }
  else
  {
    if (State != START_STATE)
    {
      State = START_STATE;
      timer.disable(Timer[OTA_TIMER]);
    }
  }
}

BLYNK_WRITE(SYNC_TIME_BUTTON_WIDGET)
{
  syncTime();
}

BLYNK_WRITE(SHOW_TIME_BUTTON_WIDGET)
{
  if (param.asInt() == HIGH)
  {
    State = TIME_STATE;
    textSpeed = 80;
    timerDisabler(MSG_TIMER);

    x    = matrix->width();
    timer.enable(Timer[MSG_TIMER]);
    Blynk.virtualWrite(TEXT_SCROLL_BUTTON_WIDGET, HIGH);
    Blynk.virtualWrite(FX_BUTTON_WIDGET, LOW);

  }
  else
  {
    if (State != START_STATE)
    {
      State = START_STATE;
      matrix->fillScreen(0);
      matrix->show();
      timer.disable(Timer[MSG_TIMER]);
      //timer.disable(Timer[TIME_TIMER]);
      Blynk.virtualWrite(TEXT_SCROLL_BUTTON_WIDGET, LOW);
    }
  }
}

BLYNK_WRITE(WIFI_CONFIG_BUTTON_WIDGET)
{
  wifiReset();
}

#endif
