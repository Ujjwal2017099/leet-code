class Solution {
public:
    TreeNode* root=nullptr;
    bool findTarget(TreeNode* node, int k) {
        root = node;
        if(!node->left and !node->right) return 0;
        return fun(node,k);
    }
    bool fun(TreeNode* node,int k){
        if(node==nullptr){
            return 0;
        }
        return find(root,node,k-(node->val))|fun(node->left,k)|fun(node->right,k);
    }
    bool find(TreeNode* node,TreeNode* curr,int t){
        if(node==nullptr){
            return 0;
        }
        if(node->val==t and node!=curr){
            return 1;
        }
        
        if(node->val>t){
            return find(node->left,curr,t);
        }else{
            return find(node->right,curr,t);
        }
    }
};