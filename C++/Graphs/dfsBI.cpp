#include<bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int node,vector<int> adj[],vector<int> &col)
    {
        for(auto i:adj[node])
        {
            if(col[i]==-1)
            {
                col[i]=1-col[node];
                if(dfs(i,adj,col))
                   return true;
            }
            else if(col[i]==col[node])
            {
                return true;
            }
        }
        return false;
    }
    public:
    bool checkbipartite(int n,vector<int>adj[])
    {
        vector<int> col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                col[i]=1;
                if(dfs(i,adj,col))
                   return true;
            }
        }
        return false;
    }
};
void addedge(vector<int> adj[],int u,int v)
{
        adj[u].push_back(v); 
        adj[v].push_back(u);
}
int main() {
    
    vector<int> adj[6];
    addedge(adj,0,1);
    addedge(adj,0,5);
    addedge(adj,1,2);
    addedge(adj,1,4);
    addedge(adj,1,5);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,3,5);
    Solution obj;

    if(!obj.checkbipartite(6,adj)) {
        cout << "It is a Bipartite Graph"; 
    } else {
        cout << "It is not a Bipartite Graph"; 
    }
    return 0;
}