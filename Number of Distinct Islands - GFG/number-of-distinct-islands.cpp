//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&visit,
  vector<pair<int,int>>&vec,
  int i,int j ,int n ,int m )
  {
      visit[r][c]=1;
      vec.push_back({r-i,c-j});
      int rows[4]={1,-1,0,0};
      int cols[4]={0,0,1,-1};
      for(int k=0;k<4;k++)
      {
          int nr=rows[k]+r;
          int nc=cols[k]+c;
          if(nr>=0 && nr<n && nc<m && nc>=0 && grid[nr][nc]==1 && visit[nr][nc]==0)
          {
              dfs(nr,nc,grid,visit,vec,i,j ,n ,m);
          }
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n =grid.size();
        int m =grid[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visit[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,visit,vec,i,j,n,m);
                    st.insert(vec);
                }
            }
        }
        return st.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends