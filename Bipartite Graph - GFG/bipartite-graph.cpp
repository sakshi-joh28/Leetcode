//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool check(int V,vector<int>adj[],vector<int>&visit,int i){
  queue<int>q;
	   q.push(i);
	   visit[i]=0;
	   while(!q.empty())
	   {
	       int node=q.front();
	       q.pop();
	       for(auto it:adj[node])
	       {
	           if(visit[it]==-1 && visit[node]==0)//if(tehy dont have color)
	             {
	           visit[it]=1;
	           
	           q.push(it);
	             }
	           else if(visit[it]==-1 && visit[node]==1)
	           {
	           visit[it]=0;
	           q.push(it);
	           }
	           else if(visit[it]==visit[node]) //if they have the color
	           return false;
	       }
	   }
	   return true;
	}
	bool isBipartite(int V, vector<int>adj[]){
	   vector<int>visit(V,-1);
	   for(int i=0;i<V;i++)
	   {
	       if(visit[i]==-1){
	    if(check(V,adj,visit,i)==false)
	    return false;
	   
	   }
	   }
	   return true;
	  
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends