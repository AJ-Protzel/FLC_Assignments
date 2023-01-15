#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
  string pass = "";
  char c;
  int i = 0;
  bool checkc = false;
  bool checks = false;
  bool checku = false;
  bool checkl = false;

do 
{
  cout << "\nEnter password\n";
  getline(cin, pass);
  
  if (!pass.empty())
  {
    checkc = true;
  }
    else 
    {
      cout << "Your password needs at least 6 characters\n1 uppercase letter\n1lower case letter\n";
    }

  if (pass.length() >= 6)
  {
    checks = true;
  }
    else 
    {
      cout << "Needs more than 6 characters\n";
    }

  for(int u = 0; u < pass.length(); u++)
  {
    c = pass[u];
    if (isupper(c))
    {
      checku = true;
    }
  }

  for(int l = 0; l < pass.length(); l++)
  {
    c = pass[l];
    if (islower(c))
    {
      checkl = true;
    }
  }
  
  if(checku == false)
  {
    cout << "Needs at least one upper case letter\n";
  }
  if(checkl == false)
  {
    cout << "Needs at least one lower case letter\n";
  }
  
} while(checkc == false || checks == false || checku == false || checkl == false);
  
  cout << "(" << pass << ") works";
  
  return 0;
}