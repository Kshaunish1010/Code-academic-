#include<bits/stdc++.h>
using namespace std;

class topological
{
    void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &s)
    {
        vis[node]=1;
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,s);
            }
        }
        s.push(node);
    }    
    public:
    vector<int> toposort(int n,vector<int> adj[])
    {
        stack<int> s;
        vector<int> vis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,s);
            }
        }
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
int main() {

  int N = 6;

  vector < int > adj[5+1];

  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(3);
  adj[3].push_back(4);
  adj[2].push_back(4);
  adj[3].push_back(5);

  topological obj;
  vector < int > res = obj.toposort(5, adj);

  cout << "Toposort of the given graph is:" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
} 