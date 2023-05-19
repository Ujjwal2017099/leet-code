class Solution {
public:
    int minStartValue(vector<int>& n) {
        int ans=1;
        while(1){
            bool f=1;
            int temp=ans;
            for(int& i:n){
                temp += i;
                if(temp<1) {
                    f=0;
                    break;
                }
            }
            if(f) return ans;
            ans++;
        }
        return 1;
    }
};