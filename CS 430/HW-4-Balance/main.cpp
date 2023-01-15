#include <iostream>
#include <stack>
#include <string>
using namespace std;

//****************************************************************************************Main
int main(){
  string Mess;
  cout << ">>ENTER:";
  cin >> Mess;
  cout << endl;

  stack<char> checker;

  for (int i = 0; i < Mess.size(); ++i){
    
    if(Mess.at(i) == '(' || Mess.at(i) == '[' || Mess.at(i) == '{'){
      cout << "+ :" << Mess.at(i) << endl;
      checker.push(Mess.at(i));
    }
    else if(Mess.at(i) == ')'){
      if(checker.top() == '('){
        cout << "- :" << checker.top() << endl;
        checker.pop();
      }
    }
    else if(Mess.at(i) == ']'){
      if(checker.top() == '['){
        cout << "- :" << checker.top() << endl;
        checker.pop();
      }
    }
    else if(Mess.at(i) == '}'){
      if(checker.top() == '{'){
        cout << "- :" << checker.top() << endl;
        checker.pop();
      }
    }
    else{
      cout << "last+ :" << Mess.at(i) << endl;
      checker.push(i);
    }
  }cout << endl;

  if(checker.size() <= 0){
    cout << "String is balanced";
  }
  else{
    cout << "String " << Mess << " is not balanced";
  }

  return 0;
} // [()]{}{[()()]()}