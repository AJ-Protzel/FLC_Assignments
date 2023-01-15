//LoveTester.txt -- Crushing your hopes and dreams
//A.Protzel, p360 
//10/20/2017 - 11/27/2017

//Prompts the user for two nouns and then displays how much the two things ’love’ each other.
//If I type ’Caleb’ and ’Broccoli’ it may respond with "Caleb loves Broccoli 86%".

//• Now, there is no way the program will be able to actually ’know’ how much these two things love each other, so generate a random number between 1 and 100 and display that instead.
//• Whenever you enter the same noun pair - the program responds with the SAME, consistent, answer as the first time! Example:every time I enter ’Caleb’ and ’Broccoli’ the program will respond with 86%.
//• Make the words case independent (i.e. run no matter what letter is capitalized).
//• Loop the program until you type quit into the first noun.
//• You will have no way of knowing how many entries the client will enter, so you will need to have your array increase every time you add a new item to it. I’m looking for a real dynamic array.
//• Do not allow blank lines as input.
//• Do not allow numbers as input.

// Bonus 1 - Line 44: made Mama Baba user friendly
// Bonus 2 - Line 141: Added quotes to the % of the match
// Bonus 3 - Line 150: added user name input and special interaction

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

struct Matches
{
  string Name1;
  string Name2;
  int Rate;
};

const int SIZE = 100;
Matches* List = new Matches[SIZE];

string Names();
void Quote(int, string, int);

//*****************************************************************************************************************Main
int main()
{
  srand (time(NULL));
  char quit;
  bool Quit = false;
  string Name1, Name2, User;
  
// Bonus 1 - made Mama Baba user friendly
  cout << "Welcome to Mama Baba's Love Machine." << endl;
  cout << "But who are you? Give me your name." << endl;
  User = Names();
  
  cout << "\nAhh well hello dere " << User << ", well I know why you're here" << endl << endl;
  
  for(int i = 0; (i < SIZE) && (Quit == false); ++i)
  {
    cout << "❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️" << endl;
    cout << "Give Baba two names and she will see their fate." << endl;
    
    Name1 = Names();
    Name2 = Names();
    
    for(int ii = 0; ii < SIZE; ++ii)
    {
      if(Name1 == List[ii].Name1 || Name1 == List[ii].Name2 && Name2 == List[ii].Name1 || Name2 == List[ii].Name2)
      {
        cout << "\nYes yes I see's, Mama Baba says [" << List[ii].Rate <<"%]\ncompatible" << endl;
        
        Quote(List[ii].Rate, User, ii);
        
        break;
      }
      else
      {
        List[i].Name1 = Name1;
        List[i].Name2 = Name2;
        List[i].Rate = rand() % 100;
        
        cout << "\nYes yes I sees, Mama Baba says [" << List[i].Rate <<"%]\ncompatible" << endl;
        
        Quote(List[i].Rate, User, i);
        
        break;
      }
    }
    
    cout << "=================================================" << endl;
    cout << "Would you like Baba too look at more names?\n>>ENTER Y/N:";
    cin >> quit;
    
    if(quit == 'N' || quit == 'n')
      {
        cout << "\nMama Baba says goodbye for now.";
        Quit = true;
        break;
      }
      
      cin.ignore();
  }
  
  delete [] List;
  List = NULL;
  
  return 0;
}
//=================================================================================================================Functions
//-----------------------------------------------------------------------------------------------------------------Names
string Names()
{
  string Name;
  string Place;
  char c;
  bool check = false;
  bool digit = false;
  
  do{
    cout << ">>ENTER:"; getline(cin, Name);
  
    for(int i = 0; i < Name.length(); ++i)
    {
      if(isdigit(Name[i]))
      {
        digit = true;
      }
    }
  
    if(Name.empty() || digit == true)
    {
      cin.clear();
      cin.ignore();
      digit = false;
      cout << endl << ">>Mama Baba cant read dat name, try again<<" << endl << endl;
    }
    else
    {
      check = true;
    }
  }while(check == false);
  
  for(int i = 0; i < Name.length(); ++i)
  {
    c = Name[i];
    c = tolower(c);
    Place += c;
  }
  
  return Place;
}
//-----------------------------------------------------------------------------------------------------------------Quote
// Bonus 2 - Added quotes to the % of the match
// Bonus 3 - added user name input and special interaction
void Quote(int num, string User, int Spot)
{
  cout << endl;
  
  if(num > 90)
  {
    if(User == List[Spot].Name1 || User == List[Spot].Name2)
    {
      cout << "OOOHHOHO, dis be a good good bond wid you two" << endl;
    }
    else
    {
      cout << "Yes, Yes dis is good good, dey be great friends" << endl;
    }
  }
  else if(num > 80)
  {
    if(User == List[Spot].Name1 || User == List[Spot].Name2)
    {
      cout << "Yes, Yes, you be great friends wid dis fool" << endl;
    }
    else
    {
      cout << "Oooo Mama Baba see's a great bond can be found between dese fools" << endl;
    }
  }
  else if(num > 70)
  {
    if(User == List[Spot].Name1 || User == List[Spot].Name2)
    {
      cout << "Mama can see you two being good good friends" << endl;
    }
    else
    {
      cout << "Now dey be becoming great friends" << endl;
    }
  }
  else if(num > 60)
  {
    if(User == List[Spot].Name1 || User == List[Spot].Name2)
    {
      cout << "Mama dont see why you two cant be better friends, ya'll are on the right track" << endl;
    }
    else
    {
      cout << "Good, dem be on the right track" << endl;
    }
  }
  else if(num > 50)
  {
    if(User == List[Spot].Name1 || User == List[Spot].Name2)
    {
      cout << "Dis can go two ways, really, or really bad" << endl;
    }
    else
    {
      cout << "Dese two have de makings to become great friends or great enemies" << endl;
    }
  }
  else if(num > 40)
  {
    if(User == List[Spot].Name1 || User == List[Spot].Name2)
    {
      cout << "You need to work more wid dem, you losing dem" << endl;
    }
    else
    {
      cout << "Feelings are fading but dere still be a spark" << endl;
    }
  }
  else if(num > 30)
  {
    if(User == List[Spot].Name1 || User == List[Spot].Name2)
    {
      cout << "You and dem? not much dere, ya'll gotta do someding about it" << endl;
    }
    else
    {
      cout << "Mmm, maybe if dey where stuck in a room togeda dey can become better friends" << endl;
    }
  }
  else if(num > 20)
  {
    if(User == List[Spot].Name1 || User == List[Spot].Name2)
    {
      cout << "No, no you need to no good good togeda" << endl;
    }
    else
    {
      cout << "Dese bonds be shaky, no good togeda" << endl;
    }
  }
  else if(num > 10)
  {
    if(User == List[Spot].Name1 || User == List[Spot].Name2)
    {
      cout << "Mama dont see much going to happen between you and dem" << endl;
    }
    else
    {
      cout << "Dese two have much work to do" << endl;
    }
  }
  else if(num > 0)
  {
    if(User == List[Spot].Name1 || User == List[Spot].Name2)
    {
      cout << "Nope, you'd best look for anoder person to share time wid" << endl;
    }
    else
    {
      cout << "No, No dis will not do, YOU need to make dese two find de good path" << endl;
    }
  }
}