// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	public:
	void shuffleArray(int arr[],int n)
	{
	    vector<int> v;
	    for(int i=0;i<n/2;i++) v.push_back(arr[i]);
	    
	    fun(v,arr,n,0);
	    
	    for(int i=0;i<n;i++){
	        arr[i] = v[i];
	    }
	}
		 
    void fun(vector<int>& v,int arr[],int n,int i){
        if(i>=n/2) return;
        // if(i!=0) v.insert(v.begin()+i+2,arr[i+n/2]);
        v.insert(v.begin()+i+i+1,arr[i+n/2]);
        fun(v,arr,n,i+1);
    }
};

// { Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends