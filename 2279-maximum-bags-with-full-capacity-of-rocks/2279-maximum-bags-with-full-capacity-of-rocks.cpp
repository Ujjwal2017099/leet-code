class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int ar) {
        vector<int> t(c.size());
        for(int i=0;i<c.size();i++){
            t[i] = c[i]-r[i]; 
        }
        sort(t.begin(),t.end());
        int cnt=0;
        for(int i=0;i<t.size();i++){
            if(t[i]>ar) break;
            ar-=t[i];
            cnt++;
        }
        return cnt;
    }
};