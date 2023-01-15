#include<iostream>
//#include <queue>
using namespace std;

struct queue{
  int item;
  int priority;
};

const int Max=5;
queue queue[Max];
int front=0,rear=0;
int menu();

void enqueue();
void dequeue();
void display();

int main(){
  int ch;
  do{    
    ch=menu();    
    switch(ch){    
      case 1: enqueue(); break;
      case 2: dequeue(); break;    
      case 3: display(); break;    
      case 4: cout<<"\n Exit Queue Program!"; break;    
      default:cout<<"\n Please enter a valid choice!!";    
    }
  }while (ch!=4);
  return 0;
}

int menu(){    
  int ch;
    cout<<"\n\n\n1.ENQUEUE \n2.DEQUEUE \n3.DISPLAY \n4.EXIT";
    cout<<"\nEnter your Choice:";    
    cin>>ch;    
    return ch;    
}

void enqueue(){    
  int element;    
  if(rear==Max){        
    cout<<"\nOverflow!!";    
  }
  
  else{        
    cout<<"\nEnter Element:";        
    cin>>element;        
    queue[rear++] = element;        
    cout<<"\nEnqueued at "<<element<<" at "<<rear;    
  }
}

void dequeue(){    
  if(rear==front){        
    cout<<"\nUnderflow!!";    
  }    
  
  else{      
    for(int i=front;i<=rear;i++){            
      queue[i]=queue[i+1];
    }        
    rear--;
  }
}

void display(){    
  int i;
  if(front==rear){        
    cout<<"\nQueue is Empty!!!";    
  }    
  else{        
    cout<<" \n";        
    for(i=0;i<Max;i++){            
      cout<<" |  "<<queue[i];        
    }            
    cout<<"|";    
  }
}