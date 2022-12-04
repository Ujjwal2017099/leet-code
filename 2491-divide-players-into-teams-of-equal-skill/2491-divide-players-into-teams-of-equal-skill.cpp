class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        sort(s.begin(),s.end());
        int sum = s[0] + s.back();
        long long ans = s[0]*s.back();
        int i=1,j=s.size()-2;
        while(i<j){
            if(s[i]+s[j]==sum){
                long long x = s[i]*s[j];
                ans+=x;
            }
            else return -1;
            i++;j--;
        }
        return ans;
    }
};