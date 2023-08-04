#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector <int> bfs(int s,vector <int> adj[])
    {
        vector <int> vis(s,0);
        vector <int> ans;
        vis[0]=1;
        queue <int> q;
        q.push(0);
        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i]=1;

            }
        }
        }
        return ans;
    }
};
void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void printAns(vector < int > & ans) {
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}

int main()
{
    vector <int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 4);

    Solution obj;
    vector < int > ans = obj.bfs(5, adj);
    printAns(ans);
    cout << endl;
    return 0;
}