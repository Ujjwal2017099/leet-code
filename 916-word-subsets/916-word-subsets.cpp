class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        unordered_map<char,int> cnt;
        for(char c:w2[0]){
            cnt[c]++;
        }
        
        for(int i=1;i<w2.size();i++){
            unordered_map<char,int> t;
            for(char c:w2[i]){
                t[c]++;
            }
            for(auto k:t){
                if(cnt[k.first]==0){
                    cnt[k.first] = k.second;
                }
                else if(cnt[k.first] < k.second){
                    cnt[k.first] = k.second;
                }
            }
        }
        
        vector<string> ans;
        for(string s:w1){
            bool f = 1;
            unordered_map<char,int> t;
            for(char c:s){
                t[c]++;
            }
            for(auto k:cnt){
                if(t[k.first] ==0 or t[k.first] < k.second){
                    f = 0;
                    break;
                }
            }
            if(f){
                ans.push_back(s); 
            }
        }
        
        return ans;
    }
};