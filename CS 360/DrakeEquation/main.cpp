//drake.txt -- calculate the probability of life
//A.Protzel, p360 
//9/1/2017 - 9/9/1027

//This program should calculate the possible worlds with 
//intelligent life willing to communicate with us
//using the drake equation, 

//N = R *p * n * f * i * c * L 
//R, the average rate of star formations, in our galaxy.
//f, the fraction of formed stars that have planets.
//n, stars that have habitable planets.
//l, planets that develop life.
//i, fraction of planets with life intelligent.
//c, fraction planets with communications.
//L, length of time the planet sends signals.

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
  float N,R,f,n,l,i,c,L;
  
  srand (time(NULL)); //seed generator
  
  R = rand()% 20 + 1; //(given = 7) (low = 7.7) (high = 500) (ave = 253.85) (caveat now = 5-20)
  R = R + 5;
  
  f = rand()% 90 + 1; //(given = 40%) (low = 5%) (high = 90%) (ave = 47.5%)
  f = (f + 5) / 100;
  
  n = rand()% 50 + 1; //(low = 50%) (high = 80%)
  n = (n + 50) / 100;
  
  l = rand()% 80 + 1; //(given = 13%) (low = 1%) (high = 90%)
  l = l / 100;
  
  i = rand()% 80 + 1; //(low = 1%) (high = 80%)
  i = i / 100;
  
  c = rand()% 80 + 1; //(low = 1%) (high = 80%)
  c = c / 100;
  
  L = rand()%10000 + 1; //(low = 50) (high = 10000)
  L = L + 50;
  
  N = R *f * n * l * i * c * L;
  int NN = N * 100;
  
  cout << "*Number are chosen at random*\n\n"
       << R << " - " << "New stars per year\n"
       << f * 100 << "% - " << "Stars with plantes\n" 
       << n * 100 << "% - " << "Habitability of those planets\n"
       << l * 100 << "% - " << "Life on those planets\n"
       << i * 100 << "% - " << "Life that is intelligent\n" 
       << c * 100 << "% - " << "Life with communication\n" 
       << L << " - " << "Number of years they send signals\n\n"
       << NN << " Possible intelligent civilizations that may contact us";
  
  return 0;
}