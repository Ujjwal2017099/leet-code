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
    int ans;
    int sumNumbers(TreeNode* root) {
        ans = 0;
        fun(root,0);
        return ans;
    }
    void fun(TreeNode* root,int sum){
        if(root==nullptr) return;
        if(root->left == nullptr and root->right == nullptr){
            ans += sum*10+root->val;
            cout<<sum<<" ";
            sum =0 ;
            return;
        }
        
        fun(root->left,sum*10+root->val);
        fun(root->right,sum*10+root->val);
    }
};