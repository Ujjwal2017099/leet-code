class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& i, vector<int>& ni) {
        vector<vector<int>> ans;
        vector<vector<int>> t;
        bool f=0;
        for(auto it:i){
            if((ni[0]>=it[0] && ni[0]<=it[1]) || (ni[1] <= it[1] && ni[1]>=it[0])){
                t.push_back({min(ni[0],it[0]),max(ni[1],it[1])});
                f=1;
            }
            else{
                t.push_back(it);
            }
        }
        if(!f) t.push_back(ni);
        sort(t.begin(),t.end());
        for(auto it:t){
            if(ans.empty()){
                ans.push_back(it);
            }
            else {
                vector<int> x = ans.back();
                if(x[0]<=it[0] && x[1]>=it[0]){
                    ans.back()[0] = min(x[0],it[0]);
                    ans.back()[1] = max(x[1],it[1]);
                }else{
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};