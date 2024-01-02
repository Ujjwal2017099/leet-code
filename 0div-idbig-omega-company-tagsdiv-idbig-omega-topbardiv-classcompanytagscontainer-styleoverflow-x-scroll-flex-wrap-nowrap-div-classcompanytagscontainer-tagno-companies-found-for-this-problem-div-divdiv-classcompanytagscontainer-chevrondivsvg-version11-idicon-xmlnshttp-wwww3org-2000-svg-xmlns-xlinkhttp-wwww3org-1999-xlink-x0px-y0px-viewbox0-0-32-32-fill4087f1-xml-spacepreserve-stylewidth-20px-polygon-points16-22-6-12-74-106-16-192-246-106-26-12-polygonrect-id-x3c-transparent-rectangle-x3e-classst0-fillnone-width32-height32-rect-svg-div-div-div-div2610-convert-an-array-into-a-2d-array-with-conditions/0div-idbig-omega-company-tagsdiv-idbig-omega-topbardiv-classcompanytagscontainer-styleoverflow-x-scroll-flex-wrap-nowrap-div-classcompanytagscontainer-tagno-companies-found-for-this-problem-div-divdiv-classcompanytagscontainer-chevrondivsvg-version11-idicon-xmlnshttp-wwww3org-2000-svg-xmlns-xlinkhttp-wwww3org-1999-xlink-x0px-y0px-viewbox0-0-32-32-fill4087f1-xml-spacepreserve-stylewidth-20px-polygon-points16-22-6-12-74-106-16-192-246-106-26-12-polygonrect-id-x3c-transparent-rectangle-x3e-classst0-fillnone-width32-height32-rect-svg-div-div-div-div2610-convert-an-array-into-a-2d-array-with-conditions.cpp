class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& n) {
        map<int,int> cnt;
        for(int& i:n) cnt[i]++;
        vector<vector<int>> ans;
        
        bool f=0;
        
        do{
            f=0;
            vector<int> t;
            for(auto& it:cnt){
                if(it.second){
                    it.second--;
                    t.push_back(it.first);
                    f=1;
                }
            }
            if(f) ans.push_back(t);
        }while(f);
        return ans;
    }
};