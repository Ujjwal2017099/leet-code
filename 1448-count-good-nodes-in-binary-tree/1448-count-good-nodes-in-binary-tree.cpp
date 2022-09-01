class Solution {
public:
    int cnt = 0;
    int goodNodes(TreeNode* root) {
        fun(root,INT_MIN);
        return cnt;
    }
    void fun(TreeNode* root,int val){
        if(root==nullptr){
            return;
        }
        if(root->val >= val) {
            val = root->val;
            cnt++;
        }
        
        fun(root->left,val);
        fun(root->right,val);
    }
};