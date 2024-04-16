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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* ptr = new TreeNode(val);
            ptr->left = root;
            
            return ptr;
        }
        fun(root,val,depth,1);
        
        return root;
    }
    void fun(TreeNode* node,int val,int target,int current){
        if(node==nullptr){
            return;
        }
        
        if(current+1==target){
            TreeNode* ptr1 = new TreeNode(val);
            TreeNode* ptr2 = new TreeNode(val);
            
            ptr1->left = node->left;
            ptr2->right = node->right;
            
            node->left = ptr1;
            node->right = ptr2;
            
            return;
        }
        
        fun(node->left,val,target,current+1);
        fun(node->right,val,target,current+1);
    }
};