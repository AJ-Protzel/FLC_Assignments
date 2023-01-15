//MadLibs.txt -- madlibs
//A.Protzel, p360 
//10/11/2017 - 10/20/2017

//prompt the user for every CAPITALIZED word. Then, display the below text, 
//replacing the capitalized word with the word the user typed in. 
//Collect all the data, then display the text 
//(do not ask a question and then display a sentence).

//A Day In The Life Of a College Student
//======================================
//Every TIME-SPAN, I wake up and get off my NOUN. I don‘t
//always have time to VERB a shower, but I always make sure to
//VERB my hair. Once that‘s done I get some NOUN (PLURAL OR
//SINGULAR), and then it‘s off to my first NOUN. I often get
//caught VERB ENDING IN ING in class. No one likes it when
//the 2 WORD OCCUPATION gives a surprise NOUN. My second class
//is NOUN Theory. Dr. FAMOUS PERSON is incredibly ADJECTIVE,
//but I never VERB her because of her thick NOUN. Her NOUN
//(PLURAL), however, are really ADJECTIVE. After lunch, I have
//no more NOUN (PLURAL) and I‘m free to VERB PREPOSITION my
//friends. This is right around INTEGER O’clock. Before I go
//to bed I VERB a little bit, in my room, FLOAT LETTER.

//Use the specification numbers, names and parameters from the data dictionary below.
//Don’t worry about testing for specific types of words (ie plural, etc. etc.). 
//However, pay attention to the word count.

//Use the standard program constraints we have been discussing.
//Make sure you prompt all at once, then you display the paragraph with the filled in text.
//Include a simple menu. Option 1 explains what Mad Libs are, 2 -executes the Mad Lib, 3 - quits.

//credit to site http://www.madtakes.com/libs/187.html for extra madlib

// Bonus 1 - Added a second madlibs option 
// Bonus 2 - Made user experience easier

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

void MadLibs();
void School();
void Camp();

int main()
{
  bool check = false;
  string choice;
  char quite;
// Bonus 2 - added ----- lines and >>ENTER: things for easier user reading   
//dowhile loop for player choice of what they want to do 
  do{
    cout << "\n-----------------------------------------";
    cout << "\nWhat would you like to do?\n[1]:Explanation\n[2]:Play\n[3]:Quite\n>>ENTER:";
    getline(cin, choice);
    
    if(choice == "1")
    {
      cout << "\nYou will be prompted to enter words and numbers that will then be put into one large story for your enjoyment" << endl;
    }
    else if(choice == "2")
    {
      MadLibs();
    }
    else if(choice == "3")
    {
      cout << "\nWhould you like to quite playing?\n>>ENTER Y/N:";
      cin >> quite;
      cin.ignore();
      
      if(quite == 'Y' || quite == 'y')
      {
        check = true;
      }
    }
    else 
    {
      cout << "\nThats not a valid option" << endl;
    }
  }while(check == false);
  
  cout << "\n\nThanks for playing";
  
  return 0;
}

void MadLibs()//----------------------------------------------------------------------------------------------------choices
{
  bool check = false;
  string choice;
  
  do{
    cout << "\nWhich MadLib would you like to do?\n[1]:Day of school\n[2]:Letter from camp\n>>ENTER:";
    getline(cin, choice);
    
    if(choice == "1")
    {
      School();
      check = true;
    }
    else if(choice == "2")
    {
      Camp();
      check = true;
    }
    else 
    {
      cout << "\nThats not a valid option" << endl;
    }
    
  }while(check == false);
}

void School()//----------------------------------------------------------------------------------------------------school
{
  string Answer;
  int size = 19;
  srand ( time(NULL) ); //initialize the random seed
  const string VerbRand[3] = {"comb" , "paint" , "remove"};

//array of string to be said for inputs
  string Ask[size] = {"A Time-Span" , "A Noun" , "A Verb" , "One:Breakfast, Fishes, Copper Coins" , "A Noun" , "A Verb Ending In ING" , "2 Word Occupation" , "A Noun" , "A Noun" , "A Famouse Persons Name" , "An Adjective" , "A Verb" , "A Noun" , "A Noun(Plural)" , "An Adjective" , "A Noun(Plural)" ,  "A Verb Prepostion" ,  "A Verb" , "A Single Letter"};
  
//array of answers to be put into the full dialog
  string Ans[size];
  
  cout << "\nGreat, lets get started." << endl;
  
//for loop to continuously ask for nouns and such
  for(int i = 0; i < size; ++i)
  {
    cout << "\n[" << i + 1 << "]:Enter " << Ask[i] << "\n>>ENTER:";
    getline(cin, Answer);
    Ans[i] = Answer;
  }
  
  int VRandIndex = rand() % 3; //generates a random number between 0 and 2
  int RandInt = rand() % 12; //generates a random number between 0 and 11 then + 1 in cout
  float RandFloat = 14 * ((((float) rand()) / (float) RAND_MAX)); //generates a random number between 0.0 - 15.0 set precision in cout
  
  cout << "\nEvery [" << Ans[0] << "], I wake up and get off my [" << Ans[1] << "]. I don‘t always have time to [" << Ans[2] << "] a shower, but I always make sure to " << VerbRand[VRandIndex] << " my hair. Once that‘s done I get some [" << Ans[3] << "], and then it‘s off to my first [" << Ans[4] << "]. I often get caught [" << Ans[5] << "] in class. No one likes it when the [" << Ans[6] << "] gives a surprise [" << Ans[7] << "]. My second class is [" << Ans[8] << "] Theory. Dr. [" << Ans[9] << "] is incredibly [" << Ans[10] << "], but I never [" << Ans[11] << "] her because of her thick [" << Ans[12] << "]. Her [" << Ans[13] << "], however, are really [" << Ans[14] << "]. After lunch, I have no more [" << Ans[15] << "] and I‘m free to [" << Ans[16] << "] my friends. This is right around " << RandInt + 1 << ". Before I go to bed I [" << Ans[17] << "] a little bit, in my room, " << setprecision (1) << fixed << RandFloat + 1 << " [" << Ans[18] << "]." << endl;
}
// Bonus 1 - Added another madlibs, can this count as 2 bonuses?
void Camp()//-----------------------------------------------------------------------------------------------------------camp
{
  string Answer;
  int size = 16;

//array of string to be said for inputs
  string Ask[size] = {"Name of a Person" , "Adjective" , "Adjective" , "Adjective" , "Name of a Person " , "Adjective" , "Adjective" , "Verb ending in ED" , "Body Part" , "Verb ending in ING" , "Noun(Plural)" , "Noun" , "Adverb" , "Verb" , "Verb" ,};
  
//array of answers to be put into the full dialog
  string Ans[size];
  
  cout << "\nGreat, lets get started." << endl;
  
//for loop to continuously ask for nouns and such
  for(int i = 0; i < size; ++i)
  {
    cout << "\n[" << i + 1 << "]:Enter a " << Ask[i] << "\n>>ENTER:";
    getline(cin, Answer);
    Ans[i] = Answer;
  }

  cout << "\nDear [" << Ans[0] << "],\nI am having a [" << Ans[1]  << "] time at camp. The counselour is [" << Ans[2] << "] and the food is [" << Ans[3] << "]. I met ["<< Ans[4] << "] and we became [" << Ans[5] << "] friends. Unfortunately, [" << Ans[6] << "] is [" << Ans[7] << "] and I [" << Ans[8] << "] my [" << Ans[9] << "] so we couldn`t go [" << Ans[10] << "] like everybody else. I need more [" << Ans[11] << "] and a [" << Ans[12] << "] sharpener, so please [" << Ans[13] << "] [" << Ans[14] << "] more when you [" << Ans[15] << "] back." << endl;
}