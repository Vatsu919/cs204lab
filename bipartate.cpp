#include <bits/stdc++.h> 
using namespace std; 
  

void adde(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

bool isBipartite(vector<int> adj[], int v, 
                 vector<bool>& visited, vector<int>& color) 
{ 
  
    for (int u : adj[v]) { 
  
        
        if (visited[u] == false) { 
  
            
            visited[u] = true; 
  
          
            color[u] = 1-color[v]; 
  
            
            if (!isBipartite(adj, u, visited, color)) 
                return false; 
        } 
  
        
        else if (color[u] == color[v]) 
            return false; 
    } 
    return true; 
} 
  

int main() 
{ 
    
    int N,m,k;
    cin>>N>>m;
     
  
   
    vector<int> adj[N + 1]; 
  
  
    vector<bool> visited(N + 1); 
  
  
    vector<int> color(N + 1); 
  
   
    for(int i=1;i<=m;i++)
    {
        int y,z;
        cin>>y>>z;
        if(i==1)
        {
            k=y;
        }
        adde(adj, y, z); 
    }
    
  
   
    visited[k] = true; 
  
    
    color[k] = 0; 
  
   
    if (isBipartite(adj, k, visited, color)) { 
        cout << "Graph is Bipartite"; 
    } 
    else { 
        cout << "Graph is not Bipartite"; 
    } 
  
    return 0; 
} 
