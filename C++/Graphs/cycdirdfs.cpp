#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int node,int vis[],int dis[],vector<int> adj[])
    {
        vis[node]=1;
        dis[node]=1;
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                if(dfs(i,vis,dis,adj))
                   return true;
            }
            else if(dis[i]&&vis[i])
                return true;

        }
        dis[node]=0;
        return false;
    }
    public:
    bool checkcycle(int n,vector<int> adj[])
    {
        int vis[n],dis[n];
        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,dis,adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
}

int main() {

  int V = 6;

  vector < int > adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 5);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  //addEdge(adj, 4, 0);
  //addEdge(adj, 4, 1);
  

  Solution obj;
  if (obj.checkcycle(V, adj))
    cout << "Cycle Detected" << "\n";
  else
    cout << "No Cycle Detected";

  return 0;
}