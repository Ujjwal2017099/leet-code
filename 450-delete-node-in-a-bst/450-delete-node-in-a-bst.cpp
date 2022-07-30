
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        
        if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            if(root->left==nullptr) return root->right;
            if(root->right==nullptr) return root->left;
            
            root->val = minVal(root->right);
            
            root->right = deleteNode(root->right,root->val);
        }
        
        return root;
    }
    int minVal(TreeNode* root){
        if(root->left==nullptr){
            return root->val;
        }
        
        return minVal(root->left);
    }
};