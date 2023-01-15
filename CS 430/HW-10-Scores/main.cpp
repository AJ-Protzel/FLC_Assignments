/*
Write a program that dynamically allocates an array large enough to hold a 
user-defined number of test scores. Once all the scores are entered, 
the array should be passed to a function that sorts them in ascending order. 
Another function should be called that calculates the average score. 
The program should display the sorted list of scores and averages with 
appropriate headings. Use pointer notation rather than array notation 
whenever possible.

Input Validation: Do not accept negative numbers for test scores.
*/

#include <iostream>
using namespace std;

int getNumber();
void enterScore(int arr[], int n, int i);
void sortScores(int arr[], int n);
int average(int arr[], int n);
void print(int avr, int arr[], int n);

int main() {
  int n = getNumber();
  int *array = new int[n];

  enterScore(array, n, 0);
  sortScores(array, n);
  print(average(array, n), array, n);

  return 0;
}
//-------------------------------------------------------------------------------getNumber
int getNumber(){
  int c;
  cout << endl << "Enter how many test scores you will be grading.\n>>ENTER:";
  cin >> c;

  if(!cin || cin.fail() || c <= 0){ // input was not an int / input was not valid
    cout << endl << "That is not a usable integer." << endl;
    cin.clear();
    cin.ignore(100, '\n');
    getNumber();
  }
  
  return c;
}
//-------------------------------------------------------------------------------enterScore
void enterScore(int arr[], int n, int i){
  if(i < n){
    int c;
    cout << endl << "Enter score #" << i+1 << "\n>>ENTER:";
    cin >> c;

    if(!cin || cin.fail() || c < 0){ // input was not an int / input was not valid
      cout << endl << "That is not a usable integer." << endl;
      cin.clear();
      cin.ignore(100, '\n');
      enterScore(arr, n, i);
    }
    else{
      arr[i] = c;
      i++;
      enterScore(arr, n, i);
    }
  }
}
//-------------------------------------------------------------------------------sortScores
void sortScores(int arr[], int n){
  int i, key, j;

  for (i = 1; i < n; i++){ 
    key = arr[i]; 
    j = i-1; 
    
    while (j >= 0 && arr[j] > key){ 
      arr[j+1] = arr[j]; 
      j = j-1;
    } 
    
    arr[j+1] = key; 
  }
}
//-------------------------------------------------------------------------------average
int average(int arr[], int n){
  int u = 0;
  for(int i = 0; i < n; ++i){
    u += arr[i];
  }

  return u / n;
}
//-------------------------------------------------------------------------------print
void print(int avr, int arr[], int n){
  cout << endl;

  cout << "The average was: " << avr << endl;
  cout << "Scores from Lowest to Highest is:" << endl;

  for (int i = 0; i < n; ++i){
    cout << "[" << i+1 << "]:" << arr[i] << endl;
  }
}