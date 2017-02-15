//This one includes all the other includes, this makes sure that the main file is not messy.
#include "_external.h"


void setup() {

  //Init all the Subsystems.
  Serial.begin(115200);
  matrixInit();
  fxInit();
  rtcInit();
  timeInit();
  timerInit();
  blynkInit();
  
}

void loop() {

//Check if Blynk is connected, to make sure that the code doesn't become blocking.
  if (Blynk.connected())
  {
    blynkConnected = true;
    Blynk.run();
    pingCheck = false;
  }
  else
  {
    blynkConnected = false;
  }
  //Run the Timer.
  timer.run();
}
