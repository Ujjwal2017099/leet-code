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
    TreeNode* prev,node;
    void flatten(TreeNode* root) {
        prev = nullptr;
        fun(root);
        // root->left=nullptr;
    }
    void fun(TreeNode* root){
        if(root == nullptr) return;
        
        
        fun(root->right);
        fun(root->left);
        // fun(root->right);
        // if(prev==nullptr) {}
        {
            root->right = prev;
            root->left = nullptr;
        }
        prev = root;
    }
};