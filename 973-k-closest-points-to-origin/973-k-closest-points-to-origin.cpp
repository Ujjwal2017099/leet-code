class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        vector<vector<int>> kp;
        sort(p.begin(),p.end(),[&](vector<int> a,vector<int> b){
            int d1 = a[0]*a[0] + a[1]*a[1];
            int d2 = b[0]*b[0] + b[1]*b[1];
            return d1<d2;
        });
        for(int i=0;i<k;i++) kp.push_back(p[i]);
        
        return kp;
    }
};