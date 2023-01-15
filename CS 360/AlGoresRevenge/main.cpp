//Al Gore's Revenge.cpp -- Calculate the changes in earth's climate 
//A.Protzel, p360 
//9/9/2017 - 9/11/2017

//This program should calculate how much the ocean has risen over the past century and how much 
//it will rise over the next few years, as well as how much the mean temperature will rise over 
//the specified 4 cities.

#include <iostream>
using namespace std;
  
int main()
{
  
  float wadd = 3.1; //added water
  float tadd = .02; // added temperature
  
  cout << "Over the last century, the ocean rose by\n"
       << "(1.8mm)(0.8cm)(0.0708661in)\n\n";
  
  cout << "In 15 years the ocean will have risen by\n"
       << "(" << (wadd * 15) << "mm)(" << (wadd * 15 / 10) << "cm)(" << (wadd * 15 / 25.4) << "in)\n\n";
  
  cout << "At 30 years the ocean will have risen by\n"
       << "(" << (wadd * 30) << "mm)(" << (wadd * 30 / 10) << "cm)(" << (wadd * 30 / 25.4) << "in)\n\n";
  
  //Bonus- simplified years 1-15-13 to 1 chunk
  cout << "Average temperature in July of this year, 15 years, 30 years-\n" //Bonus- simplified years 1-15-13 to 1 chunk
       << "New York City: 85◦F -> " << (85 * (tadd * 15)) + 85 << "◦F -> " << (85 * (tadd * 30)) + 85 <<"◦F\n"
       << "Denver: 88◦F -> " << (88 * (tadd * 15)) + 88 << "◦F -> " << "◦F -> " << (88 * (tadd * 30)) + 88 << "◦F\n"
       << "Phoenix: 106◦F -> " << (106 * (tadd * 15)) + 106 << "◦F -> " <<(106 * (tadd * 30)) + 106 << "◦F\n"
       << "Sacramento: 92◦F -> " << (92 * (tadd * 15)) + 92 << "◦F -> " << (92 * (tadd * 30)) + 92 << "◦F\n\n";
  
  return 0;
}