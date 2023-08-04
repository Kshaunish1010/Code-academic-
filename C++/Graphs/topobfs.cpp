#include<bits/stdc++.h>
using namespace std;

class topological
{
    public:
    vector<int> toposort(int n,vector<int> adj[])
    {
        queue<int> q;
        vector<int> indegree(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(auto j:adj[i])
            {
                indegree[j]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!indegree[i])
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adj[node])
            {

                indegree[i]--;
                if(!indegree[i])
                {
                    q.push(i);
                }
            }
           
        }
        return ans;
    }
};
int main()
{

    	vector<int> adj[6];
    	adj[5].push_back(2);
    	adj[5].push_back(0);
    	adj[4].push_back(0);
    	adj[4].push_back(1);
    	adj[3].push_back(1);
    	adj[2].push_back(3);

    	topological obj;
    	vector<int> v=obj.toposort(6, adj);
    	for(auto it:v)
    	cout<<it<<" ";
    

    return 0;
}