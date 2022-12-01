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
        if(!node->right && !node->left){
            sum += node->val;
            node->val = sum;
            return ;
        }
        if(node->right) fun(node->right);
        sum += node->val;
        node->val = sum;
        if(node->left) fun(node->left);
    }
};