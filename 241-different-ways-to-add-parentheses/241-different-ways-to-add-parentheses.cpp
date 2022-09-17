class Solution {
public:
    vector<int> diffWaysToCompute(string e) {
        vector<int> ans;
        bool f=0;
        for(int i=0;i<e.length();i++){
            if(e[i]=='+' or e[i]=='-' or e[i]=='*'){
                f=1;
                vector<int> l = diffWaysToCompute(e.substr(0,i));
                vector<int> r = diffWaysToCompute(e.substr(i+1));
                
                for(int j=0;j<l.size();j++){
                    for(int k=0;k<r.size();k++){
                        if(e[i]=='+') ans.push_back(l[j]+r[k]);
                        if(e[i]=='-') ans.push_back(l[j]-r[k]);
                        if(e[i]=='*') ans.push_back(l[j]*r[k]);
                    }
                }
            }
        }
        
        if(!f){
            ans.push_back(stoi(e));
            return ans;
        }
        return ans;
    }
    
};