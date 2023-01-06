class Solution {
public:
    int maxIceCream(vector<int>& c, int coins) {
        sort(c.begin(),c.end());
        int cnt=0;
        for(int i:c){
            if(coins==0 || coins < i) break;
            coins -= i;
            cnt++;
        }
        return cnt;
    }
};