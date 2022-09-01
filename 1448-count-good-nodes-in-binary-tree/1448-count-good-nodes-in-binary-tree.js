
var cnt=0;
var goodNodes = function(root) {
    cnt=0;
    fun(root,root.val);
    return cnt;
};
function fun(root,val){
    if(root===null){
        return;
    }
    if(root.val >= val){
        val = root.val;
        cnt++;
    }
    fun(root.left,val);
    fun(root.right,val);
}