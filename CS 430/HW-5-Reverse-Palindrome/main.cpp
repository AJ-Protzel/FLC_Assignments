//Write a program that reads in a sequence of characters and prints them in reverse order using a Stack.

//Create a program that asks the user to enter a string as input. Using Stack or Queue, determine whether this string is a palindrome (i.e. reads the same from left to right and right to left).

#include <iostream>
#include <stack>
#include <string>
using namespace std;

//****************************************************************************************Main
int main(){
  string Word;
  cout << ">>ENTER:";
  cin >> Word;
  cout << endl;

  stack<char> flip;

  for (int i = 0; i < Word.size(); ++i){
    cout << Word.at(i);
    flip.push(Word.at(i));
  }

  cout << endl;
  string word = "";

  for (int i = 0; i < Word.size(); ++i){
    cout << flip.top();
    word += flip.top();
    flip.pop();
  }

  if(Word == word){
    cout << endl << "The word is a palindrome"; 
  }

  return 0;
}