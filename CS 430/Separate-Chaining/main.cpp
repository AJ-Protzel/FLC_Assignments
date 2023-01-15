#include<iostream>
using namespace std;

class HashedObj{
  private:
    int key;
    int value;
    HashedObj *next;
  public:
    HashedObj(int key, int value){
      this->key = key;
      this->value = value;
      this->next = nullptr;
    }

    int getKey(){
      return key;
    }

    int getValue(){
      return value;
    }
    
    void setValue(int value){
      this->value = value;
    }
    
    HashedObj *getNext(){
      return next;
    }

    void setNext(HashedObj *next){
      this->next = next;
    }
};

const int TABLE_SIZE = 100;

class HashTable{
  private:
    HashedObj **table;
  public:
    HashTable(){
      table = new HashedObj *[TABLE_SIZE];
      for(int i = 0; i < TABLE_SIZE; i++)
        table[i] = nullptr;
    }

    int get(int key){
      int hash = (key% TABLE_SIZE);
      if(table[hash] == nullptr)
        return-1;
      else{
        HashedObj *entry = table[hash];
        while(entry != nullptr && entry->getKey() != key)
          entry = entry->getNext();
          if(entry == nullptr)
            return-1;
          else return entry->getValue();
      }
    }
    
    void put(int key, int value) {
      int hash = (key % TABLE_SIZE);
      if(table[hash] == nullptr)
        table[hash] = new HashedObj(key, value);
      else{
        HashedObj *entry = table[hash];
        while(entry->getNext() != nullptr)
          entry = entry->getNext();
          if(entry->getKey() == key)
            entry->setValue(value);
          else 
            entry->setNext(new HashedObj(key, value));
      }
    }
    
    void remove(int key){
      int hash = (key% TABLE_SIZE);
      if(table[hash] != nullptr){
        HashedObj *prevEntry = nullptr;
        HashedObj *entry = table[hash];
        while(entry->getNext() != nullptr && entry->getKey() != key){
          prevEntry = entry;
          entry = entry->getNext();
        }
        if(entry->getKey() == key){
          if(prevEntry == nullptr){
            HashedObj*nextEntry = entry->getNext();
            delete entry;
            table[hash] = nextEntry;
          }
          else{
            HashedObj *next = entry->getNext();
            delete entry;
            prevEntry->setNext(next);
          }
        }
      }
    }
};

int main(){
  HashTable table;
  int found;

  table.put(1, 10);
  table.put(2, 30);
  table.put(101, 50);
  table.put(3, 12);
  table.put(4, 60);
  table.put(201, 35);

  cout << "Key, Value" << endl;
  for(int i = 0; i < 500; ++i){
    found = table.get(i);
    if(found != -1)
      cout << i << ", " << found << endl;
  }

  table.remove(101);
  cout << endl << "removed 101" << endl << endl;

  for(int i = 0; i < 500; ++i){
    found = table.get(i);
    if(found != -1)
      cout << i << ", " << found << endl;
  }
}