//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int mod= 1e9+7;
    public:
    long long solve(int n ,int k ,vector<int>&dp)
    {
        if(n==1)
        return k;
        if(n==2)
        return (k*k)%mod;
        if(dp[n]!=-1)
        return dp[n]%mod;
        long long  temp1=solve(n-2,k,dp)%mod;
        long long temp2=solve(n-1,k,dp)%mod;
        int x=(temp1*(k-1)%mod)%mod;
        int y=(temp2*(k-1)%mod)%mod;
       long long  ans=(x+y)%mod;
        dp[n]=ans;
        return dp[n];
    }
    long long countWays(int n, int k){
        // code here
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