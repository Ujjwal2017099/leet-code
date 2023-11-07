class Solution {
public:
    int eliminateMaximum(vector<int>& d, vector<int>& s) {
        int n=d.size();
        vector<double> t;
        for(int i=0;i<n;i++){
            t.push_back((double)d[i]/s[i]);
        }
        sort(t.begin(),t.end());
        double curr=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(t[i]>curr) {
                ans++;curr++;
            }else{
                break;
            }
        }
        return ans;
    }
};