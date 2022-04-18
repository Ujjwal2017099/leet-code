int ans;
class Solution {
public:
    
    void find(TreeNode* r,int& k)
    {
        if(r == NULL ) return ;
        
        find(r->left,k);
        k--;
        
        if(k == 0) {::ans = r->val;}
        find(r->right,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        find(root,k);
        return ans;
    }
};