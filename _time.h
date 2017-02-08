#ifndef _TIME_H
#define _TIME_H

#include <NTPClient.h>
#ifndef _WIFIUDP_H
#include <WiFiUdp.h>
#endif


WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, 19800);


void timeInit()
{
  timeClient.begin();
}


void syncTime()
{
  timeClient.update();
  unsigned long secsTillEpoch = timeClient.getEpochTime() - 946684800 ;
  RtcDateTime compiled = RtcDateTime(secsTillEpoch);
  printDateTime(compiled);
  Rtc.SetDateTime(compiled);
}

#endif
