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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()){
            TreeNode* x = q.front();
            q.pop();
            if(q.front()==nullptr){
                ans.push_back(x->val);
            }
            if(x!=nullptr){
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }else if(!q.empty()){
                q.push(nullptr);
            }
        }
        
        return ans;
    }
};