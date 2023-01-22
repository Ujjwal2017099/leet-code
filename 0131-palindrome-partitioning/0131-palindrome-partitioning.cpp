class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        fun(s,{},0,0);
        return ans;
    }
    void fun(string s,vector<string> t,int i,int l){
        if(i>=s.size()){
            string x = s.substr(l,s.size()-l);
            if(x.empty()) return;
            if(isPal(x)){
                t.push_back(x);
                ans.push_back(t);
            }
            return;
        }
        
        fun(s,t,i+1,l);
        string x = s.substr(l,i-l+1);
        if(isPal(x)){
            t.push_back(x);
            fun(s,t,i+1,i+1);
        }
    }
    bool isPal(string x){
        int l=0,r=x.size()-1;
        while(l<r){
            if(x[l]!=x[r]){
                return 0;
            }
            l++;r--;
        }
        return 1;
    }
};