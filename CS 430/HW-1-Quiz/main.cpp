// Quiz.cpp + Questions.txt
// Adrien Protzel 
// 9/9/2018

// You are going to write a program for Computer test which willread 10 multiple choice questions from a file,
// order them randomly and provide the test to the user.
// when user done the program must give the user his final score.

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;

struct Task
{
  string question;
  string answers;
  string answer;
};

Task makeTask(string q, string aa, string a)
{
  Task newTask = {q, aa, a};
  return newTask;
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++End of Class
vector<Task> Questions;

bool CheckFile(ifstream &file);
void LoadVector(ifstream &file);
void Randomize();
void Body();
//****************************************************************************************Main
int main ()
{
  srand (time(NULL));
//Existing file checker
  ifstream file;
  file.open("Questions.txt", ios::app);
  bool check = CheckFile(file);
  file.close();

  if (check == true)
    Body();

  return 0;
}
//-----------------------------------------------------------------------------------Functions
//-------------------------------------------------------------------------------CheckFile
bool CheckFile(ifstream &file){
  file.seekg(0, ios::end);
  int length = file.tellg();

  file.seekg(0, ios::beg);

  if(length == 0)
  {
    cout << endl;
    cout << "Quiz not found" << endl << endl;
    return false;
  }

  else
  {
    cout << "Quiz found." << endl;
    LoadVector(file);
    return true;
  }
}
//-------------------------------------------------------------------------------LoadVector
void LoadVector(ifstream &file){
  cout << "Loading questions." << endl;

  string str;
  string anss;
  string ans;

  while(!file.eof())
  {
    getline(file, str);
    getline(file, anss);
    getline(file, ans);

    Questions.push_back(makeTask(str, anss, ans));
  }
  cout << "Questions loaded." << endl;
  Randomize();
}
//-------------------------------------------------------------------------------Randomize
void Randomize(){
  cout << "Randomizing questions." << endl;

  random_shuffle(Questions.begin(), Questions.end());

  cout << "Questions randomized." << endl;
}
//-------------------------------------------------------------------------------Body
void Body()
{
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

  string ans;
  vector<string> Answers;

  cout << ">------------------Pop Quiz-----------------<" << endl;

  for(int i = 0; i < Questions.size(); ++i)
  {
    cout << "         >-----------------------<" << endl;
    cout << "[" << i+1 << "] " << Questions[i].question << endl << endl;
    cout << "    " << Questions[i].answers << endl << endl;
    cout << ">>ENTER:";
    getline(cin, ans);
    transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
    Answers.push_back(ans);
  }

  int score = 0;

  for(int i = 0; i < Questions.size(); ++i)
  {
    if(Answers[i] == Questions[i].answer)
    {
      score++;
    }
  }

  cout << endl << endl << "[You scored " << score << "/10]" << endl;
}