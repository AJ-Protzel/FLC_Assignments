//Pig.cpp -- Dice roller



//1/16/2018



//Players take turns rolling a die. The die determines how many points they get. 

//You may get points each turn your roll (turn points), 

//you also have points for the entire game (grand points). 

//The first player with 100 grand points is the winner. 



//The rules are as follows: Each turn, the active player faces a decision (roll or hold):

//  Roll the die. If it’s is a: 1: You lose your turn, no points are added to your grand total.

//                              2-6: The number you rolled is added to your turn total.

//  Hold: Your turn total is added to your grand total. It’s now the next player’s turn.



//Make a simple AI with a random number. Each decision the computer rolls, 1-3 hold, 4-6 roll again.

//Run the program in a main event loop. Prompt the player when the game ends if they want to play another game. 

//Use a ’y’ or ’n’ prompt to stop playing games.

//Excluding the Program Greeting, use at least one function call in your code (Don’t forget to use the function prototype.).

//Use a time value to generate a new random number seed every time you play.



// Specification 1 - 



#include <iostream>

#include <stdlib.h>

#include <time.h>

#include <iomanip>

#include <string>

using namespace std;



struct Players

{

  string Name;

  int TurnCount; // number in turn

  int GrandCount; // number in grand

  bool AI = false; // tells if player is ai

};



const int SIZE = 10;

Players* Player = new Players[SIZE];



// Specification 3 - Assorted functions and called functions

void Game(); //starts main play functions

  int SetPlayers(); // sets the number of players and ai, returns number of players

  void Roll(int); // rolls die

  void Hold(int); // adds turn to grand counts

void Dice(int); // display dice thrown

void Enemy(int); // enemy move

bool End(int, int); //checks for a winner



// Specification 2 - Main and exit prompt

int main()

{

  // Specification 4 - Time seed 

  srand (time(NULL));

  bool check = false;

  string choice;

  char exit;

  cout << "Welcome to Pig";



// Feature 1 - Pretty User Interface

  do{

    cout << "\n___________________________________" << endl;

    cout << "\nWhat would you like to do?\n[1]:Explanation\n[2]:Play\n[3]:Exit\n>>ENTER:";

    getline(cin, choice);

    

    if(choice == "1")

    {

      cout << "\nThe rules are as follows:\nEach turn, the active player faces a decision (roll or hold):" << endl;

      cout << "Roll: If it’s is a: 1- You lose your turn, no points are added to your grand total.\n                    2-6- The number you rolled is added to your turn total.\nHold: Your turn total is added to your grand total. It’s now the next player’s turn." << endl;

    }

    else if(choice == "2")

    {

      Game();

    }

    else if(choice == "3")

    {

      cout << "\nWhould you like to exit the game?\n>>ENTER Y/N:";

      cin >> exit;

      cin.ignore();



      if(exit == 'Y' || exit == 'y')

      {

        check = true;

      }

    }

    else

    {

      cout << "\nThats not a valid option" << endl;

    }

  }while(check == false);



  cout << "\n\nThanks for playing" << endl << endl;



  return 0;

}

//---------------------------------------------------------------------------------------------------------------------------Functions

//---------------------------------------------------------------------------------------------------------------------------Game

void Game()

{

  bool end = false;



  cout << endl;

  int players = SetPlayers();

  cout << endl << endl;



  cout << string( 100, '\n' );



  do{

    for(int i = 0; i < players; ++i)

    {

      int turn;

      bool check = false;



      cout << "--------------------------" << endl;



      if(Player[i].AI != true)

      {

// Feature 2 - Seperate name displays for users and AI

        cout << "      Player: " << Player[i].Name << endl;

        cout << "--------------------------" << endl << endl;



        cout << "Grand Total: [" << Player[i].GrandCount << "]" << endl;

        cout << "Turn Total: [" << Player[i].TurnCount << "]" << endl << endl;

        cout << "What would you like to do?\n[1]:Roll\n[2]:Hold\n>>ENTER:";

        do{

          cin >> turn;



          if(turn == 1)

          {

            Roll(i);

            check = true;

          }

          else if(turn == 2)

          {

            Hold(i);

            check = true;

          }

          else

            cout << "\nThats not a valid option" << endl;

        }while(check == false);

      }

      else

      {

        cout << "      Player: " << Player[i].Name << " " << i << endl;

        cout << "--------------------------" << endl << endl;



        cout << "Grand Total: [" << Player[i].GrandCount << "]" << endl;

        cout << "Turn Total: [" << Player[i].TurnCount << "]" << endl << endl;



        Enemy(i);

      }



      end = End(Player[i].GrandCount, i);

      if(end == true)

      {

        break;

      }

    }

  }while(end == false);

  cin.ignore();

}

//---------------------------------------------------------------------------------------------------------------------------SetPlayers

int SetPlayers()

{

  int number;

  cout << "How many players (Max of 10)\n>>ENTER:";

  cin >> number;



  for(int i = 0; i < number; ++i)

  {

    cout << "\nEnter player [" << i + 1 << "]'s name (Enter 'ai' to set as computer)\n>>ENTER:";

    cin >> Player[i].Name;



    if(Player[i].Name == "ai" || Player[i].Name == "AI" || Player[i].Name == "Ai" || Player[i].Name == "aI")

    {

      Player[i].AI = true;

    }



    Player[i].TurnCount = 0;

    Player[i].GrandCount = 0;

  }



  return number;

}



//---------------------------------------------------------------------------------------------------------------------------Roll

void Roll(int i)

{

  int roll = rand() % 6;

  if(roll == 1)

  {

    Player[i].TurnCount = 0;

  }

  else

  {

    Player[i].TurnCount = roll + 1;

  }



  cout << endl << Player[i].Name << " rolled a " << endl;

  Dice(roll);



  cout << "\nTurn Total = [" << Player[i].TurnCount << "]" << endl << endl;

}



//---------------------------------------------------------------------------------------------------------------------------Hold

void Hold(int i)

{

  Player[i].GrandCount += Player[i].TurnCount;

  Player[i].TurnCount = 0;



  cout << "\n>Grand Total = [" << Player[i].GrandCount << "]" << endl;

  cout << ">Turn Total = [" << Player[i].TurnCount << "]" << endl << endl;

}



// Feature 3 - Dice art

//---------------------------------------------------------------------------------------------------------------------------Dice

void Dice(int roll)

{

  switch (roll)

  {

  //case 0: cout << "_________\n| o o o |\n| o o o |   \n| o o o |\n|_______|" << endl; break;

    case 0: cout << "_________\n|       |\n|   o   |  1\n|       |\n|_______|" << endl; break;

    case 1: cout << "_________\n| o     |\n|       |  2\n|     o |\n|_______|" << endl; break;

    case 2: cout << "_________\n| o     |\n|   o   |  3\n|     o |\n|_______|" << endl; break;

    case 3: cout << "_________\n| o   o |\n|       |  4\n| o   o |\n|_______|" << endl; break;

    case 4: cout << "_________\n| o   o |\n|   o   |  5\n| o   o |\n|_______|" << endl; break;

    case 5: cout << "_________\n| o   o |\n| o   o |  6\n| o   o |\n|_______|" << endl; break;

  }

}



// Specification 1 - Enemy AI

//---------------------------------------------------------------------------------------------------------------------------Enemy

void Enemy(int i)

{

  int turn = rand() % 6;



  if(turn >= 0 && turn <= 2)

  {

    cout << Player[i].Name << " Held" << endl << endl;



    Hold(i);

  }

  else if(turn >= 3 && turn <= 5)

  {

    cout << Player[i].Name << " Rolled" << endl << endl;



    Roll(i);

  }

}



// Feature 4 - Auto end game checker and prompts to play again or exit

//---------------------------------------------------------------------------------------------------------------------------End

bool End(int score, int i)

{

  if(score >= 100)

  {

    cout << "\n  <<" << Player[i].Name << " won the game!>>" << endl << endl;

    return true;

  }

  else

    return false;

}