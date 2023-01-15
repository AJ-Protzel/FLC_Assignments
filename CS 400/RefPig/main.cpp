#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<fstream>
using namespace std;
//Specification 5 - Have the program create a log file which details all the moves for both players.
ofstream ofile("Log.txt");

// Specification 1 - Create an abstract class called Player. It will have 2 child classes:Computer and Human.
class Player{
  protected:
    string name;
    int turntotal;
    int total;
    
  public:
    bool Roll();
    void Hold();
    void Play();
    string Name();
    int TurnTotal();
    int Total();
    void Dice(int r1, int r2);
};
//-------------------------------------------------------------------------------Player Functions
//_______________________________________________________________Roll
// Specification 2 - Create a function called Dice and use composition with the other classes.
  bool Player::Roll(){
    ofile << "Rolled" << endl;
    int r1 = (rand() % 6) + 1;
    int r2 = (rand() % 6) + 1;
    
    turntotal += (r1 + r2);
    Dice(r1, r2);
    if(r1 == 1 || r2 == 1)
    {
      turntotal = 0;
      cout << "                  }}Bust{{" << endl << endl;
      ofile << "Busted" << endl;
      return false;
    }
    return true;
  }
//_______________________________________________________________Hold
  void Player::Hold(){
    total += turntotal;
    cout << "                  }}Hold{{" << endl << endl;
    ofile << "Held" << endl;
    turntotal = 0;
  }
//_______________________________________________________________Play
// Specification 4 - Make a simple AI with a random number. Each decision the computer rolls, 1-3 hold, 4-6 roll again.
  void Player::Play(){
    bool turn = true;
    int num;
    
    do{
      num = (rand() % 100);
      
      if(num >= 25)
      {
        turn = Roll();
      }
      else if(num < 25)
      {
        Hold();
        turn = false;
      }
    }while(turn != false);
  }
//_______________________________________________________________Name
  string Player::Name(){return name;}
//_______________________________________________________________TurnTotal
  int Player::TurnTotal(){return turntotal;}
//_______________________________________________________________Total
  int Player::Total(){return total;}
//_______________________________________________________________Dice
// Feature - Nice dice display
  void Player::Dice(int r1, int r2){
    cout << "            _________  _________" << endl; // top
    switch (r1) // first row
    {
      case 1: cout << "            |       |  "; break;
      case 2: cout << "            | o     |  "; break;
      case 3: cout << "            | o     |  "; break;
      case 4: cout << "            | o   o |  "; break;
      case 5: cout << "            | o   o |  "; break;
      case 6: cout << "            | o   o |  "; break;
    }
    switch (r2)
    {
      case 1: cout << "|       |" << endl; break;
      case 2: cout << "| o     |" << endl; break;
      case 3: cout << "| o     |" << endl; break;
      case 4: cout << "| o   o |" << endl; break;
      case 5: cout << "| o   o |" << endl; break;
      case 6: cout << "| o   o |" << endl; break;
    }
    switch (r1) // middle row
    {
      case 1: cout << "            |   o   |  "; break;
      case 2: cout << "            |       |  "; break;
      case 3: cout << "            |   o   |  "; break;
      case 4: cout << "            |       |  "; break;
      case 5: cout << "            |   o   |  "; break;
      case 6: cout << "            | o   o |  "; break;
    }
    switch (r2)
    {
      case 1: cout << "|   o   |" << endl; break;
      case 2: cout << "|       |" << endl; break;
      case 3: cout << "|   o   |" << endl; break;
      case 4: cout << "|       |" << endl; break;
      case 5: cout << "|   o   |" << endl; break;
      case 6: cout << "| o   o |" << endl; break;
    }
    switch (r1) // bottom row
    {
      case 1: cout << "            |       |  "; break;
      case 2: cout << "            |     o |  "; break;
      case 3: cout << "            |     o |  "; break;
      case 4: cout << "            | o   o |  "; break;
      case 5: cout << "            | o   o |  "; break;
      case 6: cout << "            | o   o |  "; break;
    }
    switch (r2)
    {
      case 1: cout << "|       |" << endl; break;
      case 2: cout << "|     o |" << endl; break;
      case 3: cout << "|     o |" << endl; break;
      case 4: cout << "| o   o |" << endl; break;
      case 5: cout << "| o   o |" << endl; break;
      case 6: cout << "| o   o |" << endl; break;
    }
    cout << "            |_______|  |_______|" << endl; // bottom
  }

//-----------------------------------------------------------------------------------Child Classes
//-------------------------------------------------------------------------------User
class User : public Player{
  public:
    User(string n){
      name = n;
      turntotal = 0;
      total = 0;
    }
    ~User(){}
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++End of Class
void AddPlayers(vector<Player*> &players);
//****************************************************************************************Main
int main(){srand (time(NULL));
  vector<Player*> players;
  AddPlayers(players);
  
  bool end = false;
  bool turn = true;
  int round = 0;
  char c;
  int num;
  
  do{
//    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
//    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
//    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
//    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
//    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
//    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
//    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
// Feature - Pretty UI
    round++;
    cout << "  >>>=============Round " << round << "=============<<<" << endl;
    ofile << ">>>=============Round " << round << "=============<<<" << endl;
    cout << "                 Total:[";num = players[0]->Total();cout << num << "]" << endl;
    do{
      string playername = players[0]->Name();
      ofile << ">--------------" << playername << "--------------<" << endl;
      
      cout << "               Turn Total:[";num = players[0]->TurnTotal();cout << num << "]" << endl;
      cout << "             (+)Roll    (=)Hold" << endl;
      cout << "   >>:";cin >> c;
    
      if(c == '+') // roll
      {
        turn = players[0]->Roll();
      }
      else if(c == '=') // hold
      {
        players[0]->Hold();
      }
      else // clear input
      {
        cin.clear();
        cin.ignore();
      }
    }while(c != '=' && turn != false);
    
    for(int i = 1; i < players.size(); ++i)
    {
      string ainame = players[i]->Name();
      cout << "    >--------------" << ainame << "--------------<" << endl;
      ofile << ">--------------" << ainame << "--------------<" << endl;
      cout << "                 Total:[";num = players[i]->Total();cout << num << "]" << endl;
      
      players[i]->Play();
    }
    
    for(int i = 0; i < players.size(); ++i)
    {
      if(players[i]->Total() >= 100)
      {
// Specification 3 - Use operator overloading where appropriate.
        string name = players[i]->Name();
        cout << name << ", Won the game!";
        ofile << name << ", Won the game!";
        end = true;
        ofile.close();
      }
    }
    
  }while(end == false);
  
  return 0;
}
//-----------------------------------------------------------------------------------Functions
//-------------------------------------------------------------------------------AddPlayers
void AddPlayers(vector<Player*> &players)
{
// Feature - random names for ai;
  const string names[]= {"Dreama", "Phylis", "Shenika", "Mel", "Gregory", "Dalia", "Matthew", "Timika", "Emmy", "Jules", "Omer", "Stephani", "Lenard", "Morton", "Domenica", "Delaine", "Brinda", "King", "Evangeline", "Jann", "Laurene", "Valorie", "Dennise", "Evelina", "Stormy", "Thomasena", "Clifford", "Launa", "Mafalda", "Nada", "Leeanne", "Adan", "Clemencia", "Leonie", "Agripina", "Earlie", "Edelmira", "Marlon", "Serena", "Eunice", "Eboni", "Wes", "David", "Ronna", "Raymonde", "Thea", "Rosendo", "Brigid", "Eugena", "Clifton"};
  
  string n;
  cout << "Hello, what is your name?\n>>ENTER:";
  getline(cin, n);
  players.push_back(new User(n));
  
  cin.clear();
//  cin.ignore();
  
  int num;
// Feature - Module number of ai combatants
  cout << "\nAnd how many AI would you like to play with? " << n << ".\n>>ENTER:";
  cin >> num;
  
  for(int i = 0; i < num; ++i)
  {
    int a = (rand() % 50);
    players.push_back(new User(names[a]));
  }
  cout << "\n        Alright, the table is set.\n     May the odds be ever in your favor" << endl << endl;
}