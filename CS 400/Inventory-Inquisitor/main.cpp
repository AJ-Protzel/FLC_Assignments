// InventoryInquisitor.cpp

// 3/9/2018



#include <fstream>

#include <iomanip>

#include <iostream>

#include <stdlib.h>

#include <string>
#include <vector>

using namespace std;


class Item 

{

  private:

    int SIZE;

    int index;   // no. of item(x=>0)

    string name; // item name

    int date;    // (00000000) date added(figure out to take real world date)

    float wcost; // holesale cost(x>$5)

    float rcost; // retail cost(auto calc 100% markup)

    string desc; // item desc



  public:
    void indexDisplay()
{
   cout << index << "===" << name << endl;
}
//___________________________________________________________________________Constructor
    Item() // first main constructor
    {
      SIZE = 1;

	index = 0;           // no. of item(x=>0)

	name  = "Name";       // item name

	date  = 00000000; // (00000000) date added(figure out to

	wcost = 0.00;    // holesale cost(x>$5)

	rcost = 0.00;    // retail cost(auto calc 100% markup)

	desc  = "Description";// item desc
      

    }
//______________________________________________________________________File Constructor

    
//_______________________________________________________________________________Display
    void Display() // Displays all Items
    {
        cout << "[" << index << "] " << name << endl;
        cout << "Date Added" << date << endl;
        cout << "$" << wcost << "Wholesale Price" << endl;
        cout << "$" << rcost << "Retail Price" << endl;
        cout << "Description" << desc << endl << endl;
    }

//__________________________________________________________________________________Edit
    void Edit() // Edits an Item
    {
      int num;
      bool pass = false;

      cout << endl << endl << endl;

      cout << "[" << index << "] " << name << endl;
      cout << "Date Added" << date << endl;
      cout << "$" << wcost << "Wholesale Price" << endl;
      cout << "$" << rcost << "Retail Price" << endl;
      cout << "Description" << desc << endl << endl;

      cout << "Name: ";
        cin >> name;
      cout << "Whole:  $";
        cin >> wcost;
      cout << "Retail: $";
        cin >> rcost;
      cout << "Desc: ";
        cin >> desc;

      cout << endl << endl;

      cout << "[" << index << "] " << name << endl;
      cout << "Date Added" << date << endl;
      cout << "$" << wcost << "Wholesale Price" << endl;
      cout << "$" << rcost << "Retail Price" << endl;
      cout << "Description" << desc << endl << endl;
    }
//___________________________________________________________________________________Add
    void Add(int itemPosition) // Adds an Item
    {
	index = itemPosition++;
      cout << "Name: ";
        cin >> name;
      cout << "Whole:  $";
        cin >> wcost;
      cout << "Retail: $";
        cin >> rcost;
      cout << "Desc: ";
        cin >> desc;

      cout << endl << endl;

      cout << "[" << index << "] " << name << endl;
      cout << "Date Added" << date << endl;
      cout << "$" << wcost << "Wholesale Price" << endl;
      cout << "$" << rcost << "Retail Price" << endl;
      cout << "Description" << desc << endl << endl;

      ofstream textFile;
      textFile.open("data.csv", ios::app);
      textFile << index << "," << date << "," << name << "," << wcost << "," << rcost << "," << desc << endl;
      
    }


  ~Item(){}

};


vector<Item> items;


void CheckFile(fstream &file);
void Body();

//****************************************************************************************Main

int main() 

{
  Body();


  

  return 0;

}

//------------------------------------------------------------------------------------------Functions

//--------------------------------------------------------------------------------------CheckFile

void CheckFile(fstream &file)

{

  if(file.is_open() && file.good()) 

  {
    cout << "File opened" << endl;
    file.close();

  } 

  else 

  {
    file.close();
    cout << "File created" << endl;

  }

}

//--------------------------------------------------------------------------------------Body
void Body()
{


  fstream file("ItemRecords.txt", ios::in); // opens file IO

  CheckFile(file); // checks if readfile exists
  file.open("ItemRecords.txt", ios::out | ios::app | ios::trunc); // clears file and ready to write to

  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

  cout << ">--- Iten Inventory Manager ---<" << endl;

  bool check = false;
  string choice;
  char exit;

  do{
    cout << "___________________________" << endl;
    cout << "\nWhat would you like to do?\n[1]:Display Items\n[2]:Edit an Item\n[3]:Add Item\n[4]:Remove Item\n[5]:Exit\n>>ENTER:";

    cin >> choice;

    if(choice == "1") // display
    {
      ifstream myFile;
      myFile.open("data.csv");
      while(myFile.good())
      {

         string line;
         getline(myFile, line, ',');
         cout << "Index: " << line << endl;

         getline(myFile, line, ',');
         cout << "Date: " << line << endl;

         getline(myFile, line, ',');
         cout << "Name: " << line << endl;

         getline(myFile, line, ',');
         cout << "WCost: " << line << endl;

         getline(myFile, line, ',');
         cout << "RCost: " << line << endl;

         getline(myFile, line, ',');
         cout << "Desc: " << line << endl;

      }
      //Display();
      //for(int i = 0; i < items.size(); i++) {
      //   items.at(i).Display();
      //}
    }
    else if(choice == "2") // edit
    {
      //Edit();
    }
    else if(choice == "3") // Add
    {
      //Add();
      Item oneItem;
      oneItem.Add(items.size());
      items.push_back(oneItem);
    }
    else if(choice == "4") // Remove
    {
      //Remove();
      for(int i = 0; i < items.size(); i++) {
         items.at(i).indexDisplay();
      }
      cout << "Select index" << endl;
      int selection;
      cin >> selection;
      items.erase(items.begin() + selection);
    }
    else if(choice == "5") // Exit
    {
      cout << "\nWould you like to exit?\n>>ENTER Y/N:";
      cin >> exit;
      cin.ignore();
      
      if(exit == 'Y' || exit == 'y')
      {
        check = true;
      }
    }

    else // checks input
    {
      cout << "\n" << choice << " is not a valid option" << endl;
      cin.clear();
    }
  }while(check == false);
  cout << "\n\nThank you, Goodbye" << endl << endl;
  file.close();
}