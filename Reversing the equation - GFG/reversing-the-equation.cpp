//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
  stack<string>st;
    string reverseEqn (string s)
        {
            //code here.
          
            int i=0,j=0;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]>='0' &&s[i]<='9')
                {  j=i;
                    while(s[j]>='0' &&s[j]<='9')
                       j++;
                      string sub=s.substr(i,j-i);
                       st.push(sub);
                       i=j-1;
                }
                else
                {
                    string rev;
                    rev+=s[i];
                    st.push(rev);
            }
            }
            string ans;
            while(!st.empty())
            {
                ans+=st.top();
                st.pop();
            }
            return ans;
        }
};
       

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends