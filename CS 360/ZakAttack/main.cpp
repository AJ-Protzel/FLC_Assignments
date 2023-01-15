//ZakAttack.txt -- Quiz scores
//A.Protzel, p360 
//10/30/2017 - 11/13/2017

//Professor Zak allows students to drop the lowest scores on the 100-point quizzes she gives during the semester. Unfortunately, the number of
//quizzes varies from semester to semester (sometimes significantly). However, she always drops the lowest 30% of the quizzes.

//Design and code an application that accepts a student name and the
//quiz scores. Output the student’s name, all test scores (and letter
//grades) and the GPA for the upper 70% of the quizzes. Then output
//the corresponding letter grade and words of advice. Constraints.

//• Use a fixed size array of 50 elements. However, only display the data entered, not the entire array.
//• Use pointer notation to access the arrays, not array notation.
//• Allow name to accept first plus last name (ie 2 words).
//• Range test the input data for the grades.
//• Create a simple menu to 1 add grade, 2 - Produce output, 3 quit. Only allow this input.

// Bonus 1 - line 54: Added comfortable user experience 
// Bonus 2 - line 107: added check to make sure its right name
// Bonus 3 - line 306: Added break after top 70% of tests are shown  

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

void NewStudent(string*, double*); // input new student name and score
void Sorter(double*, double*);
void Display(string*, double*, double*); // Displays

const int SIZE = 50;
int length = 0;

int main()
{
  string Name = "BLOBBERT";
  double Scores[SIZE];
  double Grade;
  
  for(int i = 0; i < SIZE; ++i)
  {
    *(Scores + i) = 0.00;
  }
  
  string* PtrName = &Name;
  double* GPA = &Grade;
  
  bool check = false;
  int choice;
  char quite;

  cout << "Welcome";
// Bonus 1 - Comfy for user 
  do{
    cout << "\n-----------------------------------------";
    cout << "\nWhat would you like to do?\n[1]:Explanation\n[2]:Start\n[3]:Quite\n>>ENTER:";
    cin >> choice;
    
    if(choice == 1)
    {
      cout << "\nYou will be prompted to enter the students first and last name together as well as their grade."
           << "\nWhen you are done inputting the scores will be calculate and displayed." << endl;
    }
    else if(choice == 2)
    {
      NewStudent(PtrName, Scores);
      Sorter(Scores, GPA);
      Display(PtrName, Scores, GPA);
    }
    else if(choice == 3)
    {
      cout << "\nWhould you like to quite?\n>>ENTER Y/N:";
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
  
  cout << "\n\nThanks you";
  
  return 0;
}
//=================================================================================================================Functions
//-----------------------------------------------------------------------------------------------------------------NewStudents
void NewStudent(string* Name, double* Score)
{
  cout << endl;
  cin.clear();
  cin.ignore();
  
  bool check = false;
  char Answer;
  bool checka = false;
  
  do{
    cout << "Enter the students first and last name.\n>>ENTER:";
    getline(cin, *Name);
// Bonus 2 - added check to make sure its right name
    cout << "\nIs [" << *Name << "] Correct? Y/N\n>>ENTER:";
    cin >> Answer;
    
    if(Answer == 'Y' || Answer == 'y')
    {
      check = true;
    }
  }while(check == false);
  
  cin.clear();
  cin.ignore();
  
  do{
    cout << "\nType the number of tests you will be entering, limit 50.\n>>ENTER:";
    cin >> length;
  
    if(length > 0 && length <= 50)
    {
      checka = true;
    }
    else
    {
      cout << "\nSorry the number of tests you enterd is either too much or too little, please try again" << endl;
    }
  }while(checka == false);
  
  cout << "\nEnter the test scores when prompted, if a score is 0 or less, enter 0.01" << endl;
  cout << "========================================" << endl;
  
  for(int i = 0; i < length; ++i)
  {
    cout << "Test [" << (i + 1) << "] :";
    cin >> *(Score + i);
  }
}

//-----------------------------------------------------------------------------------------------------------------Sorter
void Sorter(double* Score, double* GPA)
{
  double temp;
  bool madeSwap;
  int num;
  
  do{
    madeSwap = false;
    for(int count = 0; count < (SIZE - 1); ++count)
    {
      if(*(Score + count) < *(Score + count + 1))
      {
        temp = *(Score + count);
        *(Score + count) = *(Score + count + 1);
        *(Score + count + 1) = temp;
        madeSwap = true;
      }
    }
  }while(madeSwap);
  
  num = ((length * 70) / 100);
  
  for(int i = 0; i < num; ++i)
  {
    if(*(Score + i) >= 94)
    {
      *GPA += 4.00;
    }
    else if(*(Score + i) >= 90 && *(Score + i) < 94)
    {
      *GPA += 3.70;
    }
    else if(*(Score + i) >= 87 && *(Score + i) < 90)
    {
      *GPA += 3.33;
    }
    else if(*(Score + i) >= 84 && *(Score + i) < 87)
    {
      *GPA += 3.00;
    }
    else if(*(Score + i) >= 80 && *(Score + i) < 84)
    {
      *GPA += 2.70;
    }
    else if(*(Score + i) >= 77 && *(Score + i) < 80)
    {
      *GPA += 2.30;
    }
    else if(*(Score + i) >= 74 && *(Score + i) < 77)
    {
      *GPA += 2.00;
    }
    else if(*(Score + i) >= 70 && *(Score + i) < 74)
    {
      *GPA += 1.70;
    }
    else if(*(Score + i) >= 67 && *(Score + i) < 70)
    {
      *GPA += 1.30;
    }
    else if(*(Score + i) >= 64 && *(Score + i) < 67)
    {
      *GPA += 1.00;
    }
    else if(*(Score + i) >= 60 && *(Score + i) < 64)
    {
      *GPA += 0.70;
    }
    else
    {
      *GPA += 0.00;
    }
  }
  
  *GPA /= num;
}

//-----------------------------------------------------------------------------------------------------------------Display
void Display(string* Name, double* Score, double* GPA)
{
  cout << endl;
  cout << "****************************************" << endl;
  cout << *Name << endl;
  cout << setprecision(2) << fixed << showpoint;
  cout << "GPA:" << *GPA << endl;
  
  if(*GPA >= 3.67)
  {
    cout << "Great Work!!" << endl;
  }
  else if(*GPA >= 2.67 && *GPA < 3.67)
  {
    cout << "Good Work!" << endl;
  }
  else if(*GPA >= 1.67 && *GPA < 2.67)
  {
    cout << "Keep trying" << endl;
  }
  else if(*GPA >= 0.67 && *GPA < 1.67)
  {
    cout << "Need to try again" << endl;
  }
  else
  {
    cout << "See me after class" << endl;
  }
  
  cout << endl;
  
  for(int i = 0; i < length; ++i)
  {
    if(*(Score + i) >= 94)
    {
      cout << "Test[" << i + 1 << "]:" << *(Score + i) << " A" << endl;
    }
    else if(*(Score + i) >= 90 && *(Score + i) < 94)
    {
      cout << "Test[" << i + 1 << "]:" << *(Score + i) << " A-" << endl;
    }
    else if(*(Score + i) >= 87 && *(Score + i) < 90)
    {
      cout << "Test[" << i + 1 << "]:" << *(Score + i) << " B+" << endl;
    }
    else if(*(Score + i) >= 84 && *(Score + i) < 87)
    {
      cout << "Test[" << i + 1 << "]:" << *(Score + i) << " B" << endl;
    }
    else if(*(Score + i) >= 80 && *(Score + i) < 84)
    {
      cout << "Test[" << i + 1 << "]:" << *(Score + i) << " B-" << endl;
    }
    else if(*(Score + i) >= 77 && *(Score + i) < 80)
    {
      cout << "Test[" << i + 1 << "]:" << *(Score + i) << " C+" << endl;
    }
    else if(*(Score + i) >= 74 && *(Score + i) < 77)
    {
      cout << "Test[" << i + 1 << "]:" << *(Score + i) << " C" << endl;
    }
    else if(*(Score + i) >= 70 && *(Score + i) < 74)
    {
      cout << "Test[" << i + 1 << "]:" << *(Score + i) << " C-" << endl;
    }
    else if(*(Score + i) >= 67 && *(Score + i) < 70)
    {
      cout << "Test[" << i + 1 << "]:" << *(Score + i) << " D+" << endl;
    }
    else if(*(Score + i) >= 64 && *(Score + i) < 67)
    {
      cout << "Test[" << i + 1 << "]:" << *(Score + i) << " D" << endl;
    }
    else if(*(Score + i) >= 60 && *(Score + i) < 64)
    {
      cout << "Test[" << i + 1 << "]:" << *(Score + i) << " D-" << endl;
    }
    else
    {
      cout << "Test[" << i + 1 << "]:" << *(Score + i) << " F" << endl;
    }
// Bonus 3 - Added break after top 70% of tests are shown    
    if(i == ((length * 70) / 100) - 1)
    {
      cout << "----" << endl;
    }
  }
}