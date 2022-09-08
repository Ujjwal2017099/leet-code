
var arr = [];
var inorderTraversal = function(root) {
    arr = [];
    fun(root);
    return arr;
};
function fun(root){
    if(root===null){
        return;
    }
    
    fun(root.left);
    arr.push(root.val);
    fun(root.right);
}