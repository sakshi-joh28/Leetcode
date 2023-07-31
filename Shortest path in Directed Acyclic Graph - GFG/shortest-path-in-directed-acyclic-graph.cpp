//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void dfs(int node,vector<int>&visit,vector<pair<int,int>>adj[],stack<int>&st)
  {
      visit[node]=1;
      for(auto it:adj[node])
      {
          if(!visit[it.first])
          dfs(it.first,visit,adj,st);
      }
        st.push(node);
  }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<pair<int,int>>adj[N];
         for(int i=0;i<M;i++)
         {
             int u=edges[i][0];
             int edge=edges[i][1];
             int wei=edges[i][2];
             adj[u].push_back({edge,wei});
         }
         stack<int>st;
         vector<int>visit(N,0);
         for(int i=0;i<N;i++)
         {
             if(!visit[i])
             dfs(i,visit,adj,st);
         }
         vector<int>dist(N);
         for(int i=0;i<N;i++)
         dist[i]=1e9;
         dist[0]=0;
         while(!st.empty())
         {
             int parent=st.top();
             st.pop();
             for(auto it:adj[parent])
             {
                 dist[it.first]=min(dist[it.first],(dist[parent]+it.second));
             }
         }
         for(int i=0;i<dist.size();i++)
         {
             if(dist[i]==1e9)
             dist[i]=-1;
         }
         return dist;
     }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends