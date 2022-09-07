
class Solution {
public:
    string s="";
    string tree2str(TreeNode* root) {
        s += to_string(root->val);
        if(root->left) fun(root->left);
        else if(root->right) s+="()";
        if(root->right) fun(root->right);
        return s;
    }
    void fun(TreeNode* node){
        s+="(";
        s += to_string(node->val) ;
        if(node->left) {
            fun(node->left);
        }
        else if(node->right) s += "()";
        if(node->right) fun(node->right);
        
        s+=")";
    }
};