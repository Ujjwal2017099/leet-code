class Solution {
public:
    double average(vector<int>& s) {
        sort(s.begin(),s.end());
        long long sm=0;
        for(int i=1;i<s.size()-1;i++){
            sm+=s[i];
        }
        return sm/(double)(s.size()-2);
    }
};