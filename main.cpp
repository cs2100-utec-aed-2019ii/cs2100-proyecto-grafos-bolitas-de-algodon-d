#include <iostream>
#include "./Glufunc.hpp"
using namespace std;

int main(int argc, char **argv)
{
  value = new Screen<char>(argc, argv, 640, 480, drawHandler, mouseHandler);
  value->Start();
  delete value;
  List<int> a;
  a.push(4);
  a.push(2);
  a.push(5);
  a.push(3);
  for(int i = 0; i < a.length(); i++)
  {
    cout << a.at(i) << endl;
  }
  cout << endl;

  a.for_each(
    [](int i){
      cout << i << endl;
    }
  );
  return 0;
}
