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
 * @return {number[]}
 */
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