class Solution {
public:
    int f=0;
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        
        return height(root->left) +1;
    }
    int countNodes(TreeNode* root) {
        int h = height(root);
        int n = (1<<h) - 1;
        int miss = fun(root,0,h);
        return n-miss;
    }
    int fun(TreeNode* root,int curr,int h){
        if(root==nullptr){
            if(curr==h) return 0;
            f++;
            return 1;
        }
        
        int r = fun(root->right,curr+1,h);
        int l = 0;
        if(r || f==2){
            l = fun(root->left,curr+1,h);
            if(l) f=0;
        }
        return r+l;
    }
};