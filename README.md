# ESP8266 Based NeoPixel Dashboard

This is an ESP8266 based Neopixel dashboard, it shows current time, can show a custom message and have upto 41 prebuild effects.
Moreoever, the color and brightness of the message as well as time can be changed. The speed of the message scroll as well as effects
can also be changed dynamically. The time is RTC backed and The whole dashboard is LiIon Battery Backed.




The construction consist of following basic parts.

1. ESP8266 based NodeMCU, any other board can be used (https://shop.pimoroni.com/products/adafruit-feather-huzzah-with-esp8266-wifi)
2. NeoPixel matrix (https://goo.gl/zl7i5V)
3. LiIo Battery (From Amazon)
4. RTC for time keeping (From Amazon or Ebay)
5. Battery charging circuit (The one found on ebay, or Amazon)
6. Front and Back plates from Pimoroni (https://shop.pimoroni.com/products/pibow-modification-layers)

The connection is straightforward, The Data In Pin of the matrix is connected to the D3 pin of NodeMCU. and the 5V Pin is connected to the 5V of battery charging circuit. This is to make sure that we do not fry the ESP. Protection diode needs to be placed between all the points, but I was lazy enough not to use one, as who cares even if I loose a cheap NodeMUC. All the connection are totally up to you, this is not the only way you can use it. 

The Magic lies in the Code, The meat lies in the code. Code is everything !!!!!!......
Before uploading the code make sure, you have the ESP9266 Arduino Core and that you have connected the ESP8266 to WiFi at least once, and do remember to use the libraries that I have included in this repository, the one that I have used have been modified a bit to be able to use it properly. The description is below. 

Original Library

1. Adafruit_GFX (https://github.com/adafruit/Adafruit-GFX-Library)
2. Adafruit_NeoPixel (https://github.com/adafruit/Adafruit_NeoPixel)
3. Blynk (https://github.com/blynkkk/blynk-library)
4. WiFiManager (https://github.com/tzapu/WiFiManager)
5. AsyncPing (https://github.com/akaJes/AsyncPing)
6. NTPClient (https://github.com/arduino-libraries/NTPClient)
7. RTC_By_Makuna (https://github.com/Makuna/Rtc)
8. ArduinoOTA (InBuilt)
9. Simple-Timer (https://github.com/jfturcot/SimpleTimer)

Modified

1. Adafruit_NeoMatrix (https://github.com/adafruit/Adafruit_NeoMatrix)
2. WS2812FX (https://github.com/kitesurfer1404/WS2812FX)

Now once you open the main file, go to the _defines.h_ and insert yout blynk app token in the bottom last paramater named _auth_ 
Then upload the code to the ESP. 

Arrange the Widgets according to the following image making sure that you have used the exact same virtual pin, and if you want to use your own setup, you are good to go, just make sure to make chages in the defines.h file accordingly. 

