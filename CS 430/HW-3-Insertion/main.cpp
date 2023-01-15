#include <iostream>
using namespace std;

struct node{
  int data;
  node *next;
}; // node 

class linked_list{
  public:
    node *head,*tail;
    linked_list(){
      head = NULL;
      tail = NULL;
    }
//-------------------------------------------------------------------------------linked_list Functions
//_______________________________________________________________Add
    void add_node(int n){
      node *tmp = new node;
      tmp->data = n;
      tmp->next = NULL;

      if(head == NULL){
        head = tmp;
        tail = tmp;
      }
      else{
        tail->next = tmp;
        tail = tail->next;
      }
      cout<<tmp->data<<endl;
    }
//_______________________________________________________________Delete
    void delete_node(int n){
      node *current = head;
      while(current != NULL){
        if(current->data == n)
        { 
          break; 
        }
        else {
          cout << "Value " << current->data << " does not match " << n << ".\n";
          current = current->next; 
        }
      } 
      if(current == NULL){ 
        cout << "Can't remove value: no match found.\n"; 
      }
      else
      {
        cout << "Deleting: " << current->data << "\n";
        delete current;
        current = current->next; 
      }
    } 
//_______________________________________________________________Insert
    void insert_node(int n, int i){
        node *tmp = new node;
        tmp->data = i;
        tmp->next = NULL;

        node *current = head;

        while(current != NULL){
          if(current->data == n){
            tmp->next = current->next;
            current->next = tmp;
            break;
          }
          else
          current = current->next; 
        }
    }
//_______________________________________________________________Print
    void print_list(){
      node *current = head;
      while(current != NULL)
      {
        cout<<endl<<current->data;
        current = current->next; 
      }
      cout<<endl;  
    }
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++End of Class
//****************************************************************************************Main
int main(){
  linked_list a;

  for(int i = 0; i < 10; ++i){
    a.add_node(i);
  }

  bool check = false;
  string choice;
  char exit;

  do{
    cout << "___________________________" << endl;
    cout << "\nWhat would you like to do?\n[1]:Display Items\n[2]:Add Item\n[3]:Delete Item\n[x]:Exit\n>>ENTER:";
    cin >> choice;
    cout << endl;

    if(choice == "1"){ // Display
      cout << endl;
      a.print_list();
      cout << endl;
    }
    else if(choice == "2"){ // Add
      int n,i;
      cout << "Enter what possition you would like to add to.\n>>ENTER:";
      cin >> n;

      cout << endl;

      cout << "Enter what data you want in it.\n>>ENTER:";
      cin >> i;

      a.insert_node(n,i);
    }
    else if(choice == "3"){ // Delete
      int n;
      cout << "Enter what possition you would like to add to.\n>>ENTER:";
      cin >> n;

      a.delete_node(n);
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