//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
void solve(stack<int>&st,stack<int>&new_st,int n )
{
    if(n==0 )
    return ;
    if(n>=1)
    {
        new_st.push(st.top());
        st.pop();
        solve(st,new_st,n-1);
    }
}
    void Reverse(stack<int> &st){
        stack<int>new_st;
         solve(st,new_st,st.size());
         st=new_st;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends