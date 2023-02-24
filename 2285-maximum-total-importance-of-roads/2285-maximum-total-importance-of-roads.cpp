class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& r) {
        vector<int> v(n);
        for(auto i:r){
            v[i[0]]++;
            // v[i[0]][1] = i[0];
            v[i[1]]++;
            // v[i[1]][1] = i[1];
        }
        sort(v.begin(),v.end());
        long long ans=0;
        long long cnt=1;
        for(int i:v){
            long long t = i;
            ans += t*cnt++;
        }
        return ans;
    }
};