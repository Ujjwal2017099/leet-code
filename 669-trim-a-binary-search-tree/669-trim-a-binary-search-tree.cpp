class Solution {
public:
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        while (root != NULL and !(root->val >= low and root->val <= high))
        {
            if(root->val > high) root = root->left;
            else if(root->val < low) root = root->right;
        }
        TreeNode* ptr = root;
        TreeNode* prev = ptr;
        
        while(ptr!=NULL)
        {
            if(ptr->val < low)
            {
                prev->left = ptr->right;
                ptr = ptr->right;
            }
            else 
            {
                prev = ptr;
                ptr = ptr->left;
            }
        }
        ptr = root;
        prev = ptr;
        
        while(ptr != NULL)
        {
            if(ptr->val > high)
            {
                prev->right = ptr->left;
                ptr = ptr->left;
            }
            else
            {
                prev = ptr;
                ptr = ptr->right;
            }
        }
        return root;
    }
};
