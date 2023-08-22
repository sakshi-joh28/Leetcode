//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int>&visit,vector<int>adj[],int node,vector<int>&path)
    {
        visit[node]=1;
        path[node]=1;
        for(auto it:adj[node])
        {
            if(visit[it]==1 && path[it]==1)
            {
                return true;
            }
            if(!visit[it])
           {
            if(dfs(visit,adj,it,path)==true)
            return true;
        }
        }
         path[node]=0;
         return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visit(V,0);
        vector<int>path(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visit[i])
           if( dfs(visit,adj,i,path)==true)
           return true;
        }
    return false;
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