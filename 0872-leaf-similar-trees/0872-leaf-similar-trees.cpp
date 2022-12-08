class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        fun(a,root1);
        fun(b,root2);
        if(a.size()!=b.size()) return 0;
        
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) return 0;
        }
        return 1;
    }
    void fun(vector<int>& a,TreeNode* node){
        if(!node->left && !node->right){
            a.push_back(node->val);
            return;
        }
        if(node->left) fun(a,node->left);
        if(node->right) fun(a,node->right);
    }
};