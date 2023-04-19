class Solution {
public:
    int ans=0;
    int longestZigZag(TreeNode* root) {
        fun(root,0,0);
        fun(root,1,0);
        
        return ans;
    }
    void fun(TreeNode* node,bool d,int s){
        if(!node) return;
        
        ans = max(ans,s);
        if(d){
            fun(node->left,0,s+1);
            fun(node->left,1,0);
        }else{
            fun(node->right,1,s+1);
            fun(node->right,0,0);
        }
    }
};