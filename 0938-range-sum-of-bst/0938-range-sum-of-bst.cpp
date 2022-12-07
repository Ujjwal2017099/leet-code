
class Solution {
public:
    int sum=0; 
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr){
            return sum;
        }
        if(root->val>high){
            return rangeSumBST(root->left,low,high);
        }
        if(root->val<low){
            return rangeSumBST(root->right,low,high);
        }
        
        return rangeSumBST(root->right,low,high) + rangeSumBST(root->left,low,high) + root->val;
    }
};