class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return fun(nums,0,nums.size()-1,0,0,1);
    }
    bool fun(vector<int>& n,int l,int r,int p1,int p2,int ch){
        if(l>r){
            return p1>=p2;
        }
        bool f;
        if(ch&1) {
            bool t1,t2;
            t1=fun(n,l+1,r,p1+n[l],p2,ch+1);
            t2=fun(n,l,r-1,p1+n[r],p2,ch+1);
            f=t1|t2;
        } else{
            bool t1,t2;
            t1=fun(n,l+1,r,p1,p2+n[l],ch+1);
            t2=fun(n,l,r-1,p1,p2+n[r],ch+1);
            f=t1&t2;
        }
        
        return f;
    }
};