
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        fun(root);
        return ans;
    }
    void fun(TreeNode* node){
        if(node==nullptr){
            return;
        }
        fun(node->left);
        ans.push_back(node->val);
        fun(node->right);
    }
};