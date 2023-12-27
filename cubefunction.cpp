#include <iostream>
using namespace std;


int cube(int number)
{
  return(number * number * number);
}



int main()
{

  int number;
  cout << "Please enter your number";
  
  cin >> number;

  int result = cube(number);

  cout << number << "to the power of three is :" << result;
  return 0;
}
