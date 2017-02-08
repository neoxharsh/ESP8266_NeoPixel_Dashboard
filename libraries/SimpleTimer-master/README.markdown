## SimpleTimer Library for Arduino ###

This is (yet another) simple library to launch timed actions.

It's based on millis(), thus it has 1 ms resolution.

It uses polling, so no guarantee can be made about the exact time when a callback is fired. For example, if you setup the library so that it calls a function every 2ms, but this function requires 5ms to complete, then you'll have an invocation every 5ms.

For applications where non-strict timing is enough, not using interrupts avoids potential problems with global variables shared between the interrupt service routine and the main program, and doesn't consune a hardware timer.

Author:  Marcello Romani  
Contact: mromani@ottotecnica.com  
License: GNU LGPL 2.1+  
Link: [http://playground.arduino.cc/Code/SimpleTimer](http://playground.arduino.cc/Code/SimpleTimer)

### Git Repository ###
Derek Chafin  
January 31, 2015