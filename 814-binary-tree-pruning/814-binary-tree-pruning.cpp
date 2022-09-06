
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool f = fun(root);
        if(!f) root=nullptr;
        return root;
    }
    bool fun(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        
        bool l = fun(node->left);
        bool r = fun(node->right);
        
        if(!l) node->left = nullptr;
        if(!r) node->right = nullptr;
        
        return l|r|node->val;
    }
};