//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int  n=image.size();
        int m =image[0].size();
         int rows[4]={0,-1,1,0};
    int cols[4]={-1,0,0,1};
      vector<vector<int>>visit(n,vector<int>(m,0));
      queue<pair<int,int>>q;
      q.push({sr,sc});
      visit[sr][sc]=1;
      while(!q.empty())
      {
          int row=q.front().first;
          int col=q.front().second;
          int color=image[row][col];
          q.pop();
        
          for(int i=0;i<4;i++)
          {
              int nrow=rows[i]+row;
              int ncol=cols[i]+col;
              if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visit[nrow][ncol]==0 && image[nrow][ncol]==color )
              {
                  q.push({nrow,ncol});
                  visit[nrow][ncol]=1;
                 
              }
          }
      }
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(visit[i][j]==1)
              image[i][j]=newColor;
          }
      }
      return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends