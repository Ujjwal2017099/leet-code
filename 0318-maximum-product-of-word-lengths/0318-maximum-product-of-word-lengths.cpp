class Solution {
public:
    int maxProduct(vector<string>& w) {
        vector<int> x(w.size());
        
        for(int i=0;i<w.size();i++){
            vector<int> v(26,0);
            for(char c:w[i]){
                v[c-'a'] = 1;
            }
            int b=0,prd=1;
            for(int i:v){
                if(i) b+=prd*2;
                prd*=2;
            }
            x[i]=b;
            // for(int i:v[i]) cout<<i<<" ";
            // cout<<endl;
        }
        int ans=0;
        for(int i=0;i<x.size();i++){
            for(int j=i+1;j<x.size();j++){
                if(!(x[i]&x[j])){
                    ans=max(ans,(int)(w[i].size()*w[j].size()));
                }
            }
        }
        return ans;
    }
};