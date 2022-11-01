class Solution {
public:
    int averageValue(vector<int>& n) {
        int cnt=0;
        int sum=0;
        for(int i:n){
            if(!(i&1) and i%3==0){
                sum+=i;
                cnt++;
            }
        }
        if(cnt==0) return 0;
        return sum/cnt;
    }
};