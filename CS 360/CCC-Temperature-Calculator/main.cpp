//CCC Tempurature Calculator.txt -- temperature converter.
//A.Protzel, p360 
//9/29/2017 - 10/2/2017

//We only want to accept valid words cat, cap, cot no matter how they are spelled (ie Cat, CAT, caT all Ok too).
//Prompt for the object to calculate the temperature for.
//Ask for the temperature of the object in Fahrenheit. Check to see if it’s in the proper range.
//Create a menu for the temperature scale to convert to. Have an All option.

//cat F = 86.0(low)  102.0(high)
//cot F = 54.0(low)  80.0(high)
//cap F = 72.0(low)  88.0(high)

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
  string object = "";
  string objchecker = "";
  char c;
  bool validobj = false;
  
  float temp;
  int low, high;
// Bonus - added a few more objects
  const int catL = 86, catH = 102,
            cotL = 54, cotH = 80,
            capL = 72, capH = 88,
            dogL = 99, dogH = 104,
            compL = 40, compH = 140,
            babyL = 95, babyH = 100,
            fridgeL = 33, fridgeH = 39,
            horseL = 97, horseH = 104;
  bool validtemp = false;
  
  int choice;
// Bonus - added more temperature scales
  float celsius, kelvin, rankine, delisle, newton, reaumur, romer;
  bool validcon = false;
  
// Bonus - added greeting
  cout << "Hello, here you can take the input a temperature in the normal range of an object and convert it to variouse temperature scales\n\n";
//--------------------------------------------------------------------------------------------------------------------Object 
  do{
    cout << "Type in the name of an object.\nCat, Cot, Cap, Dog, Copmuter, Baby, Refrigerator, Horse.\nChoose:";
    getline(cin, object);
  
    for(int i = 0; i < object.length(); ++i)
    {
      c = object[i];
      c = tolower(c);
      objchecker += c;
    }
    
    if(objchecker == "cat" || objchecker == "cot" || objchecker == "cap" || objchecker == "dog" || objchecker == "copmuter" || objchecker == "baby" || objchecker == "refrigerator" || objchecker == "horse")
    {
      validobj = true;
    }
    
    else
    {
      cout << "\nThat is not a valid object\n\n";
      objchecker.clear();
    }
    
  }while(validobj == false);
//------------------------------------------------------------------------------------------------------------------Temperature  
  do{
    if(objchecker == "cat")
    {
      cout << "\nEnter a temperature in fahrenheit between 86 and 102:";
      cin >> temp;
      
      low = catL;
      high = catH;
    }
    else if(objchecker == "cot")
    {
      cout << "\nEnter a temperature in fahrenheit between 54 and 80:";
      cin >> temp;
      
      low = cotL;
      high = cotH;
    }
    else if(objchecker == "cap")
    {
      cout << "\nEnter a temperature in fahrenheit between 72 and 88:";
      cin >> temp;
      
      low = capL;
      high = capH;
    }
    else if(objchecker == "dog")
    {
      cout << "\nEnter a temperature in fahrenheit between 99 and 104:";
      cin >> temp;
      
      low = dogL;
      high = dogH;
    }
    else if(objchecker == "computer")
    {
      cout << "\nEnter a temperature in fahrenheit between 40 and 104:";
      cin >> temp;
      
      low = compL;
      high = compH;
    }
    else if(objchecker == "baby")
    {
      cout << "\nEnter a temperature in fahrenheit between 95 and 100:";
      cin >> temp;
      
      low = babyL;
      high = babyH;
    }
    else if(objchecker == "refrigerator")
    {
      cout << "\nEnter a temperature in fahrenheit between 33 and 39:";
      cin >> temp;
      
      low = fridgeL;
      high = fridgeH;
    }
    else if(objchecker == "horse")
    {
      cout << "\nEnter a temperature in fahrenheit between 97 and 104:";
      cin >> temp;
      
      low = horseL;
      high = horseH;
    }
    
    if(temp >= low && temp <= high)
    {
      validtemp = true;
    }
    else
    {
      cout << "\nThat is not a valid temperature\n";
    }
    
  }while(validtemp == false);
//------------------------------------------------------------------------------------------------------------------convertion  
  do{
    cout << "\nWhat would you like to convert to?\nType in the number to continue\n";
    cout << "[1]:Celsius\n[2]:Kelvin\n[3]:Rankine\n[4]:Delisle\n[5]:Newton\n[6]:Reaumur\n[7]:Romer\n[8]:ALL\nChoose:";
    cin >> choice;
    
    celsius = ((temp - 32) / 1.8);
    kelvin = ((temp + 459.67) * 5 / 9);
    rankine = (temp + 459.67);
    delisle = ((212 - temp) * 5 / 6);
    newton = ((temp - 32) * 11 / 60);
    reaumur = ((temp - 32) * 4 / 9);
    romer = (((temp - 32) * 7 / 24) + 7.5);
    
    celsius = roundf(celsius * 1000) / 1000;
    kelvin = roundf(kelvin * 1000) / 1000;
    rankine = roundf(rankine * 1000) / 1000;
    delisle = roundf(delisle * 1000) / 1000;
    newton = roundf(newton * 1000) / 1000;
    reaumur = roundf(reaumur * 1000) / 1000;
    romer = roundf(romer * 1000) / 1000;
    
    if(choice == 1)
    {
      cout << "\nCelsius = " << celsius;
      
      validcon = true;
    }
    else if(choice == 2)
    {
      cout << "\nKelvin = " << kelvin;
      validcon = true;
    }
    else if(choice == 3)
    {
      cout << "\nRankine = " << rankine;
      
      validcon = true;
    }
    else if(choice == 4)
    {
      cout << "\nDelisle = " << delisle;
      
      validcon = true;
    }
    else if(choice == 5)
    {
      cout << "\nNewton = " << newton;
      
      validcon = true;
    }
    else if(choice == 6)
    {
      cout << "\nReaumur = " << reaumur;
      
      validcon = true;
    }
    else if(choice == 7)
    {
      cout << "\nRomer = " << romer;
      
      validcon = true;
    }
    else if(choice == 8)
    {
      cout << "\nCelsius = " << celsius
           << "\nKelvin  = " << kelvin
           << "\nRankine = " << rankine
           << "\nDelisle = " << delisle
           << "\nNewton  = " << newton
           << "\nRéaumur = " << reaumur
           << "\nRømer   = " << romer;
           
      validcon = true;
    }
    else
    {
      cout << "\nThats not a valid choice\n";
    }
    
  }while(validcon == false);
  
// Bonus - added goodbye message
  cout << "\n\nThank you, Goodbye.";
  
  return 0;
}