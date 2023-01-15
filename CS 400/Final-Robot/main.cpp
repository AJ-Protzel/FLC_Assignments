#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

void Color(char c);
// Specification - Run 200 individuals then multiple generations.
const int Gen = 3; // # of generations
const int Ind = 6; // # of individual bots

class Map{
  private:
    int ROW;
    int COL;
// Specification - Create a 12(25) by 12(25) room.
    int map[25][25];
  public:
    Map(){
      ROW = 25; 
      COL = 25;
      
      for(int i = 0; i < 25; ++i) //---------------Blank, 0
      {
        for(int ii = 0; ii < 25; ++ii)
        {
          map[i][ii] = 0;
        }
      }
      for(int i = 0; i < 25; ++i) //---------------Bedrock, 1
      {
        map[0][i]  = 1; // Top
        map[i][24] = 1; // Right
        map[24][i] = 1; // Bottom
        map[i][0]  = 1; // Left
      }
// Bonus - Added different terrain.
      for(int i = 0; i < 100; ++i) //---------------Rocks, 2
      {
        int r = rand()%24 + 1;
        int c = rand()%24 + 1;
        
        if(map[r][c] == 0)
          map[r][c] = 2;
      }
// Specification - Populate 40% with batteries.
      for(int i = 0; i < 200; ++i) //---------------Batteries, 3
      {
        int r = rand()%24 + 1;
        int c = rand()%24 + 1;
        
        if(map[r][c] == 0)
        {
          map[r][c] = 3;
        }
        else
        {
          i -= 1;
        }
      }
      for(int i = 0; i < 50; ++i) //---------------Lake, 4
      {
        int r = rand()%24 + 1;
        int c = rand()%24 + 1;
        
        if(map[r][c] == 0)
        {
          map[r][c] = 4;
        }
      }
    }
    ~Map(){}
//______________________________________________Display
// Bonus - Added Display of map.
    void Display(){
      for(int i = 0; i < 25; ++i)
      {
        for(int ii = 0; ii < 25; ++ii)
        {
          if(map[i][ii] == 0) // Blank Space
          {
            cout << "  ";
          }
          else if(map[i][ii] == 1) // Bedrock
          {
            cout << "▀ ";
          }
          else if(map[i][ii] == 2) // Rock
          {
            cout << "▀ ";
            //cout << "[]";
          }
          else if(map[i][ii] == 3) // Battery
          {
            cout << "* ";
          }
          else if(map[i][ii] == 4) // Lake
          {
            cout << "O ";
          }
        }
        cout << endl;
      }
    }
//______________________________________________Start
    int Start(int r, int c)
    {
      return map[r][c];
    }
//______________________________________________Return
    string Return(int r, int c)
    {
      string area = "";
      
      area += to_string(map[r-1][c]); // North
      area += to_string(map[r][c+1]); // East
      area += to_string(map[r+1][c]); // South
      area += to_string(map[r][c-1]); // West
      
      return area;
    }
//______________________________________________Remove
    void Remove(int r, int c)
    {
      map[r][c] = 0;
    }
}map;
//#######################################################End of Map
class Bot{
  friend class Map;
  private:
    int Row; // row cooridnate
    int Col; // column coordinate
    int Dir; // current direction facing
    int Moves; // How many turns the bot has left
    int Power; // how much power it still has
    int Steps; // how many spaces it moved
    int Batteries; // how many batteries it picked up
    vector<string> Gene;
  public:
    Bot(){
      int n;
// Specification - Start on a random square.
      do{
        Row = rand()%24 + 1;
        Col = rand()%24 + 1;
        n = map.Start(Row, Col);
      }while(n != 0);
      
// Specification - Start with 25 moves and 20 power.
      Dir = 0;
      Moves = 10;
      Power = 20;
      Steps = 0;
      Batteries = 0;
      
      SetSensor();
    }
    Bot(vector<string> &NewGene){
      int n;
      do{
        Row = rand()%24 + 1;
        Col = rand()%24 + 1;
        n = map.Start(Row, Col);
      }while(n != 0);
      Dir = 0;
      Moves = 10;
      Power = 20;
      Steps = 0;
      Batteries = 0;
      
      Gene.clear();
      for(int i = 0; i < NewGene.size(); ++i)
      {
        Gene.push_back(NewGene[i]);
      }
    }
    ~Bot(){}
//______________________________________________Return
    int Return(char c)
    {
      if(c == 'M')
      {
        return Moves;
      }
      else if(c == 'P')
      {
        return Power;
      }
      else if(c == 'S')
      {
        return Steps;
      }
      else if(c == 'B')
      {
        return Batteries;
      }
      else if(c == 'D')
      {
        return Dir;
      }
      else if(c == 'R')
      {
        return Row;
      }
      else if(c == 'C')
      {
        return Col;
      }
      else if(c == 'G')
      {
        for(int i = 0; i < Gene.size(); ++i)
        {
          cout << Gene[i] << endl;
        }
        return 0;
      }
    }
//______________________________________________ReturnGene
    string ReturnGene(int i)
    {
      return Gene[i];
    }
//______________________________________________Reset
    void Reset(char c, int i)
    {
      if(c == 'M')
      {
        Moves = i;
      }
      else if(c == 'P')
      {
        Power = i;
      }
      else if(c == 'S')
      {
        Steps = i;
      }
      else if(c == 'B')
      {
        Batteries = i;
      }
    }
//______________________________________________SetSensor
    void SetSensor()
    {
      string s = "0000";
      for(int i = 0; i < 5; ++i) // Sensor
      {
        s[3] = CHAR(i);
        for(int ii = 0; ii < 5; ++ii)
        {
          s[2] = CHAR(ii);
          for(int iii = 0; iii < 5; ++iii)
          {
            s[1] = CHAR(iii);
            for(int iiii = 0; iiii < 5; ++iiii)
            {
              s[0] = CHAR(iiii);
              Gene.push_back(s);
            } 
          }
        }
      }
      for(int i = 0; i < Gene.size(); ++i) // Motion
      {
        for(int u = 0; u < 4; ++u)
        {
          switch(rand()%6)
          {
            case 0: Gene[i] += "F"; break; // Move Forward
            case 1: Gene[i] += "B"; break; // Move Back
            case 2: Gene[i] += "L"; break; // Turn Left
            case 3: Gene[i] += "R"; break; // Turn Right
            case 4: Gene[i] += "A"; break; // Turn Around
            case 5: Gene[i] += "X"; break; // Do Nothing
          }
        }
      }
    }
//______________________________________________CHAR
    char CHAR(int i)
    {
      switch(i)
      {
        case 0: return '0'; break;
        case 1: return '1'; break;
        case 2: return '2'; break;
        case 3: return '3'; break;
        case 4: return '4'; break;
      }
    }
//______________________________________________Run
    void Run()
    {
      do{
      string s = map.Return(Row, Col); // sensor
      for(int i = 0; i < 625 && Moves > 0 && Power > 0; ++i) // search gene for matching sensor reading
      {
        size_t found = Gene[i].find(s);
        found = Gene[i].find(s);
        if(found != std::string::npos) // match found, do motion
        {
          for(int ii = 0; ii < 4 && Moves > 0 && Power > 0; ++ii)
          {
            if(Gene[i][ii + 4] == 'F')      //------Move Forwards
            {
              switch(Dir)
              {
                case 0: Row--; break;
                case 1: Col++; break;
                case 2: Row++; break;
                case 3: Col--; break;
              }
              
              if(s[Dir] == '0'){}
              else if(s[Dir] == '1' || s[Dir] == '2')
              {
                switch(Dir)
                {
                  case 0: Row++; break;
                  case 1: Col--; break;
                  case 2: Row--; break;
                  case 3: Col++; break;
                }
                Steps--;
              }
              else if(s[Dir] == '3')
              {
                Power += 5;
                map.Remove(Row, Col);
              }
              else if(s[Dir] == '4')
              {
                Power--;
              }
              Steps++;
            }
            else if(Gene[i][ii + 4] == 'B') //------Move Backwards
            {
              switch(Dir)
              {
                case 0: Row++; break;
                case 1: Col--; break;
                case 2: Row--; break;
                case 3: Col++; break;
              }
              
              if(s[Dir] == '0'){}
              else if(s[Dir] == '1' || s[Dir] == '2')
              {
                switch(Dir)
                {
                  case 0: Row--; break;
                  case 1: Col++; break;
                  case 2: Row++; break;
                  case 3: Col--; break;
                }
                Steps--;
              }
              else if(s[Dir] == '3')
              {
                Power += 5;
                map.Remove(Row, Col);
              }
              else if(s[Dir] == '4')
              {
                Power--;
              }
              Steps++;
            }
            else if(Gene[i][ii + 4] == 'L') //------Turn Left
            {
              switch(Dir)
              {
                case 0: Dir = 3; break;
                case 1: Dir = 0; break;
                case 2: Dir = 1; break;
                case 3: Dir = 2; break;
              }
            }
            else if(Gene[i][ii + 4] == 'R') //------Turn Right
            {
              switch(Dir)
              {
                case 0: Dir = 1; break;
                case 1: Dir = 2; break;
                case 2: Dir = 3; break;
                case 3: Dir = 0; break;
              }
            }
            else if(Gene[i][ii + 4] == 'A') //------Turn Around
            {
              switch(Dir)
              {
                case 0: Dir = 2; break;
                case 1: Dir = 3; break;
                case 2: Dir = 0; break;
                case 3: Dir = 1; break;
              }
            }
            else if(Gene[i][ii + 4] == 'X') //------Do Nothing
            {
              Power++;
            }
            Power--;
          }
          Moves--;
          i = Gene.size()+1;
        }
      }
      }while(Moves > 0 && Power > 0);
    }
};
//#######################################################End of Bot
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++End of Class
void Load(vector<Bot> &bot);
void Breed(vector<Bot> &bot);
//****************************************************************************************Main
int main()
{
  srand (time(NULL));
  Map map; //map.Display(); cout << endl;
  vector<Bot> bot; // parents vector
  Load(bot);
  
  for(int i = 0; i < Gen; ++i) // generation
  {
cout << "Gen:" << i << ":" << endl;
    for(int ii = 0; ii < Ind; ++ii) // individual
    {
cout << "Ind:" << ii << endl << "  ";

int p;
p = bot[ii].Return('P');
if(p <= 0){Color('r');cout << p << ",";Color('w');}
else{cout << p << ",";}

        bot[ii].Run();

p = bot[ii].Return('P');
if(p <= 0){Color('r');cout << p << ",";Color('w');}
else if(p > 0){Color('g');cout << p << ",";Color('w');}

cout << endl;
    }
cout << endl;
    Breed(bot);
  }
  
  return 0;
}
//-----------------------------------------------------------------------------------Functions
//-------------------------------------------------------------------------------Color
void Color(char c)
{
  if(c == 'w')
  {
    cout << "\033[0m";
  }
  else if(c == 'r')
  {
    cout << "\033[1;31m";
  }
  else if(c == 'g')
  {
    cout << "\033[1;32m";
  }
  else if(c == 'y')
  {
    cout << "\033[1;33m";
  }
  else if(c == 'b')
  {
    cout << "\033[1;34m";
  }
  else if(c == 'm')
  {
    cout << "\033[1;35m";
  }
  else if(c == 'c')
  {
    cout << "\033[1;36m";
  }
}
//-------------------------------------------------------------------------------Load
void Load(vector<Bot> &bot)
{
  for(int i = 0; i < Ind; ++i)
  {
    bot.push_back(Bot());
  }
}
//-------------------------------------------------------------------------------Breed
void Breed(vector<Bot> &bot)
{
  Bot sorted[Ind];
  for(int i = 0; i < Ind; ++i)
  {
    sorted[i] = bot[i];
  }
  
  for(int i = 0; i < Ind; ++i)
  {
    for(int ii = i; ii < Ind; ++ii)
    {
      if(sorted[i].Return('P') <= sorted[ii].Return('P'))
      {
        Bot temp = sorted[i];
        sorted[i] = sorted[ii];
        sorted[ii] = temp;
      }
    }
  }
  bot.clear();
  
  for(int i = 0; i < Ind/2; ++i)
  {
    bot.push_back(sorted[i]);
  }
  
  vector<string> NewGene;
  vector< vector<string> > GeneList;
  for(int i = 0; i < bot.size()-1; i += 2)
  {
    for(int ii = 0; ii < 624; ii += 2)
    {
      if(rand()%2 == 0)
      {
        NewGene.push_back(sorted[i].ReturnGene(ii));
      }
      else
      {
        NewGene.push_back(sorted[i+1].ReturnGene(ii));
      }
    }
    GeneList.push_back(NewGene);
    NewGene.clear();
    
    for(int ii = 0; ii < 624; ii += 2)
    {
      if(rand()%2 == 0)
      {
        NewGene.push_back(sorted[i].ReturnGene(ii));
      }
      else
      {
        NewGene.push_back(sorted[i+1].ReturnGene(ii));
      }
    }
    GeneList.push_back(NewGene);
    NewGene.clear();
  }
  
  for(int i  = 0; i < GeneList.size(); ++i)
  {
    bot.push_back(Bot(GeneList[i]));
  }
  NewGene.clear();
  GeneList.clear();
}