//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
class Solution{
    int minElement;
    stack<int> s;
    public:
       int getMin(){
         if(s.size()==0)
         return -1;
         else
         return minElement;
       }
       int pop(){
           int ele=-1;
          if(s.size()==0)
          return ele;
          else
          {
          if(s.top()>=minElement)
           {
                ele=s.top();
               s.pop();
           }
           else  if(s.top()<minElement)
           {  
               ele=minElement;
               minElement=2*minElement-s.top();
               s.pop();
           }
           return ele;
          }
       }
       
       void push(int x){
            if(s.size()==0)
            {
                minElement=x;
                s.push(x);
            }
            else
            {
             if(x<minElement)
            {
                 s.push(2*x-minElement);
               minElement=x;
            }
            else  if(x>=minElement)
            {          
              s.push(x);
            }
            }
           //Write your code here
       }
};




//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends