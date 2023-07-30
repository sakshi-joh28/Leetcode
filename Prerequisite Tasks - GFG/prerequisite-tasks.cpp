//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
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
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[N];
	    for(auto it:prerequisites)
	    adj[it.first].push_back(it.second);
	     vector<int>ans;
	    vector<int>indegree(N,0);
	    for(int i=0;i<N;i++)
	    {
	        for(auto it:adj[i])
	            indegree[it]++;
	    }
	    bfs(indegree,adj,ans,N);
	   if(ans.size()==N)
	   return 1;
	   return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends