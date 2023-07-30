class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& n, int k) {
        map<int,int> m;
        for(int i=0;i<min(k+1,(int)n.size());i++){
            if(m[n[i]]) return 1;
            m[n[i]]=1;
        }
        int prev=0;
        for(int i=k+1;i<n.size();i++){
            m[n[prev++]]=0;
            if(m[n[i]]) return 1;
            m[n[i]]=1;
        }
        return 0;
    }
};