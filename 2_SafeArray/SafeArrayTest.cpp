#include <list>
#include "SafeArray.h"
#include <iostream>
#include <string.h>
#include <cassert>

int main() {
  int i;
  
  SafeArray s(10);
  cout << "SafeArray 1 parameter: ";
  for (i = 0; i < s.length(); ++i)
    cout << i << ": " <<s[i] << "\t";
  cout << endl;
  
  SafeArray x(0, 10);
  cout << "SafeArray 2 parameter positive: ";
  for (i = 0; i < x.length(); ++i)
    cout << i << ": " <<x[i] << "\t";
  cout << endl;
  
  SafeArray z(-5, 1);
  cout << "SafeArray 2 parameter neg: ";
  for (i = 0; i < z.length(); ++i)
    cout << i << ": " <<z[i] << "\t";
  cout << endl;

  return 0;
}  