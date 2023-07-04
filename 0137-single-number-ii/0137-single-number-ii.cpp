class Solution {
public:
    int singleNumber(vector<int>& n) {
        int o=0,t=0,th=0;
        for(int i=0;i<n.size();i++){
            t = t|(o & n[i]);
            o ^= n[i];
            th = o&t;
            o &= ~t;
            t &= ~th;
        }
        return o;
    }
};