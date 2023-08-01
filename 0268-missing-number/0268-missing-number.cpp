class Solution {
public:
    int missingNumber(vector<int>& v) {
        long long n=v.size();
        int sm = (n*(n+1))/2;
        for(int i:v) sm-=i;
        return sm;
    }
};