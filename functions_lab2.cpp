#include <iostream>
using namespace std;


int max (int x, int y)
{
  if (x > y)
    return x;
  else
    return y;
}

int main()
{
  int a = 30, b = 20;

  int m = max(a,b);

  cout << " m is " << m << endl;
  return 0;
}
