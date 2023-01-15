// Hokeemon.cpp - virtual pet
// 4/6/2018

// Specification 6 - not implemented
// Specification 7 - not implemented

#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
#include<time.h>
#include<string>
#include<vector>
#include<unistd.h>
using namespace std;

class Pet{
  private:
    string name;
    int species;
    int boredom;
    int hunger;
  public:
//___________________________________________________________________________Constructor
    Pet()
    {
      name = "";
      species = 0;
      boredom = 0;
      hunger = 0;
    }
//___________________________________________________________________________FileConstructor
// Specification 3 - constructor (NOT WORKING FOR SOME REASON)
    Pet(string nname, int nspecies, int nboredom, int nhunger)
    {
      name = nname;
      species = nspecies;
      boredom = nboredom;
      hunger = nhunger;
    }
//___________________________________________________________________________TimePass
// Specification 1 - passtime function
    void TimePass()
    {
      srand (time(NULL));
// Feature 1 - random starting stats
      boredom += (rand() % 4);
      hunger += (rand() % 4);
    }
//___________________________________________________________________________Display
    void Display()
    {
      cout << "        >-----------" << name << "-----------<" << endl;
      cout << "   Boredom: ";
        for(int i = 1; i <= boredom; ++i){cout << "*";}// << boredom << endl;
      cout << endl;
      cout << "   Hunger : ";
        for(int i = 1; i <= hunger; ++i){cout << "*";}// << hunger << endl << endl;
      cout << endl << endl << "                  ";
// Feature 2 - specific pet faces for stress level
      if(boredom >= 7 || hunger >= 7)
      {
        switch(species) {
          case 0 : cout << "(=^ ; ｪ ; ^=)" << endl; break;
          case 1 : cout << "(/-(ｴ)-＼)" << endl; break;
          case 2 : cout << "(ＵＴｪＴＵ)" << endl; break;
          case 3 : cout << "／(≧ x ≦)＼" << endl; break;
          case 4 : cout << "｡ﾟ(ﾟ´(00)`ﾟ)ﾟ｡" << endl; break;
          case 5 : cout << "ヾ(￣◇￣)ノ〃" << endl; break;
          case 6 : cout << "八八╭(•̀•̀益•́•́)╮八八 " << endl; break;
        }
      }
      else if(boredom >= 4 || hunger >= 4)
      {
        switch(species) {
          case 0 : cout << "(=^･ｪ･^=)" << endl; break;
          case 1 : cout << "(￣(ｴ)￣)" << endl; break;
          case 2 : cout << "(Ｕ･ｪ･Ｕ)" << endl; break;
          case 3 : cout << "／(=･ x ･=)＼" << endl; break;
          case 4 : cout << "( ´(00)ˋ )" << endl; break;
          case 5 : cout << "(`･Θ･´)" << endl; break;
          case 6 : cout << "八八╭(•̀•̀_•́•́)╮八八 " << endl; break;
        }
      }
      else
      {
        switch(species) {
          case 0 : cout << "(=^･ω･^=)" << endl; break;
          case 1 : cout << "(*￣(ｴ)￣*)" << endl; break;
          case 2 : cout << "(Ｕ^ｪ^Ｕ)" << endl; break;
          case 3 : cout << "／(=^ x ^=)＼" << endl; break;
          case 4 : cout << "(ˆ(oo)ˆ)" << endl; break;
          case 5 : cout << "(`^Θ^´)" << endl; break;
          case 6 : cout << "八八╭(^^ ω ^^)╮八八 " << endl; break;
        }
      }
      cout << endl << endl;
    }
//___________________________________________________________________________Play
    void Play()
    {
      boredom -= 3;
      if(boredom < 0){boredom = 0;}
    }
//___________________________________________________________________________Feed
    void Feed()
    {
      hunger -= 4;
      if(hunger < 0){hunger = 0;}
    }
//___________________________________________________________________________Watch
    void Watch()
    {
      for(int i = 0; i < rand() % 6; ++i)
      {
        TimePass();
      }
    }
//___________________________________________________________________________Death
// Specification 4 - hunger death
// Specification 5 - boredom death
    bool Death()
    {
      if(hunger > 10 || boredom > 20)
      {
        cout << "Your pet wasnt cared for enough, " << name << " has died!" << endl;
        return true;
      }
    }
//___________________________________________________________________________OutFile
    void OutFile(ofstream &outfile){
      outfile << name << ';';
      outfile << species << ';';
      outfile << boredom << ';';
      outfile << hunger << ';';
    }

    ~Pet(){}
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++End of Class
void CheckFile(ifstream &file); // checks and makes file
void Load(ifstream &file); // loads info from file
void Add(); // adds new pet
//****************************************************************************************Main
int main()
{
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

  Pet pet;

  ifstream file;
  file.open("Pet.csv", ios::app);
  CheckFile(file);
  file.close();

  char c;
  bool death = false;

  do{
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
// Feature 3 - Pretty UI
    cout << ">-----------------Hokeemon-----------------<" << endl;
    pet.TimePass();
    pet.Display();
    cout << ">------------------------------------------<" << endl << endl;
// Specification 2 - numeric menu
    cout << "(1)Play - (2)Feed - (3)Watch - (X)Exit\n\n>>ENTER:";
    cin >> c;

    if(c == '1') // Play
    {
      cout << endl;
      pet.Play();
    }

    else if(c == '2') // Feed
    {
      cout << endl;
      pet.Feed();
    }

    else if(c == '3') // Watch
    {
      cout << endl;
      pet.Watch();
    }

    else if(c == 'X' || c == 'x') // Exit
    {
      cout << endl;
      cout << "Would you like to exit? Y/N:";
      cin >> c;
    }

    else
    {
      cin.clear();
      cin.ignore();
    }

    death = pet.Death();
  }while((c != 'Y') && (c != 'y') && (death != true));

  if(death != true)
  {
    ofstream ofile;
    ofile.open("Pet.csv", ios::trunc);
    pet.OutFile(ofile);
    ofile.close();
  }
  else
  {
    ofstream ofile;
    ofile.open("Pet.csv", ios::trunc);
    ofile.close();
  }

  return 0;
}
//-----------------------------------------------------------------------------------Functions
//-------------------------------------------------------------------------------CheckFile
void CheckFile(ifstream &file){
  file.seekg(0, ios::end);
  int length = file.tellg();

  file.seekg(0, ios::beg);

  if(length == 0)
  {
    cout << endl;
    cout << "You dont have a pet!\nPick one now." << endl << endl;
    Add();
  }

  else
  {
    cout << "Loading pet" << endl;
    Load(file);
  }
}
//-------------------------------------------------------------------------------Load
void Load(ifstream &file){
  string name;
  string sspecies;
  string sboredom;
  string shunger;

  getline(file, name, ';');
  getline(file, sspecies, ';');
  getline(file, sboredom, ';');
  getline(file, shunger, ';');

  int species = stoi(sspecies);
  int boredom = stoi(sboredom);
  int hunger = stoi(shunger);

  Pet pet = Pet(name, species, boredom, hunger);
}
//-------------------------------------------------------------------------------Add
void Add(){
  int choice;
  char conf;
  bool check = false;
// Feature 4 - multiple pet options
  string list[] = {"Cat", "Bear", "Dog", "Rabbit", "Pig", "Bird", "Spider"};

  do{
    cout << "Choose a pet" << endl << endl;

    for (int i = 0; i < 7; ++i)
    {
      cout << "[" << i << "]: " << list[i] << endl;
    }

    cout << endl << ">>ENTER:";
    cin >> choice;

    if(choice < 0 || choice > 7)
    {
      cout << choice << " is not a valid pet option";
      cin.clear();
    }
    else
    {
// Feature 5 - checks and confirmations everywhere
      cout << "Are you sure you want a " << list[choice] << "?\n>>ENTER Y/N:";
      cin >> conf;
    }
  }while(conf != 'Y' && conf != 'y');

  cout << "Great! Now you can name your pet" << endl << endl;

  switch(choice){
    case 0 : cout << "   (=^･ω･^=)" << endl; break;
    case 1 : cout << "   (*￣(ｴ)￣*)" << endl; break;
    case 2 : cout << "   (Ｕ^ｪ^Ｕ)" << endl; break;
    case 3 : cout << "   ／(=^ x ^=)＼" << endl; break;
    case 4 : cout << "   (ˆ(oo)ˆ)" << endl; break;
    case 5 : cout << "   (`^Θ^´)" << endl; break;
    case 6 : cout << "   八八╭(^^ ω ^^)╮八八 " << endl; break;
  }

  string name;

  do{
    cin.ignore();
    cout << "Name:";
    getline(cin, name);

    cout << "\nAre you sure, " << name << "?\n>>ENTER Y/N:";
    cin >> conf;
  }while(conf != 'Y' && conf != 'y');

  Pet pet = Pet(name, choice, (rand() % 6), (rand() % 6));
}
