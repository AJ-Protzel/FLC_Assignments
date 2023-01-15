#include<iostream>
#include <stdlib.h> 
using namespace std;

struct Node{ 
  int data; 
   Node *left, *right; 
}; 

Node* newNode(int data){
  Node* node = (Node*)malloc(sizeof(Node)); 
  node->data = data; 
  node->left = node->right = NULL;

  return(node); 
} 
  
Node* insertLevelOrder(int arr[], Node* root, int i, int n){
  if (i < n){ 
    Node* temp = newNode(arr[i]); 
    root = temp; 
    root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n); 
    root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n); 
  } 
  
  return root; 
}
  
void inOrder(Node* root){ 
  if(root != NULL){ 
    inOrder(root->left); 
    cout << root->data <<" "; 
    inOrder(root->right); 
  } 
} 

void preOrder(Node* root){ 
  if(root != NULL){ 
    cout << root->data <<" "; 
    preOrder(root->left); 
    preOrder(root->right); 
  } 
} 

void postOrder(Node* root){ 
  if(root != NULL){ 
    postOrder(root->left); 
    postOrder(root->right);
    cout << root->data <<" ";  
  } 
} 

void max(Node* root){
  if(root->right != NULL){ 
    max(root->right);  
  } 
  else
    cout << root->data <<" ";
}

void min(Node* root){
  if(root->left != NULL){ 
    min(root->left);  
  } 
  else
    cout << root->data <<" ";
}

int main(){ 
  int arr[] = {10, 5, 100, -1, 3, 70, 50}; 
  int n = sizeof(arr)/sizeof(arr[0]);
  
  Node* root = insertLevelOrder(arr, root, 0, n);

  cout << "InOrder: "; inOrder(root); cout << endl;
  cout << "PreOrder: "; preOrder(root); cout << endl;
  cout << "PostOrder: "; postOrder(root); cout << endl;

  cout << endl;

  cout << "Max: "; max(root); cout << endl; 
  cout << "Min: "; min(root); cout << endl;
} 