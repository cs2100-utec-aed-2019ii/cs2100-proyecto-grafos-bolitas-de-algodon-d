#include <iostream>
#include "./Glufunc.hpp"
using namespace std;

int main(int argc, char **argv)
{
  value = new Screen<char>(argc, argv, 640, 480, drawHandler, mouseHandler, keyboardHandler);
  value->Start();
  delete value;
  return 0;
}
