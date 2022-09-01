/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var cnt=0;
var findTargetSumWays = function(nums, target) {
    cnt=0;
    fun(nums,target,0,0);
    return cnt;
};

function fun(n,t,sum,x){
    if(x===n.length){
        if(sum === t) cnt++;
        return;
    }
    
    fun(n,t,sum+n[x],x+1);
    fun(n,t,sum-n[x],x+1);
}