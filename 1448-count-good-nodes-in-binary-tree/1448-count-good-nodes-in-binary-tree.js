/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
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