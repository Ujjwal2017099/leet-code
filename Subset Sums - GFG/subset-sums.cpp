// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    
    vector<int> ans;
    vector<int> subsetSums(vector<int> arr, int n)
    {   
        ans.push_back(0);
        
        // for(int i=0;i<n;i++)
            fun(arr,0,0,n);
        return ans;
    }
    void fun(vector<int> a,int i,int sum,int n)
    {
        if(i>=n) return;
        sum += a[i];
        
        fun(a,i+1,sum,n);
        ans.push_back(sum);
        fun(a,i+1,sum-a[i],n);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends