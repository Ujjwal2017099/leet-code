class Solution {
public:
    void total(TreeNode* root,int* s)
    {
        if(root == NULL) return;
        
        total(root->right,s);
        *s += root->val;
        root->val = *s;
        total(root->left,s);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum =0 ;
        total(root,&sum);
        return root;
    }
};