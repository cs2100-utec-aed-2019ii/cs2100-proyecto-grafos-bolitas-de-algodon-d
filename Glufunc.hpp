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

void keyboardHandler(unsigned char tecla,int x,int y)
{
  value->closeall(tecla, x, y);
}

#endif
