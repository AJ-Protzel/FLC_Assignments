// ToDoList.cpp
// 3/23/2018

#include<fstream>
#include<iomanip>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<time.h>
using namespace std;

class Task{
  private:
    string date;
    string task;
  public:
//___________________________________________________________________________Constructor
    Task(){
      date = "";
      task = "";
    }
//___________________________________________________________________________File Constructor
    Task(string d, string t){
      date = d;
      task = t;
    }
//___________________________________________________________________________Setter/Display
    friend ostream &operator<<(ostream &output, const Task &T){ 
      output << "(" << T.date << ") + " << T.task;
    }
//___________________________________________________________________________Getter
    friend istream &operator>>(istream  &input, Task &T){ 
      input >> T.task;
      return input;            
    }
//___________________________________________________________________________OutFile
// Specification 4 - Save the item so it persists when the program is restarted.
    void OutFile(ofstream &outfile, vector<Task> &List){
      for(int i = 0; i < List.size(); ++i)
      {
        outfile << List[i].date << ';' << List[i].task << ';';
      }
    }
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++End of Class
vector<Task> List;

void CheckFile(ifstream &file);
void LoadVector(ifstream &file);
void OutFile(ofstream &ofile);
void Body();
void Display();
void Add();
void Edit();
void Remove();
string Date();
//#######################################################End of MAP
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++End of Class
//***********************************************************************************Main
int main()
{
  Task task;

  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
// Feature 1 - Existing file checker
  ifstream file;
  file.open("To_Do_List.csv", ios::app);
  CheckFile(file);
  file.close();

  Body();
  
  ofstream ofile;
  ofile.open("To_Do_List.csv", ios::trunc);
  task.OutFile(ofile, List);
  ofile.close();

  return 0;
}
//-----------------------------------------------------------------------------------Functions
//-------------------------------------------------------------------------------Body
void Body()
{
  bool check = false;
  char c;

  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
// Feature 2 - Pretty UI
  cout << ">-----------------To Do List-----------------<" << endl;
  cout << "          >----------------------<" << endl;
// Specification 2 - Allow the user to display all tasks with a ? symbol. Overload the « operator.
// Feature 4 - Made auto display therefore no need for ? command
  Display();
  cout << "          >----------------------<" << endl << endl;

  cout << "     (+)Add, (*)Edit, (-)Remove, (X)Exit" << endl;

  cout << ">>:";
  cin >> c;
// Specification 1 - Allow the user to enter tasks with a "+" symbol.
  if(c == '+') // add
  {
    cout << endl;
    cin.ignore();
    Add();
    Body();
  }
// Feature 3 - Edit command
  else if(c == '*') // edit
  {
    cout << endl;
    Edit();
    Body();
  }
// Specification 3 - Allow the user to remove a task with a "-" symbol.
  else if(c == '-') // Remove
  {
    cout << endl;
    Remove();
    Body();
  }
// Specification 5 - Create a command symbol to quit the program.
  else if(c == 'x' || c == 'X') // Exit
  {
    cout << "\nWould you like to exit? Y/N:";
    cin >> c;
      
    if(c != 'Y' && c != 'y')
    {
      Body();
    }
  }

  else // checks input
  {
    cin.clear();
    cin.ignore();
// Specification 6 - Recursive Body Function
    Body();
  }
}
//-------------------------------------------------------------------------------CheckFile
void CheckFile(ifstream &file){
  file.seekg(0, ios::end);
  int length = file.tellg();

  file.seekg(0, ios::beg);

  if(length == 0)
  {
    cout << endl;
    cout << "You have nothing to do!\nAdd one now." << endl << endl;

    Add();
  }

  else
  {
    LoadVector(file);
  }
}
//-------------------------------------------------------------------------------LoadVector
void LoadVector(ifstream &file){
  string date;
  string todo;

  while(file)
  {
    getline(file, date, ';');
    getline(file, todo, ';'); 

    if(!file.eof())
    {
      Task task = Task(date, todo);
      List.push_back(task);
    }
  }
}
//-------------------------------------------------------------------------------Display
void Display(){
  for(int i = 0; i < List.size(); ++i)
  {
    cout << "[" << i << "] " << List[i] << endl;
  }
}
//-------------------------------------------------------------------------------Add
void Add(){
  string todo;
  string today;
  char confirm;
  bool check = false;

  do{
    cout << "ENTER:";
    getline(cin, todo);
// Feature 5 - confirmations for adds and changes
    cout << "\nConfirm Y/N:";
    cin >> confirm;
    cin.ignore();

    if(confirm == 'Y' || confirm == 'y')
    {
      check = true;
    }
  }while(check == false);

  today = Date();

  Task task = Task(today, todo);

  List.push_back(task);
}
//-------------------------------------------------------------------------------Edit
void Edit(){
  string today;
  string todo;

  int selection;
  bool check = false;
  char confirm;

  do{
    cout << "Select index\n>>ENTER:";
    cin >> selection;

    cout << "\nConfirm Y/N:";
    cin >> confirm;

    if(confirm == 'Y' || confirm == 'y')
    {
      check = true;
    }
    else
    {
      cin.ignore();
    }
  }while(check == false || selection < 0 || selection > List.size());

  cin.ignore();

  cout << "ENTER:";
  getline(cin, todo);

  today = Date();

  Task task = Task(today, todo);
  List[selection] = task;
}
//-------------------------------------------------------------------------------Remove
void Remove(){
  int selection;
  bool check = false;
  char confirm;

  do{
    cout << "Select index\n>>ENTER:";
    cin >> selection;

    cout << "\nConfirm Y/N:";
    cin >> confirm;

    if(confirm == 'Y' || confirm == 'y')
    {
      check = true;
    }
    else
    {
      cin.ignore();
    }
  }while(check == false || selection < 0 || selection > List.size());

  List.erase(List.begin() + selection);
}
//-------------------------------------------------------------------------------Date
// Specificatino 6 - Current time added
string Date(){
  string mdy;

  time_t t = time(0);

  struct tm * now = localtime(&t);
  int month = now->tm_mon + 1;
  int day = now->tm_mday;
  int year = now->tm_year + 1900;

  mdy = to_string(month);
  mdy += "/";
  mdy += to_string(day);
  mdy += "/";
  mdy += to_string(year);

return mdy;
}