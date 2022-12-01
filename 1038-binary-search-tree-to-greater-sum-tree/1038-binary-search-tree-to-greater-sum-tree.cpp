/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum=0;
    TreeNode* bstToGst(TreeNode* root) {
        fun(root);
        return root;
    }
    void fun(TreeNode* node){
        if(!node){
            return ;
        }
        fun(node->right);
        sum += node->val;
        node->val = sum;
        fun(node->left);
    }
};