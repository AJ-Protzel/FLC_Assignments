#include<iostream>
#include<string>
using namespace std;

const int SIZE = 20;

struct DataItem{   
  int data;      
  int key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* item;

int hashCode(int key){   
  return key % SIZE;
}

struct DataItem *search(int key){
  int hashIndex = hashCode(key);    

  while(hashArray[hashIndex] != NULL){      
    if(hashArray[hashIndex]->key == key)
      return hashArray[hashIndex];

    ++hashIndex;           
    hashIndex %= SIZE;   
  }           

  return NULL;        
}

void insert(int key,int data){   
  struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem)); 

  item->data = data;     
  item->key = key;   

  int hashIndex = hashCode(key);

  while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){      
    ++hashIndex;      
    hashIndex %= SIZE;   
  }

  hashArray[hashIndex] = item;
}

void remove(int key){
  int hashIndex = hashCode(key);

  while(hashArray[hashIndex] != NULL){      
    if(hashArray[hashIndex]->key == key)
      hashArray[hashIndex] = NULL;
    ++hashIndex;           
    hashIndex %= SIZE;   
  }    
}

void display(){     
  for(int i = 0; i<SIZE; i++){      
    if(hashArray[i] != NULL){       
      cout << i << ": " << hashArray[i]->key << ": " << hashArray[i]->data; 
      cout << endl;
    }   
  }   
  cout << endl;
}
//****************************************************************************************Main
int main(){

  insert(1, 20);   
  insert(2, 70);   
  insert(42, 80);   
  insert(4, 25);   
  insert(12, 44);
  insert(14, 32);   
  insert(17, 11);   
  insert(13, 78);   
  insert(37, 97);

  bool check = false;
  string choice;
  char exit;

  do{
    cout << "___________________________" << endl;
    cout << "\nWhat would you like to do?\n[1]:Display\n[2]:Add Item\n[3]:Delete Item\n[4]:Search Item\n[x]:Exit\n>>ENTER:";
    cin >> choice;
    cout << endl;

    if(choice == "1"){ // Display
      cout << endl;
      display();
      cout << endl;
    }
    else if(choice == "2"){ // Add
      int n,i;
      cout << "Enter key.\n>>ENTER:";
      cin >> n;
      cout << endl;
      cout << "Enter data.\n>>ENTER:";
      cin >> i;

      insert(n, i);
    }
    else if(choice == "3"){ // Delete
      int n;
      cout << "Enter key to delete.\n>>ENTER:";
      cin >> n;

      remove(n);
    }
    else if(choice == "4"){ // Search
      int n;
      cout << "Enter key to search.\n>>ENTER:";
      cin >> n;

      item = search(n);

      if(item != NULL){      
        //cout << endl << "Element found: \n", item->data;   
        cout << endl << "Element found: \n", item; 
      } 
      else{      
        cout << endl << "Element not found\n";   
      } 

      cout << endl;
    }
    else if(choice == "x" || choice == "X") // Exit
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
  cout << "\n\nGoodbye" << endl << endl;

  return 0;
}