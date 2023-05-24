//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long fun(string& s,int k){
        int arr[26]={0};
    	long long ans=0;
    	int l=0;
    	int n=s.size();
    	int cnt=0;
    	for(int i=0;i<n;i++){
    	    if(!arr[s[i]-'a']) cnt++;
    	    arr[s[i]-'a']++;
    	    
    	    
    	    bool f=0;
    	    while(cnt>k ){
    	        f=1;
    	        arr[s[l]-'a']--;
    	        
    	        if(!arr[s[l]-'a']) cnt--;
    	        l++;
    	       // if(cnt==k) ans++;
    	    }
    	    ans+=i-l+1;
    	}
    	return ans;
    }
    long long int substrCount (string& s, int k) {
    	return fun(s,k) - fun(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends