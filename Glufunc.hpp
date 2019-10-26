#ifndef GLUFUNC
#define GLUFUNC
#include "./Screen.hpp"

Screen<char> *value;

void drawHandler()
{
  value->drawHandler();
}

void mouseHandler(int a, int b, int c, int d)
{
  value->eventHandler(a, b, c, d);
}

#endif
