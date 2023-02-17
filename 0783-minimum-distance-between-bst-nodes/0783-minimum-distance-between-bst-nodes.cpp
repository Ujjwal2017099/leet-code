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
    int prev=-1;
    int ans=1e9;
    int minDiffInBST(TreeNode* root) {
        fun(root);
        return ans;
    }
    void fun(TreeNode* node){
        if(!node){
            return;
        }
        
        fun(node->left);
        if(prev!=-1) ans = min(ans,node->val-prev);
        prev = node->val;
        fun(node->right);
        
    }
};