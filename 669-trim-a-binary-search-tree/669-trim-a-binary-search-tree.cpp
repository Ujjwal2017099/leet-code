/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
                // prev = ptr;
            }
            else 
            {
                prev = ptr;
                ptr = ptr->left;
            }
        }
        // if(!ptr) ptr->left = NULL;
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
        // if(!ptr) ptr->right = NULL;
        return root;
    }
};