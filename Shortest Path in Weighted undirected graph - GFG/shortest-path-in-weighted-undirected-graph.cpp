//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int>dist(n+1,1e9);
        dist[1]=0;
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++)
           parent[i] =i;
        vector<pair<int,int>>ad[n+1];
     
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            ad[u].push_back({v,wt});
            ad[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:ad[node])
            {
                int child=it.first;
                int wt=it.second;
                if(dis+wt<dist[child])
                {
                    dist[child]=dis+wt;
                    pq.push({dist[child],child});
                    parent[child]=node;
                }
            }
        }
        if(dist[n]==1e9)
        return {-1};
        else
        {
     vector<int>ans;
     int i=n;
     while(i!=parent[i])
     {
         ans.push_back(i);
         i=parent[i];
     }
     ans.push_back(1);
     reverse(ans.begin(),ans.end());
     return ans;
    }
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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