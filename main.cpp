#include <iostream>
#include "./Screen.hpp"
#include "./Graph.hpp"
using namespace std;

int main(int argc, char **argv)
{
  Screen<char> *value = new Screen<char>(argc, argv, 640, 480);
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