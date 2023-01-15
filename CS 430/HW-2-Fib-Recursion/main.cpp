
// Write a C++ program that uses recursion to create the Fibonacci Table as in the example below 

#include <iostream>
using namespace std;

int fib(int n);
//****************************************************************************************Main
int main() {
  int N;
  do{
    cout << "Enter a non-negative number: ";
    cin >> N;
  }while(N <= 0);
  cout << endl;

  int n = 1;
  cout << "  ";
  for(int i = 0; i < N+1; i++)
    cout << i << " ";
  cout << endl;
  for(int i = 0; i < N+1; i++)
  {
    cout << i << " ";
    for(int ii = 0; ii < n; ii++)
    {
      cout << fib(ii) << " ";
    }
    n++;
    cout << endl;
  }

  return 0;
}
//-----------------------------------------------------------------------------------Functions
//-------------------------------------------------------------------------------fib
int fib(int n){
  if(n == 0 || n == 1) return 1;

  return fib(n - 1) + fib(n - 2);
}