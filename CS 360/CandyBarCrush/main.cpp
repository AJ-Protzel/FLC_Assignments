//CandyBarCrush.txt -- counting candy
//A.Protzel, p360 
//10/13/2017 - 11/20/2017

//A national weight loss group has hired you to keep track of candy for it’s members.
//You will build a simple database to do this. 
//Create a program which uses a CandyBar structure; which contains three members:
//brand name of candy bar, candy weight (which may be fractional), and number of calories.

//• Create a menu to control the process: 1 - add candy, 2 - delete candy 3 - display all candy, 4 - Quit.
//• Initialize the new candy elements to "Generic", 1.0 and 999 before you enter any data.
//• Use a pseudo dynamic array (i.e. prompt for the maximum number of candy at the start of the program). Then loop to enter all the candy.

// Bonus 1 - Line:50 - comfy for users 
// Bonus 2 - Line:27 - added in how many per brand in struct 
// Bonus 3 - Line:190 - added edit function

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

struct Candys
{
  string Brand;
  int Count; // Bonus 2 - added in how many per brand in struct 
  float Weight;
  int Calories;
};

void Menu(); // main add / remove / display function
void Add(); // adds in new candies
void Edit(); // edits an existing spot // Bonus 3 - added edit function
void Remove(); // removes candies
void Display(); // displays candies

const int SIZE = 50;
Candys* Candy = new Candys[SIZE];

int main()
{
  for(int i = 0; i < SIZE; ++i) // initialize the array spots as "Generic"
  {
    Candy[i].Brand = "Generic";
    Candy[i].Count = 1;
    Candy[i].Weight = 1.00;
    Candy[i].Calories = 999; 
  }

  bool check = false;
  int choice;
  char quit;

  cout << "Welcome";
// Bonus 1 - Comfy for user 
  do{
    cout << "\n-----------------------------------------";
    cout << "\nWhat would you like to do?\n[1]:Explanation\n[2]:Start\n[3]:Quit\n>>ENTER:";
    cin >> choice;
    
    if(choice == 1)
    {
      cout << "\nYou will be prompted to enter to either, enter, remove, or display your candy candy amount."
           << "\nIf inputing new candy you will be entering the brand name, its weight, and its calorie count." << endl;
    }
    else if(choice == 2)
    {
      Menu();
      check = true;
    }
    else if(choice == 3)
    {
      cout << "\nWhould you like to quite?\n>>ENTER Y/N:";
      cin >> quit;
      cin.ignore();
      
      if(quit == 'Y' || quit == 'y')
      {
        check = true;
      }
    }
    else 
    {
      cout << "\nThats not a valid option" << endl;
    }
  }while(check == false);
  
  cout << "\n\nThank you";
  
  return 0;
}
//=================================================================================================================Functions
//-----------------------------------------------------------------------------------------------------------------Menu
void Menu()
{
  bool check = false;
  int choice;
  char quit;
  
  do{
    cout << "--------------------------";
    cout << "\nWhat would you like to do?\n[1]:Add\n[2]:Edit\n[3]:Remove\n[4]:Display\n[5]:Quit\n>>ENTER:";
    cin >> choice;
    
    if(choice == 1)
    {
      Add();
    }
    else if(choice == 2)
    {
      Edit();
    }
    else if(choice == 3)
    {
      Remove();
    }
    else if(choice == 4)
    {
      Display();
    }
    else if(choice == 5)
    {
      cout << "\nWhould you like to quit?\n>>ENTER Y/N:";
      cin >> quit;
      cin.ignore();
      
      if(quit == 'Y' || quit == 'y')
      {
        check = true;
      }
    }
    else 
    {
      cout << "\nThats not a valid option" << endl;
    }
  }while(check == false);
}

//-----------------------------------------------------------------------------------------------------------------Add
void Add()
{
  cout << "========================================" << endl;
  
  int Times = 0;
  int Count = 0;
  bool check = false;
  
  do{
    cout << "How many different candy brands will you be entering?\n>>ENTER:";
    cin >> Count;

    if(cin.fail())
    {
      cin.clear();
      cin.ignore();
      cout << endl << ">>Invalid input try again<<" << endl << endl;
    }
    else
    {
      check = true;
    }
  }while(check == false);

  for(int i = 0; (i < SIZE) && (Times != Count); ++i)
  {
    if(Candy[i].Brand == "Generic")
    {
      cout << endl;
      cin.clear();
      cin.ignore();
    
      cout << "[" << i + 1 << "]Enter Brand name:";
      getline(cin, Candy[i].Brand);
    
      cout << "   Amount you are adding  :";
      cin >> Candy[i].Count;
    
      cout << "   Weight per serving     :";
      cin >> Candy[i].Weight;
    
      cout << "   Calories per serving   :";
      cin >> Candy[i].Calories;
      
      Times++;
    }
  }
}
// Bonus 3 - added edit function
//-----------------------------------------------------------------------------------------------------------------Edit
void Edit()
{
  cout << "========================================" << endl;
  
  int Count = 0;
  bool check = false;
  
  for(int i = 0; i < SIZE; ++i)
  {
    if(Candy[i].Brand != "Generic")
    {
      cout << "[" << i + 1 << "]" << Candy[i].Brand << endl;
    }
  }
  
  cout << endl;
  
  do{
    cout << "Which one would you like to edit?\n>>ENTER:";
    cin >> Count;

    if(cin.fail())
    {
      cin.clear();
      cin.ignore();
      cout << endl << ">>Invalid input try again<<" << endl << endl;
    }
    else
    {
      check = true;
    }
  }while(check == false);
  
  cout << "--------------------------" << endl;
  
  cout << "[" << Count << "]" << Candy[Count - 1].Brand
           << endl << " Count   : " << Candy[Count].Count
           << endl << " Weight  : " << Candy[Count - 1].Weight
           << endl << " Calories: " << Candy[Count - 1].Calories << endl;
  
  cout << endl;
  cin.clear();
  cin.ignore();
  
  cout << "[" << Count << "]Enter Brand name:";
  getline(cin, Candy[Count - 1].Brand);
  
  cout << "   Enter Amount   :";
  cin >> Candy[Count - 1].Count;
  
  cout << "   Enter Weight   :";
  cin >> Candy[Count - 1].Weight;
  
  cout << "   Enter Calories :";
  cin >> Candy[Count - 1].Calories;
}

//-----------------------------------------------------------------------------------------------------------------Remove
void Remove()
{
  cout << "========================================" << endl;
  
  int Place;
  
  cout << "Enter the number[n] you are removing.\n>>ENTER:";
  cin >> Place;

  cout << "[" << Place << "]" << Candy[Place - 1].Brand << " Removed" << endl;

  Candy[Place - 1].Brand = "Generic";
  Candy[Place - 1].Count = 1;
  Candy[Place - 1].Weight = 1.00;
  Candy[Place - 1].Calories = 999; 
}

//-----------------------------------------------------------------------------------------------------------------Display
void Display()
{
  cout << "****************************************" << endl;
  
  for(int i = 0; i < SIZE; ++i)
  {
    if(Candy[i].Brand != "Generic")
    {
      cout << "[" << i + 1 << "]" << Candy[i].Brand
           << endl << " Count         : " << Candy[i].Count
           << endl << " Weight/Total  : " << Candy[i].Weight << " | " << Candy[i].Weight * Candy[i].Count
           << endl << " Calories/Total: " << Candy[i].Calories << " | " << Candy[i].Calories * Candy[i].Count;
      cout << endl << endl;
    }
  }
}