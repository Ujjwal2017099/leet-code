
class Solution {
public:
    long long prev;
    bool isValidBST(TreeNode* root) {
        prev = LLONG_MIN;
        return inorder(root);
    }
    bool inorder(TreeNode* root){
        if(root==nullptr){
            return true;
        }
        
        bool f1 = inorder(root->left);
        if(root->val > prev){
            prev = root->val;
        }
        else return false;
        bool f2 = inorder(root->right);
        return f1&f2;
    }
};