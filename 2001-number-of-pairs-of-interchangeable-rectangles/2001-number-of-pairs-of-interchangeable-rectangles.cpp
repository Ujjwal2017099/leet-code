class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
        map<pair<int,int>,long long> m;
        long long cnt=0;
        for(auto i:r){
            int w = i[0],r = i[1];
            int g = __gcd(w,r);
            w/=g;r/=g;
            cnt+=m[{w,r}];
            m[{w,r}]++;
        }
        return cnt;
    }
};