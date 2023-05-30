class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
        long long cnt=0,prd=1;
        for(int i:n){
            if(i!=0){
                prd*=i;
            }else{
                cnt++;
            }
        }
        for(int& i:n){
            if(i==0 && cnt==1){
                i=prd;
            }else if(cnt){
                i=0;   
            }else {
                i=prd/i;
            }
        }
        return n;
    }
};