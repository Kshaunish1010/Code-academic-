#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector <int> shortest(int n,vector<int> adj[],int src)
    {
        vector<int> dis(n,-1);
        queue<int> q;
        dis[src]=0;
        q.push(src);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(dis[node]==-1)
              continue;
            for(auto it:adj[node])
            {
                
                if(dis[it]==-1||dis[node]+1<dis[it])
                {
                    dis[it]=dis[node]+1;
                    q.push(it);
                }
            }
        }
        return dis;
    }
};
void addEdge(vector<int> adj[],int u,int v)
{
        adj[u].push_back(v); 
        adj[v].push_back(u);
}
int main()
{
   int V = 6;

  vector < int > adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 5);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
    	Solution obj;
    	vector<int> v=obj.shortest(6, adj,0);
    	for(auto it:v)
    	cout<<it<<" ";
    return 0;
}