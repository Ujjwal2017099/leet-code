class Solution {
public:
    int getCommon(vector<int>& a, vector<int>& b) {
        for(int i:a){
            auto it = lower_bound(b.begin(),b.end(),i);
            if(it!=b.end() && *it==i) return i;
        }
        return -1;
    }
};