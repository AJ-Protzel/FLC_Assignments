#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

class AdjacencyMatrix{
    private:
      int n;
      int **adj;
      bool *visited;

    public:
      AdjacencyMatrix(int n){
        this->n = n;
        visited = new bool [n];
        adj = new int* [n];
        for (int i = 0; i < n; i++){
          adj[i] = new int [n];
          for(int j = 0; j < n; j++){
            adj[i][j] = 0;
          }
        }
      }

      void addEdgeM(int origin, int destin){
        if(origin > n || destin > n || origin < 0 || destin < 0){   
          cout<<"Invalid edge!\n";
        }
        else{
          adj[origin - 1][destin - 1] = 1;
        }
      }

      void displayM(){
        int i, j;
        cout << "  _1__2__3__4__5__6__7__8__9" << endl;
        for(i = 0; i < n; ++i){
          cout << i+1 << "| ";
          for(j = 0; j < n; j++)
            cout<<adj[i][j]<<"  ";
            cout<<endl;
          }
        }
};

void addEdgeL(vector<int> adj[], int u, int v){ 
  adj[u].push_back(v); 
  adj[v].push_back(u); 
} 

void displayL(vector<int> adj[], int V){ 
  for (int v = 1; v < V; ++v) { 
    cout << "\n " << v << "\n head "; 
    for (auto x : adj[v]) 
      cout << "-> " << x; 
    printf("\n"); 
  } 
} 
//****************************************************************************************Main
int main(){
  cout << "1: Oxford Circus\n2: Tottenham Court Road\n3: Holborn\n4: Leicester Square\n5: Green Park\n6: Piccadilly\n7: Charing Cross\n8/9: Embankment" << endl << endl;

  int nodes = 9;
  //int max_edges = 72;

  AdjacencyMatrix am(nodes);

  am.addEdgeM(1, 2);  am.addEdgeM(1, 5);  am.addEdgeM(1, 6);
  am.addEdgeM(2, 1);  am.addEdgeM(2, 3);  am.addEdgeM(2, 4);
  am.addEdgeM(3, 2);  am.addEdgeM(3, 4);
  am.addEdgeM(4, 2);  am.addEdgeM(4, 3);  am.addEdgeM(4, 6);  am.addEdgeM(4, 7);
  am.addEdgeM(5, 1);  am.addEdgeM(5, 6);
  am.addEdgeM(6, 1);  am.addEdgeM(6, 4);  am.addEdgeM(6, 5);  am.addEdgeM(6, 7);
  am.addEdgeM(7, 4);  am.addEdgeM(7, 6);  am.addEdgeM(7, 8);  am.addEdgeM(7, 9);
  am.addEdgeM(8, 7);  am.addEdgeM(8, 9);
  am.addEdgeM(9, 7);  am.addEdgeM(9, 8);

  int v = nodes+1;

  vector<int> adj[v]; 
  addEdgeL(adj, 1, 2); 
  addEdgeL(adj, 1, 6);
  addEdgeL(adj, 1, 5); 
  addEdgeL(adj, 2, 4); 
  addEdgeL(adj, 2, 3); 
  addEdgeL(adj, 3, 4); 
  addEdgeL(adj, 4, 6); 
  addEdgeL(adj, 4, 7);
  addEdgeL(adj, 5, 6);
  addEdgeL(adj, 6, 7);
  addEdgeL(adj, 7, 8);
  addEdgeL(adj, 7, 9);
  addEdgeL(adj, 8, 9);
  
  am.displayM();
  cout << endl;
  displayL(adj, v);

  return 0;
}