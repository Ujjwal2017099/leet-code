class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL and root->val != val)
        {
            if(root->val > val) root = root->left;
            else root = root->right;
        }
        
        return root;
    }
};