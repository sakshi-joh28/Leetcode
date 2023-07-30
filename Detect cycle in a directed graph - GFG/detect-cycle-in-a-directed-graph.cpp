//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    	void bfs(vector<int>&indegree,vector<int>adj[],vector<int>&ans,int V)
	{
	    queue<int>q;
	    for(int i=0;i<V;i++)
	    if(indegree[i]==0)
	    q.push(i);
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        ans.push_back(temp);
	        for(auto it:adj[temp])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
	}
    bool isCyclic(int V, vector<int> adj[]) {
          vector<int>ans;
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	            indegree[it]++;
	    }
	    bfs(indegree,adj,ans,V);
	    if(ans.size()<V)
	    return 1;
	    return 0;
	   
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends