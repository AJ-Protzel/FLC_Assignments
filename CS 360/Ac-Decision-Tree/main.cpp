//Ac Decision Tree.txt -- plane emerency ai
//A.Protzel, p360 
//10/4/2017 - 10/9/2017

//This program is menu driven. It presents four potential emergency
//situations: Communications Failure, Engine Failure, In-flight Icing, Quit.
//Communications Failure - This option only leads to 1 element, "Switch to Alternate Radio."
//Engine Failure - This activates the decision tree.
//In-Flight Icing - Prompt the pilot for the estimated amount of ice on the wings (0 mm to 10 mm). 
//  Aircraft will not fly with more than 10 mm of ice (and pilots will not be operating this system).
//  Range check this to make sure only 0 mm to 10 mm can be entered.
//  The amount of ice determines how much power to use to ener-gize the deicing boots on the wings.

//Less then 1mm, 5% power
//1 - 5 mm, 20% power
//5.1 - 9 mm, 65% power
//9.1 - 10 mm, 100% power

//Only ask questions relevant to the situation and previous answers.
//Do not ask for all the inputs at once (too stressful for the pilot!).
//  Allow only Y/N answers.
//  Reprompt if input is incorrect.
//  Loop the program until the user decides to quit.

#include <iostream>
using namespace std;

void CommunicationFailure();
void EngineFailure();
    bool EngAirborne();
    bool EngElectric();
    bool EngEngins();
    bool EngTemp();
    bool EngMountain();
    bool EngWater();
    bool EngNight();
    bool EngSight();
void FlightIcing();

bool Done();

int main()
{
  bool quit = false;
// Bonus 1 - Added greeting
  cout << "Hello pilot,\nI am your in flight emergency protocol decision system\nTo get started\n" << endl;
  
  do{
    int choiceNum;
  
// Bonus 2 - Added an All failure option 
// Bonus 3 - Added indents to responces for easier reading
    cout << "Please select the number of your problem:" << endl;
    cout << "[1]: Communication Failure\n" 
         << "[2]: Engine Failure\n"
         << "[3]: In-Flight Icing\n"
         
         << "[9]: All\n"
         << "[0]: Quit" << endl; 
    cout << ">> ENTER:";
    cin >> choiceNum;
    cout << endl;
  
    if(choiceNum == 1) //-------------------------------------------------1
    {
      CommunicationFailure();
       quit = Done();
    }
    else if(choiceNum == 2) //-------------------------------------------------2
    {
      EngineFailure();
       quit = Done();
    }
    else if(choiceNum == 3) //-------------------------------------------------3
    {
      FlightIcing();
       quit = Done();
    }
    
    else if(choiceNum == 9) //-------------------------------------------------9
    {
      cout << "  Commencing prayer to God\n" << endl;
      CommunicationFailure();
      EngineFailure();
      FlightIcing();
      
      quit = Done();
    }
    
    else if(choiceNum == 0) //-------------------------------------------------0
    {
      quit = true;
    }
  }while(quit == false);
  
  cout << "Have a pleasant flight!";
  
  return 0;
}
//===============================================================================================Functions
//---------------------------------------------------------------------------------Communication
void CommunicationFailure() 
{
  cout << "  Switching to alternate radio\n" << endl;
}
//---------------------------------------------------------------------------------Engine
void EngineFailure() 
{
  bool check = false;
  
  do{
    check = EngAirborne();
  }while(check == false);
  
}
//----------------------------------------------------------------------------------Ice
// Bonus 4 - Added responce if ice is above 10mm
void FlightIcing() 
{
  bool check = false;
  float mm;
  
  do{
    cout << ">> How many millimeters of ice are on the wings\n>> ENTER:";
    cin >> mm;
    cout << endl;
    
    if(mm > 10)
    {
      cout << "  Activating search and rescue beacon\n  Brace for impact\n" << endl;
      check = true;
    }
    else if(mm >= 9.1 && mm <= 10)
    {
      cout << "  Routing  100% power to deicing boots\n" << endl;
      check = true;
    }
    else if(mm >= 5.1 && mm <= 9)
    {
      cout << "  Routing  65% power to deicing boots\n" << endl;
      check = true;
    }
    else if(mm >= 1 && mm <= 5)
    {
      cout << "  Routing  20% power to deicing boots\n" << endl;
      check = true;
    }
    else if(mm >= 0.01 && mm < 1)
    {
      cout << "  Routing  5% power to deicing boots\n" << endl;
      check = true;
    }
    else
    {
      cout << "  That is not a valid amount of ice\n" << endl;
    }
  }while(check == false);
}
//-----------------------------------------------------------------------------------Done
bool Done()
{
  bool quit = false;
  char done;
  
  cout << "Was there something else you needed help with?\n>> ENTER Y/N:";
  cin >> done;
  cout << endl;
  
  if(done == 'N' || done == 'n')
      {
        return quit = true;
      }
  else 
  {
    return quit = false;
  }
}
//===============================================================================================Engine Continued
bool EngAirborne()//-------------------------------------------------------------EngAirborne()
{
  bool check = false;
  char ans;
  do{  
      cout << ">> Are you airborne?\n>> ENTER Y/N:";
      cin >> ans;
      cout << endl;
          if(ans == 'N' || ans == 'n')
          {
            cout << "  Relax and enjoy some time off\n" << endl;
            check = true;
          }
          else if(ans == 'Y' || ans == 'y')
          {
            check = EngElectric();
          }
          else 
          {
            cout << "  Enter a valid answer" << endl << endl;
          }
    }while(check == false);
    return check;
}

bool EngElectric()//-------------------------------------------------------------EngElectric()
{
  bool check = false;
  char ans;
  do{  
      cout << ">> Are electrical systems still on?\n>> ENTER Y/N:";
      cin >> ans;
      cout << endl;
          if(ans == 'N' || ans == 'n')
          {
            cout << "  Turn on master switch\n" << endl;
            check = true;
          }
          else if(ans == 'Y' || ans == 'y')
          {
            check = EngEngins();
          }
          else 
          {
            cout << "  Enter a valid answer" << endl << endl;
          }
    }while(check == false);
    return check;
}

bool EngEngins()//-------------------------------------------------------------EngEngins()
{
  bool check = false;
  char ans;
  do{  
      cout << ">> Have engins stopped working?\n>> ENTER Y/N:";
      cin >> ans;
      cout << endl;
          if(ans == 'N' || ans == 'n')
          {
            check = EngTemp();
          }
          else if(ans == 'Y' || ans == 'y')
          {
            check = EngMountain();
          }
          else 
          {
            cout << "  Enter a valid answer" << endl << endl;
          }
    }while(check == false);
    return check;
}

bool EngTemp()//-------------------------------------------------------------EngTemp()
{
  bool check = false;
  char ans;
  do{  
      cout << ">> Is the outside temperatur less than 32 degrees?\n>> ENTER Y/N:";
      cin >> ans;
      cout << endl;
          if(ans == 'N' || ans == 'n')
          {
            cout << "  Switch to other fuel tank\n" << endl;
            check = true;
          }
          else if(ans == 'Y' || ans == 'y')
          {
            cout << "  Turn on carburator heat\n" << endl;
            check = true;
          }
          else 
          {
            cout << "  Enter a valid answer" << endl << endl;
          }
    }while(check == false);
    return check;
}

bool EngMountain()//-------------------------------------------------------------EngMountain()
{
  bool check = false;
  char ans;
  do{  
      cout << ">> Are you over mountains?\n>> ENTER Y/N:";
      cin >> ans;
      cout << endl;
          if(ans == 'N' || ans == 'n')
          {
            check = EngWater();
          }
          else if(ans == 'Y' || ans == 'y')
          {
            check = EngNight();
          }
          else 
          {
            cout << "  Enter a valid answer" << endl << endl;
          }
    }while(check == false);
    return check;
}

bool EngWater()//-------------------------------------------------------------EngWater()
{
  bool check = false;
  char ans;
  do{  
      cout << ">> Are you over water?\n>> ENTER Y/N:";
      cin >> ans;
      cout << endl;
          if(ans == 'N' || ans == 'n')
          {
            cout << "  Make an emergency landing on a road\n" << endl;
            check = true;
          }
          else if(ans == 'Y' || ans == 'y')
          {
            cout << "  Inflate your life vest and make an emergency water landing\n" << endl;
            check = true;
          }
          else 
          {
            cout << "  Enter a valid answer" << endl << endl;
          }
    }while(check == false);
    return check;
}

bool EngNight()//-------------------------------------------------------------EngNight()
{
  bool check = false;
  char ans;
  do{  
      cout << ">> Are you flying at night?\n>> ENTER Y/N:";
      cin >> ans;
      cout << endl;
          if(ans == 'N' || ans == 'n')
          {
            cout << "  Make an emergency landing\n" << endl;
            check = true;
          }
          else if(ans == 'Y' || ans == 'y')
          {
            check = EngSight();
          }
          else 
          {
            cout << "  Enter a valid answer" << endl << endl;
          }
    }while(check == false);
    return check;
}

bool EngSight()//-------------------------------------------------------------EngSight()
{
  bool check = false;
  char ans;
  do{  
      cout << ">> Turn your light and look out window, do you like what you see?\n>> ENTER Y/N:";
      cin >> ans;
      cout << endl;
          if(ans == 'N' || ans == 'n')
          {
            cout << "  Turn off your light\n" << endl;
            check = true;
          }
          else if(ans == 'Y' || ans == 'y')
          {
            cout << "  Make an emergency landing\n" << endl;
            check = true;
          }
          else 
          {
            cout << "  Enter a valid answer" << endl << endl;
          }
    }while(check == false);
    return check;
}