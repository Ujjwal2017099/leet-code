class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int t[2001] = {0};
        int t2[2001] = {0};
        for(int i:arr){
            t[i+1000]++;
        }
        for(int i:t){
            if(i==0) continue;
            if(t2[i]!=0) return 0;
            t2[i] = 1;
        }
        return 1;
    }
};