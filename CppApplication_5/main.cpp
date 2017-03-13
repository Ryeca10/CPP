#include <iostream>
#include <sstream>
using namespace std;

int main () {
  char a[10], b[10];

  istringstream iss ("0\n");
  iss >> noskipws;
  //cout <<iss;
  iss >> a >> ws >> b;
  cout << a<< b << endl;

  return 0;
}