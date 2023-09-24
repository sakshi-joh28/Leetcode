//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    #define modi 1000000007
    public:
   /* long long solve(int n ,int k,vector<int>&dp)
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
    }*/
    
      long long countWays(int n, int k){
          vector<long long >dp(n+1,-1);
          dp[1]=k;
          dp[2]= (k*k)%modi;
          for(int i=3;i<=n;i++)
          {
             dp[i]=(((dp[i-2]+dp[i-1])%modi)*(k-1))%modi;
          }
          return dp[n]%modi;
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