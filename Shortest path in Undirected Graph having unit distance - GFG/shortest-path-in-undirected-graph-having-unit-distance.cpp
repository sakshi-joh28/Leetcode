//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
       int dist[N];
       vector<int>adj[N];
       int u,v=0;
       for(int i=0;i<M;i++)
       {
            u=edges[i][0];
            v=edges[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       for(int i=0;i<N;i++)
       dist[i] = 1e9;
       dist[src] = 0;
       queue<pair<int,int>>q;
       q.push({src,0});
       while(!q.empty())
       {
           int node=q.front().first;
           int dis=q.front().second;
           q.pop();
           for(auto it:adj[node])
           {
               if(dist[it]>(dis+1))
               {
               dist[it]=dis+1;
               q.push({it,dis+1});
           }
           
       }
    }
    vector<int>ans;
    for(int i=0;i<N;i++)
    {
        if(dist[i]==1e9)
        ans.push_back(-1);
        else 
        ans.push_back(dist[i]);
    }
    return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends