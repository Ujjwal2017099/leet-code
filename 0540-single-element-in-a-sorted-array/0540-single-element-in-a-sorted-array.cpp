class Solution {
public:
    int singleNonDuplicate(vector<int>& n) {
        map<int,int> cnt;
        for(int i:n) cnt[i]++;
        for(auto it:cnt){
            if(it.second==1) return it.first;
        }
        return -1;
    }
};