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
    bool hasPathSum(TreeNode* root, int target) {
        if(!root) return 0;
        return fun(root,target,0);
    }
    bool fun(TreeNode* node,int target,int sum){
        
        sum += node->val;
        bool x=0,y=0;
        if(node->left) x=fun(node->left,target,sum);
        if(node->right) y=fun(node->right,target,sum);
        
        if(!node->left and !node->right and sum==target){
            return 1;
        }
        
        return x|y;
    }
};