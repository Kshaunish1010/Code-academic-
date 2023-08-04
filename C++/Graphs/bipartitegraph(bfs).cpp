#include<bits/stdc++.h>
using namespace std;
bool bfs(int s,vector <int> adj[],vector<int>&col)
    {
        col[s]=1;
        queue <int> q;
        q.push(s);
        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
        for(auto i:adj[node])
        {
            if(col[i]==-1)
            {
                q.push(i);
                col[i]=1-col[node];

            }
            else if(col[i]==col[node])
            {
                return false;
            }
        }
        }
       return true;
}
bool checkbipartite(vector<int> adj[],int s)
{
    vector <int> col(s,-1);
    for(int i=0;i<s;i++)
    {
        if(col[i]==-1)
        {
            if(!bfs(i,adj,col))
              return false;
        }
    }
    return true;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	
	if(checkbipartite(adj, n)) {
	    cout << "yes"; 
	} else {
	    cout << "No"; 
	}
	return 0;
}