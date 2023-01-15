//GPA_Analyzer.cpp -- GPA Analyzer

//2/9/2018



//Your friend has asked you to help them with a project. He needs to calculate his grades,

//but is finding it difficult to operate a calculator(too hard).

//Create a program which will accept an unlimited number of scores

//and calculates the average score. You will also need to prompt for the total points possible.

//  • You must use object oriented programming.

//  • You cannot use the Standard Template Library (no vectors, etc, etc.).

//  • Follow the Style Guide(below).



//1.Use a dynamically allocated array to handle an unlimited number of test scores.

//2.Create a Grade class which holds the test score and the letter grade.

//3.Use an assert to protect the letter grade by not allowing negative scores.

//4.Create a simple menu: 1 - help, 2 - enter grade, 3 - quit. Use char user_menu;

//   for menu input. If incorrect value entered, display the value in the error message(ie, 4 is not a valid input).

//5.When quitting, display the average grade with appropriate headings.

//6.Log each individual grade to a .txt file. Make sure the total goes here when the program quite, too.



#include <iostream>

#include <stdlib.h>

#include <iomanip>

#include <string>

#include <fstream>

using namespace std;



// Specification 2 - Create a Grade class which holds the test score and the letter grade.

class Grade

{

  private:

		int score; // score

		int sMax; // total possible

		char letter; // letter grade

		double num; // 0.00 grade for averaging



  public:

		Grade() // constructor

		{

			score = 1;

			sMax = 1;

			letter = 'E';

			num = 0.00;

		}



		Grade(int arg1, int arg2, char arg3, float arg4)

		{

			score = arg1;

			sMax = arg2;

			letter = arg3;

			num = arg4;

		}



		~Grade() // deconstructor

		{}



// Specification 6 - Log each individual grade to a .txt file. Make sure the total goes here when the program quite, too.

		void Print(ofstream &Results) // prints out

		{

			cout << letter << ": [" << score << "/" << sMax << "] ";

			Results << letter << ": [" << score << "/" << sMax << "] " << endl; // prints to .txt file

		}



		void Average(Grade* arr, int size, ofstream &Results) // prints average grade

		{

			double fin;

			for(int i = 0; i < size; ++i)

  		{

				fin += arr[i].num;

  		}

			fin /= size;

			fin *= 100;

			cout << setprecision(2) << fixed << showpoint;

			cout << "\nAverage grade: " << fin << endl;

			Results << "\nAverage grade: " << fin << endl; // prints to .txt file

// Feature 3 - custom message based on grade

      if(num >= 90)     {cout << "Great Job!" << endl;}

      else if(num >= 80){cout << "Good Work!" << endl;}

      else if(num >= 70){cout << "Needs Work!" << endl;}

      else if(num >= 60){cout << "Try Again!" << endl;}

      else              {cout << "Need to Redo!" << endl;}

		}

}grade;

// Function Prototypes

void Body(ofstream &Results); //starts main functions

void Load(Grade*, int); // sets values as new values

char LetterCalc(double, double); // calcs letter assosiated with each grade, returns the letter

//****************************************************************************************Main

int main() {

  bool check = false;

  string choice;

  char exit;



  ofstream Results("Results.txt"); // creats and opens file



  cout << "\nWelcome to the GPA Analyzer" << endl;



// Feature 1 - Pretty User Interface

// Specification 4 - Create a simple menu: 1 - help, 2 - enter grade, 3 - quit. 

//                   Use char user_menu; for menu input. If incorrect value entered, 

//                   display the value in the error message(ie, 4 is not a valid input).

// Specification 5 - When quitting, display the average grade with appropriate headings.

// Feature 2 -     >>Made menu loop to add multiple sets of tests, all sets saved to file

  do{

    cout << "___________________________" << endl;

		Results << "___________________________" << endl << endl;

    cout << "\nWhat would you like to do?\n[1]:Explanation\n[2]:Start\n[3]:Exit\n>>ENTER:";

    getline(cin, choice);

    

    if(choice == "1")

    {

      cout << "\nYou will be prompted to enter the number of tests you are inputting." << endl;

      cout << "Then you will type in the score you got and how much it was out of." << endl;

      cout << "Scores will then be averaged and graded," << endl;

      cout << "a copy of each set of tests will be saved in a Results.txt file\ncreated on your desktop." << endl;

    }

    else if(choice == "2")

    {

      Body(Results);

    }

    else if(choice == "3")

    {

      cout << "\nWhould you like to exit?\n>>ENTER Y/N:";

      cin >> exit;

      cin.ignore();

      

      if(exit == 'Y' || exit == 'y')

      {

        check = true;

      }

    }

    else 

    {

      cout << "\n" << choice << " is not a valid option" << endl;

			cin.clear();

    }

  }while(check == false);

// Feature 4 - Out message

  cout << "\n\nThank you, Goodbye" << endl << endl;

	Results.close();

  

  return 0;

}

//------------------------------------------------------------------------------------------Functions

//------------------------------------------------------------------------------------------Body

void Body(ofstream &Results)

{

  int size;



	do{

		cout << "\nHow many grades are you inputting?\n>>ENTER:";

		cin >> size;



		if(size <= 0)

		{

			cout << size << " is not a valid input" << endl;

			cin.clear();

		}

	}while(size <= 0);



// Specification 1 - Use a dynamically allocated array to handle an unlimited number of test scores.

	Grade* grades = new Grade[size];



	Load(grades, size);

	

	cout << endl;

  for(int i = 0; i < size; ++i)

  {

    grades[i].Print(Results);

    cout << endl;

  }



	grade.Average(grades, size, Results);



	delete[] grades;

//  grades = nullptr;

}

//------------------------------------------------------------------------------------------Loader

void Load(Grade* arr, int size)

{

	double inscore;

	double insMax;

	char inlett;

	double innum;



	for(int i = 0; i < size; ++i)

	{

		cout << endl;

	do{

		cout << "Score: ";

		cin >> inscore;

// Specification 3 - Use an assert to protect the letter grade by not allowing negative scores.

		if(inscore <= 0)

		{

			cout << inscore << " is not a valid input" << endl;

			cin.clear();

		}

	}while(inscore <= 0);

	do{

		cout << "Out of:";

		cin >> insMax;



		if(insMax <= 0)

		{

			cout << insMax << " is not a valid input" << endl;

			cin.clear();

		}

	}while(insMax <= 0);



		inlett = LetterCalc(inscore, insMax);

		innum = (inscore / insMax);



		*(arr + i) = Grade(inscore, insMax, inlett, innum);

	}

	cin.clear();

  cin.ignore();

}

//------------------------------------------------------------------------------------------Letter Calc

char LetterCalc(double scr, double max)

{

	double num = (scr / max);



	if(num >= 0.90)     {return 'A';}

	else if(num >= 0.80){return 'B';}

	else if(num >= 0.70){return 'C';}

	else if(num >= 0.60){return 'D';}

	else                {return 'F';}

}

