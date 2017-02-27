#ifndef _MATRIX_H
#define _MATRIX_H


#include <Adafruit_NeoMatrix.h>
#include <gamma.h>

//Constructor for the matrix, passinging in the height and width of the matrix as well as the Pin number.
Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(8, 8, D3,
    NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
    NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
    NEO_GRB            + NEO_KHZ800);


//Init the matrix, to start using it.
void matrixInit()
{
  matrix->begin();
  matrix->setTextWrap(false);
  matrix->setBrightness(brightness);
  matrix->fillScreen(matrix->Color(150, 150, 150));
  matrix->show();
  delay(100);
  matrix->fillScreen(0);
  matrix->show();
  x    = matrix->width();
}


//Runs evertime the msg or time needs to be displayed
void MSGEvent()
{
  if (State != START_STATE)
  {
    matrix->fillScreen(0);
    matrix->setCursor(x, 0);
    matrix->setTextColor(matrix->Color(red, green, blue));
    int len;
    if (State == MSG_STATE)
    {
      len = msg.length() * 6;
      matrix->print(msg);
    }
    if (State == TIME_STATE)
    {
      len = timeIs.length() * 6;
      matrix->print(timeIs);
    }

    if (--x < -len) {
      x = matrix->width();
    }
    if (alarmOn == true)
    {
      matrix->drawPixel(7, 7, matrix->Color(255, 0, 0));
    }
    if (blynkConnected==false)
    {
      matrix->drawPixel(0, 7, matrix->Color(255, 0, 0));
    }
    matrix->show();
    delay(textSpeed);
  }
}


#endif
