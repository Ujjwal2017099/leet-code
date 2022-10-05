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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* a = new TreeNode(val);
            a->left = root;
            return a;
        }
        return fun(root,val,depth);
    }
    TreeNode* fun(TreeNode* node,int val,int d){
        if(node==nullptr or d==0){
            return node;
        }
        d--;
        TreeNode* x = fun(node->left,val,d);
        TreeNode* y = fun(node->right,val,d);
        
        if(d==1){
            TreeNode* a = new TreeNode(val);
            TreeNode* b = new TreeNode(val);
            node->left = a;
            a->left = x;
            node->right = b;
            b->right = y;
            return node;
        }
        
        return node;
    }
};