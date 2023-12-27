#include <iostream>
using namespace std;

int main(){
  int num1;
  int num2;

  int sum;

  cout << "Please enter a number:";
  cin >> num1;

  cout <<"Please enter a second number:";
  cin >> num2;

  sum = (num1 + num2);

  cout << "The sum of " << num1 << " and " << num2 << " is " << sum <<endl;

  return 0;
}
