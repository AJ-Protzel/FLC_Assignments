//Credit Card Payoff.txt -- Calculate how long it will take to payoff a credit card.
//A.Protzel, p360 
//9/16/2017 - 9/20/2017

//Prompt for the current credit card balance, the Annual Percentage Rate (APR), and the amount of money you can pay monthly. 
//Return the number of months to pay off the card with these parameters. 

//n=-log(1-(Ai/P))/log(1+i)
//n = Number of Months to payoff credit card
//A = Amount on credit card
//i = Monthly Rate (APR / 12)
//P = Monthly Payment Amount

#include <iostream>
#include <cmath>
using namespace std;
  
  const int MONTHS_IN_YEAR = 12, 
            MONTH_ROUNDED_UP = 1;
            
int main()
{
  string first = "";
  string last = "";
  
  float Balance;
  float APR;
  float apr;
  float Paym;
  int month;
  
  //Bonus-- added name and greeting
  cout << "Hello I can tell you how many months it will take for you to pay off your credit card with your current APR. To get started,\n\n";
  cout << "Please enter your first and then last name\n";
  cin >> first >> last;
  cout << "Hello " << first << " " << last << ",\n";
  
  cout << "Please enter your cards current balance\n";
  cin >> Balance;
  
  cout << "Now please enter your APR\n";
  cin >> APR;
  
  cout << "Enter how much you can pay per month\n";
  cin >> Paym;
  
  apr = (APR / 100) / MONTHS_IN_YEAR;
  
  //Bonus-- Added checker to see is pay amount is enough to cover the apr, both here and for table
  if ((Balance * apr / MONTHS_IN_YEAR) < Paym)
  {
    cout << "With your current balance of ($" << Balance << ").\n"
         << "and an APR of (" << APR << "%).\n\n"
         << "($" << Paym << ") Is not enough to pay off the APR, below are other pay per month options at your same APR.\n\n";
  }
  
  else
  {
    month = (-log10(1 - (Balance * (apr)) / Paym) / log10(1 + (apr)));

    cout << "With your current balance of ($" << Balance << ").\n"
         << "and an APR of (" << APR << "%).\n\n"
         << "It will take you (" << month + MONTH_ROUNDED_UP << ") months to pay off your card, below are other pay per month options at your same APR.\n\n";
  }
  //Bonus-- Added other pay calculations
  int fifty_month          = (-log10(1 - (Balance * (apr)) / 50) / log10(1 + (apr)));
  int seventyfive_month    = (-log10(1 - (Balance * (apr)) / 75) / log10(1 + (apr)));
  int onehundred_month     = (-log10(1 - (Balance * (apr)) / 100) / log10(1 + (apr)));
  int onetwentyfive_month  = (-log10(1 - (Balance * (apr)) / 125) / log10(1 + (apr)));
  int onefifty_month       = (-log10(1 - (Balance * (apr)) / 150) / log10(1 + (apr)));
  int oneseventyfive_month = (-log10(1 - (Balance * (apr)) / 175) / log10(1 + (apr)));
  int twohundred_month     = (-log10(1 - (Balance * (apr)) / 200) / log10(1 + (apr)));
  int twotwentyfive_month  = (-log10(1 - (Balance * (apr)) / 225) / log10(1 + (apr)));
  int twofifty_month       = (-log10(1 - (Balance * (apr)) / 250) / log10(1 + (apr)));
  int twoseventyfive_month = (-log10(1 - (Balance * (apr)) / 275) / log10(1 + (apr)));
  int threehundred_month   = (-log10(1 - (Balance * (apr)) / 300) / log10(1 + (apr)));
  
  //Bonus-- Added table 
  cout << " Pay  | Months\n"
       << " -------------\n";
       
  cout << " $50  | ";
         if ((Balance * apr / MONTHS_IN_YEAR) < fifty_month)
         {
           cout << fifty_month + MONTH_ROUNDED_UP << "\n";
         }
          else cout << "Not Enough\n";
       
  cout << " $75  | ";
         if ((Balance * apr / MONTHS_IN_YEAR) < seventyfive_month)
         {
           cout << seventyfive_month + MONTH_ROUNDED_UP << "\n";
         }
          else cout << "Not Enough\n";
        
  cout << " $100 | ";
         if ((Balance * apr / MONTHS_IN_YEAR) < onehundred_month)
         {
           cout << onehundred_month + MONTH_ROUNDED_UP << "\n";
         }
          else cout << "Not Enough\n";
        
  cout << " $125 | ";
         if ((Balance * apr / MONTHS_IN_YEAR) < onetwentyfive_month)
         {
           cout << onetwentyfive_month + MONTH_ROUNDED_UP << "\n";
         }
          else cout << "Not Enough\n";
        
  cout << " $150 | ";
         if ((Balance * apr / MONTHS_IN_YEAR) < onefifty_month)
         {
           cout << onefifty_month  + MONTH_ROUNDED_UP << "\n";
         }
          else cout << "Not Enough\n";
        
  cout << " $175 | ";
         if ((Balance * apr / MONTHS_IN_YEAR) < oneseventyfive_month)
         {
           cout << oneseventyfive_month + MONTH_ROUNDED_UP << "\n";
         }
         else cout << "Not Enough\n";
        
  cout << " $200 | ";
         if ((Balance * apr / MONTHS_IN_YEAR) < twohundred_month)
         {
           cout << twohundred_month + MONTH_ROUNDED_UP << "\n";
         }
          else cout << "Not Enough\n";
        
  cout << " $225 | ";
         if ((Balance * apr / MONTHS_IN_YEAR) < twotwentyfive_month)
         {
           cout << twotwentyfive_month + MONTH_ROUNDED_UP << "\n";
         }
          else cout << "Not Enough\n";
        
  cout << " $250 | ";
         if ((Balance * apr / MONTHS_IN_YEAR) < twofifty_month)
         {
           cout << twofifty_month + MONTH_ROUNDED_UP << "\n";
         }
          else cout << "Not Enough\n";
        
  cout << " $275 | ";
         if ((Balance * apr / MONTHS_IN_YEAR) < twoseventyfive_month)
         {
           cout << twoseventyfive_month + MONTH_ROUNDED_UP << "\n";
         }
          else cout << "Not Enough\n";
        
        
  cout << " $300 | ";
         if ((Balance * apr / MONTHS_IN_YEAR) < threehundred_month)
         {
           cout << threehundred_month + MONTH_ROUNDED_UP << "\n";
         }
          else cout << "Not Enough\n";
  
  return 0;
}