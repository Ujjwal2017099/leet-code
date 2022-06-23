// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    stack<int> a;
    int n ;
    void fun(stack<int>& s,int n,int size){
        if(size == (n+1)/2){
            return;
        }
        a.push(s.top());
        s.pop();
        
        fun(s,n,size-1);
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int size)
    {
        n = size;
        fun(s,n,size);
        s.pop();
        
        while(!a.empty()){
            s.push(a.top());
            a.pop();
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}
  // } Driver Code Ends