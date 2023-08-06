//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         int n =grid.size();
                         int m =grid[0].size();
    if(source.first==destination.first && source.second==destination.second)
    return 0;
     vector<vector<int>>dist(n,vector<int>(m,1e9));
     dist[source.first][source.second]=0;
     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
     pq.push({0,{source.first,source.second}});
     int rows[]={-1,1,0,0};
     int cols[]={0,0,-1,1};
     while(!pq.empty())
     {
         int row=pq.top().second.first;
         int col=pq.top().second.second;
         int wt=pq.top().first;
             pq.pop();
         for(int k=0;k<4;k++)
         {
             int newrow=row+rows[k];
             int newcol=col+cols[k];
if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && 
grid[newrow][newcol]==1)
{
    if(wt+1<dist[newrow][newcol])
    {
        dist[newrow][newcol]=wt+1;
        if(newrow==destination.first && newcol==destination.second)
        return dist[newrow][newcol];
        pq.push({dist[newrow][newcol],{newrow,newcol}});
    }
}
}
}
return -1;
    
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends