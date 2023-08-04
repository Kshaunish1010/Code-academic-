#include<bits/stdc++.h>
using namespace std;

class Solution{
    void solve(int node,vector<int>&vis,vector<int> adj[],vector<int> &ans)
    {
        ans.push_back(node);
        vis[node]=1;
        for(auto j:adj[node])
        {
            if(!vis[j])
              {
                solve(j,vis,adj,ans);
              }
        }
    }
    public:
    vector <int> dfs(int s,vector<int> adj[])
    {
        vector <int> ans;
        vector <int> vis(s+1,0);
        for(int i=1;i<=s;i++)
        {
            if(!vis[i]) solve(i,vis,adj,ans);
        }
        return ans;
    }
};
void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}


int main()
{
    vector<int> adj[6];
    
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,2,4);
    addEdge(adj,2,1);
    addEdge(adj,3,1);
    addEdge(adj,4,1);
    addEdge(adj,4,2);
    addEdge(adj,5,1);
    Solution obj;
    vector<int> df;
    df= obj.dfs(5, adj);
    for(auto it: df)
    cout<<it<<" ";
    return 0;
}


