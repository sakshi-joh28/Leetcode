//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    #define modi 1000000007
    public:
    long long solve(int n ,int k,vector<int>&dp)
    {
        if(n==1)
        return k;
        if(n==2)
        return (k*k)%modi;
        if(dp[n]!=-1)
        return dp[n];
       long long same=((solve(n-2,k,dp)%modi)*(k-1))%modi;
       long long diff=((solve(n-1,k,dp)%modi)*(k-1))%modi;
       long long ans=(same+diff)%modi;
       dp[n]= ans;
       return dp[n];
    }
    long long countWays(int n, int k){
        vector<int>dp(n+1,-1);
      return solve(n,k,dp);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends