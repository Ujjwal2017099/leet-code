class Solution {
public:
    int findSmallestInteger(vector<int>& n, int v) {
        unordered_map<int,int> m;
        for(int& i:n){
            i %= v;
            i += v;
            i %= v;
            m[i]++;
        }
        
        int ans=0;
        while(m[ans%v]--){
            ans++;
        }
        return ans;
    }
};