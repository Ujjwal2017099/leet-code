class Solution {
public:
    vector<int> diffWaysToCompute(string e) {
        return fun(e);
    }
    vector<int> fun(string s){
        vector<int> ans;
        bool f=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='+' or s[i]=='-' or s[i]=='*'){
                f=1;
                vector<int> l = fun(s.substr(0,i));
                vector<int> r = fun(s.substr(i+1));
                
                for(int j=0;j<l.size();j++){
                    for(int k=0;k<r.size();k++){
                        if(s[i]=='+') ans.push_back(l[j]+r[k]);
                        if(s[i]=='-') ans.push_back(l[j]-r[k]);
                        if(s[i]=='*') ans.push_back(l[j]*r[k]);
                    }
                }
            }
        }
        
        if(!f){
            ans.push_back(stoi(s));
            return ans;
        }
        return ans;
    }
};