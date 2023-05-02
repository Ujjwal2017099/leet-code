class Solution {
public:
    int arraySign(vector<int>& n) {
        int ans=1;
        for(int& i:n){
            if(i==0) ans=0;
            if(i<0) ans*=-1;
        }
        return ans;
    }
};