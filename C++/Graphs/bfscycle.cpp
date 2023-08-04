#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool check(int s,vector <int> adj[],vector<int>&vis)
    {
        vis[s]=true;
        queue <pair<int,int>> q;
        q.push({s,-1});
        while (!q.empty()) 
        {
            int node = q.front().first;
            int par=q.front().second;
            q.pop();
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                q.push({i,node});
                vis[i]=true;
            }
            else if(i!=par)
            {
                return true;                
            }

        }
        }
        return false;
    }
    bool checkcycle(int s,vector<int> adj[])
{
    vector <int> vis(s,0);
    for(int i=0;i<s;i++)
    {
        if(!vis[i])
        {
            if(check(i,adj,vis))
               return true;
        }
    }
}
};


void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
int main()
{
    vector<int> adj[5];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 4);

    Solution obj;
    int num=obj.checkcycle(5, adj);
    if(num==1)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    return 0;
}