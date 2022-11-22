class Solution {
public:
    TreeNode* first;
    TreeNode* second;
    TreeNode* ptr;
    void inorder(TreeNode* root)
    {
        if(!root) return;
        
        inorder(root->left);
        
        if(first == nullptr and ptr->val > root->val) {
            first = ptr;
        }
        if(first != nullptr and ptr->val > root->val) {
            second = root;
        }
        ptr = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        ptr = new TreeNode(INT_MIN);
        inorder(root);
        swap(first->val,second->val);
    }
};