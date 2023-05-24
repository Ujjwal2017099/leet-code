class Solution {
public:
    int majorityElement(vector<int>& n) {
        int x=n.size()/2;
        unordered_map<int,int> cnt;
        for(int i=0;i<n.size();i++){
            cnt[n[i]]++;
        }
        for(auto& it:cnt){
            if(it.second > x) return it.first;
        }
        return n[0];
    }
};