#include<iostream>
using namespace std; 

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++End of Class
void HeapSort();
  void heapify(int arr[], int n, int i);
  void heapSort(int arr[], int n);

void InsertSort();
  void insertionSort(int arr[], int n);

void ShellSort();
  int shellSort(int arr[], int n);

void printArray(int arr[], int n);
//****************************************************************************************Main
int main(){srand(time(NULL));

  cout << endl << "Unsorted:\n6 15 70 13 88 7 2 11 24 35" << endl << endl;

  cout << "Heap Sort:" << endl;
  HeapSort();

  cout << endl << endl;

  cout << "Insertion Sort:" << endl;
  InsertSort();

  cout << endl << endl;

  cout << "Shell Sort:" << endl;
  ShellSort();

  return 0; 
} 
//-----------------------------------------------------------------------------------Functions
//-------------------------------------------------------------------------------Heap Sort
void HeapSort(){
  int arr[] = {6, 15, 70, 13, 88, 7, 2, 11, 24, 35};
  int n = sizeof(arr)/sizeof(arr[0]);

  heapSort(arr, n);
  printArray(arr, n);
}
//______________________________________________heapSort
void heapSort(int arr[], int n){
  // Build max heap
  printArray(arr, n);

  for (int i = n / 2 - 1; i >= 0; i--){
    heapify(arr, n, i);
  }

  // Heap sort
  for (int i=n-1; i>=0; i--){
    swap(arr[0], arr[i]);
    printArray(arr, n);
     
    // Heapify root element to get highest element at root again
    heapify(arr, i, 0);
    printArray(arr, n);
  }
}
//______________________________________________heapify
void heapify(int arr[], int n, int i){
   // Find largest among root, left child and right child
   int largest = i;
   int l = 2*i + 1;
   int r = 2*i + 2;

   if (l < n && arr[l] > arr[largest])
     largest = l;

   if ((r < n) && (arr[r] > arr[largest]))
     largest = r;

   // Swap and continue heapifying if root is not largest
   if (largest != i)
   {
     swap(arr[i], arr[largest]);
     heapify(arr, n, largest);
     printArray(arr, n);
   }
}

//-------------------------------------------------------------------------------Insertion Sort
void InsertSort(){
  int arr[] = {6, 15, 70, 13, 88, 7, 2, 11, 24, 35};
  int n = sizeof(arr)/sizeof(arr[0]); 
  
  insertionSort(arr, n); 
  printArray(arr, n);
}
//______________________________________________insertionSort
void insertionSort(int arr[], int n){ 
  printArray(arr, n);
  int i, key, j;

  for (i = 1; i < n; i++){ 
    key = arr[i]; 
    j = i-1; 
    
    while (j >= 0 && arr[j] > key){ 
      arr[j+1] = arr[j]; 
      j = j-1;
    } 
    
    arr[j+1] = key; 
    printArray(arr, n);
  } 
} 
//-------------------------------------------------------------------------------Shell Sort
void ShellSort(){
  int arr[] = {6, 15, 70, 13, 88, 7, 2, 11, 24, 35};
  int n = sizeof(arr)/sizeof(arr[0]); 
  
  shellSort(arr, n); 
  printArray(arr, n);
}
//______________________________________________shellSort
int shellSort(int arr[], int n){
  cout << "0_1__2__3__4__5__6__7__8__9__10" << endl;
  printArray(arr, n);
  

  for (int gap = n/2; gap > 0; gap /= 2){ 
    for (int i = gap; i < n; i += 1){ 
      int temp = arr[i]; 

      int j = i;
      cout << j-gap << "[" << arr[j-gap] << "] > " << i << "[" << temp << "]:" << endl;      
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
        arr[j] = arr[j - gap];
        cout << "-> " << arr[j] << endl;
        //cout << j-gap << "[" << arr[j-gap] << "] > " << i << "[" << temp << "]: -> " << arr[j] << endl << endl;
        printArray(arr, n);
      }

      arr[j] = temp; 
    } 
  } 
  return 0;
} 
//-------------------------------------------------------------------------------printArray
void printArray(int arr[], int n){
  for (int i=0; i < n; ++i){
    cout << arr[i] << " ";
  }
  cout << endl;
}