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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fun(nums,0,nums.size()-1);
    }
    TreeNode* fun(vector<int>& n,int l,int r){
        TreeNode* node = nullptr;
        if(l>r) return node;
        int mid = (l+r)/2;
        
        node = new TreeNode(n[mid]);
        node->left = fun(n,l,mid-1);
        node->right = fun(n,mid+1,r);
        
        return node;
    }
};