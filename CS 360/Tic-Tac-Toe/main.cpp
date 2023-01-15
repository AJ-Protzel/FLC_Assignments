//TicTacToe.txt -- Tic Tac Toe against computer
//A.Protzel, p360 
//10/18/2017 - 10/30/2017

//You are going to program a game of tic-tac-toe. The human will play the computer. Use the following pseudocode to guide your design:

//Create an empty Tic_Tac_Toe board
//Display the Game Instructions
//Determine who goes first
//Display the board
//While nobody has won and it’s not a tie

//If it’s the human’s turn
//Get the human’s move
//Update the board with the human’s move

//Otherwise calculate the computer’s move
//Update the board with the computer’s move
//Display the board
//Switch turns
//Congratulate the winner or declare a tie

//Add statements to the main() function to do the following:
//• Randomly determine who will go first.
//• Filter the input for valid numbers.

//Constraints.
//• Use whatever method is expedient to generate the computer moves; this isn’t an AI class.
//• Use functions whenever possible to modularize your code.
//• Create a simple menu, 1 - Explain Game, 2 - Play, 3 - Quit. Only allow these choices.

// Bonus 1 - line 203 added reset function
// Bonus 2 - line 59 Added greeting
// Bonus 3 - line 54 Made a comfortable UI for player, such as ------ lines and extra spaces to differentiate TTT boards

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

void Game(); //starts main play functions
void Board(); //display board
void Enemy(); //enemy move
void Reset(); //resets game 
bool End(); //checks for a draw or winner

const int ROW = 3;
const int COL = 3;

char board[ROW][COL] = {};

int limit = 0;
// Bonus 3 - Made a comfortable UI for player 
int main()
{
  bool check = false;
  string choice;
  char quite;
// Bonus 2 - Added greeting
  cout << "Welcome to Tic Tac Toe";

  do{
    cout << "\n-----------------------------------------";
    cout << "\nWhat would you like to do?\n[1]:Explanation\n[2]:Play\n[3]:Quite\n>>ENTER:";
    getline(cin, choice);
    
    if(choice == "1")
    {
      cout << "\nYou will be presented a Tic Tac Toe board and be prompted to make a move, the computer then makes a move, this is repeated until a winner is decided or is a cats game." << endl;
    }
    else if(choice == "2")
    {
      Game();
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
//---------------------------------------------------------------------------------------------------------------------------Functions
//---------------------------------------------------------------------------------------------------------------------------Game
void Game()
{
  bool end = false;
  Reset();
  
  int posX;
  int posY;
  
  srand (time(NULL));
  int turn = rand() % 2;
  if(turn == 1)
  {
    Enemy();
  }

  while((limit < 9) && (end == false))
  {
    Board();
  
    bool checkx = false;
    bool checky = false;
    bool checkspace = false;
    
    do{
      do{
        cout << "\n[X]ENTER:";
        cin >> posX;
    
        if(posX < 4 && posX > 0)
        {
          checkx = true;
        }
        else
        {
          cout << "Thats not a valid space";
        }
      }while(checkx == false);
  
      do{
        cout << "[Y]ENTER:";
        cin >> posY;
    
        if(posY < 4 && posY > 0)
        {
          checky = true;
        }
        else
        {
          cout << "Thats not a valid space";
        }
      }while(checky == false);
      
      if((board[posX - 1][posY - 1] != 'X') && (board[posX - 1][posY - 1] != 'O'))
      {
        checkspace = true;
      }
      else
      {
        cout << "\n>>That space has already been taken<<\n";
      }
    }while(checkspace == false);
  
    board[posX - 1][posY - 1] = 'X';
  
    limit++;
    
    if(limit != 9)
    {
      Enemy();
      end = End();
    }
    else 
    {
      Board();
      cout << "\n\nIt's a cats game" << endl;
    }
  }
  cin.ignore();
}

//---------------------------------------------------------------------------------------------------------------------------Board
void Board()
{
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;//Break line

  cout << " x_1___2___3__\n";
  cout << "y| " << board[0][0] << " | " << board[1][0] << " | " << board[2][0] << " |\n";
  cout << "1|___|___|___|\n";
  cout << " | " << board[0][1] << " | " << board[1][1] << " | " << board[2][1] << " |\n";
  cout << "2|___|___|___|\n";
  cout << " | " << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << " |\n";
  cout << "3|___|___|___|\n";
}

//---------------------------------------------------------------------------------------------------------------------------Enemy
void Enemy()
{
  srand (time(NULL));
  bool checkspace = false;
  int posx;
  int posy;
  
  do{
    posx = rand() % 3;
    posy = rand() % 3;
    
    if((board[posx][posy] != 'X') && (board[posx][posy] != 'O'))
    {
      checkspace = true;
    }
  }while(checkspace == false);
  
  board[posx][posy] = 'O';
  
  limit++;
}
// Bonus 1 - added a reset so player can stay in "game"
//---------------------------------------------------------------------------------------------------------------------------Reset
void Reset()
{
  for(int i = 0; i < 3; ++i)
  {
    for(int ii = 0; ii < 3; ++ii)
    {
      board[i][ii] = {' '};
    }
  }
  limit = 0;
}

//---------------------------------------------------------------------------------------------------------------------------Win Checker
bool End()
{
  for(int i = 0; i < 3; i++)//Row, Colm
  {
    if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
    {
      if(board[i][0] == 'X')
      {
        Board();
        cout << "\nYou Won, Congratulations" << endl;
        return true;
      }
      else if(board[i][0] == 'O')
      {
        Board();
        cout << "\nYou Lost" << endl;
        return true;
      }
    }
    else if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
    {
      if(board[0][i] == 'X')
      {
        Board();
        cout << "\nYou Won, Congratulations" << endl;
        return true;
      }
      else if(board[0][i] == 'O')
      {
        Board();
        cout << "\nYou Lost" << endl;
        return true;
      }
    }
  }
  if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
  {
    if(board[0][0] == 'X')
      {
        Board();
        cout << "\nYou Won, Congratulations" << endl;
        return true;
      }
    else if(board[0][0] == 'O')
      {
        Board();
        cout << "\nYou Lost" << endl;
        return true;
      }
  }
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
	  if(board[0][2] == 'X')
      {
        Board();
        cout << "\nYou Won, Congratulations" << endl;
        return true;
      }
    else if(board[0][2] == 'O')
      {
        Board();
        cout << "\nYou Lost" << endl;
        return true;
      }
	}
	return false;
}