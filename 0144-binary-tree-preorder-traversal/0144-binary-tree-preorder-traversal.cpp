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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root==nullptr) return ans;
        st.push(root);
        while(!st.empty()){
            ans.push_back(st.top()->val);
            TreeNode* y = st.top();
            while(y->left!=nullptr){
                ans.push_back(y->left->val);
                st.push(y->left);
                y=y->left;
            }
            if(y->right){
                // ans.push_back(y->right->val);
                st.pop();
                st.push(y->right);
            }else{
                while(!st.empty()){
                    TreeNode* x = st.top();
                    st.pop();
                    if(x->right){
                        // ans.push_back(x->right->val);
                        st.push(x->right);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};