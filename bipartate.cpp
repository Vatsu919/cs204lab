#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<bool> vis;
vector<int> colour;
void adde(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int bipartate(int v)
{
    for(int u : adj[v])
    {
        if(!vis[u])
        {
    
            vis[u]=true;
            colour[u]=1-colour[v];
            if(!bipartate(u))
            {
                return 0;
            }
        
        }
        else if(colour[u]==colour[v])
        {
            return 0;
        }
    }
    
return 1;
}
int main()
{
   
    //vector<int> adj[3];
    //vector<bool> vis;
    //vector<int> colour;
    //cin>>n>>m;
   /*  for(int i=1;i<=m;i++)
    {
        int u,v;
        
        cin>>u>>v;
        if(i==1)
        {
            k=u;
        }
        adde(adj,u,v);
    }*/
    adde(1,2);
    adde(2,1);
    colour[1]=0;
    vis[1]=true;
    if(bipartate(1)==1)
    {
        cout<<"Yes it is bipartate";
    }
    else
    {
        cout<<"not bipartate";
    }
    

}
