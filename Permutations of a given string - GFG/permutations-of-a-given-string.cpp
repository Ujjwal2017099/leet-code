// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int j=0;
    vector<string> ans;
    map<string,bool> mp;
	public:
	    void fun(string s){
	        if(mp[s]) return;
	        mp[s] = true;
	        
	        for(int i = j ; i >= 1 ; i--){
	            swap(s[i],s[i-1]);
	            fun(s);
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    j = s.length()-1;
		    fun(s);
		    for(auto i:mp) ans.push_back(i.first);
		    
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends