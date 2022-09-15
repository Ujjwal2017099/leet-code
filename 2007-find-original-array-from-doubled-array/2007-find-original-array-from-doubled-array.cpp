class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        if(c.size()&1){
            return {};
        }
        sort(c.begin(),c.end());
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i:c){
            m[i]++;
        }
        for(int i:c){
            int a = 2*i;
            if(a==i and m[a]==1) continue;
            if(m[a] and m[i]){
                ans.push_back(i);
                m[a]--;
                m[i]--;
            }
        }
        if(ans.size() == c.size()/2) return ans;
        return {};
    }
};