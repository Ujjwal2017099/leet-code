class Solution {
public:
    int cnt=0;
    int findTargetSumWays(vector<int>& nums, int target) {
        fun(nums,target,0,0);
        return cnt;
    }
    void fun(vector<int>& n,int t,int x,int sum){
        if(x==n.size()){
            if(sum == t) cnt++;
            return;
        }
        
        fun(n,t,x+1,sum+n[x]);
        fun(n,t,x+1,sum-n[x]);
    }
};