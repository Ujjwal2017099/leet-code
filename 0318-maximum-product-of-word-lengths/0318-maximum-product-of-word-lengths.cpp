class Solution {
public:
    int maxProduct(vector<string>& w) {
        vector<vector<int>> v(w.size(),vector<int>(26,0));
        for(int i=0;i<w.size();i++){
            for(char c:w[i]){
                v[i][c-'a']++;
            }
            // for(int i:v[i]) cout<<i<<" ";
            // cout<<endl;
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                bool f=0;
                for(int k=0;k<26;k++){
                    if(v[i][k] && v[j][k]){
                        f=1;
                        break;
                    }
                }
                if(!f) {ans=max(ans,(int)(w[i].size()*w[j].size()));}
            }
        }
        return ans;
    }
};