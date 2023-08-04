#include<bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int node,int par,vector <int> adj[],vector<int> &vis)
    {
       vis[node]=1;
       for(auto i:adj[node])
       {
        if(!vis[i])
        {
            if(dfs(i,node,adj,vis))
               return true;
        }
        else if(i!=par)
        {
            return true;
        }
       }
       return false;
    }
    public:
    bool checkCycle(int s,vector<int> adj[])
    {
        vector <int> vis(s+1,0);
        for(int i=0;i<s;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,adj,vis))
                  return true;
            }
            
        }
        return false;
    }
};
void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
int main() {

  int V = 5;
  vector < int > adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 4);

  Solution obj;
  bool ans = obj.checkCycle(V, adj);
  if (ans) {
    cout << "Cycle Detected";
  } else cout << "No Cycle Detected";

  return 0;
}