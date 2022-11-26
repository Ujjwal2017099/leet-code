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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root==nullptr) return ans;
        st.push(root);
        while(!st.empty()){
            while(st.top()->left!=nullptr){
                TreeNode* x = st.top();
                st.push(x->left);
            }
            ans.push_back(st.top()->val);
            TreeNode* x = st.top();st.pop();
            if(x->right!=nullptr) st.push(x->right);
            else {
                while(!st.empty()){
                    ans.push_back(st.top()->val);
                    TreeNode* x = st.top();
                    st.pop();
                    if(x->right){
                        st.push(x->right);
                        break;
                    }
                }
            }
            // st.pop();
        }
        return ans;
    }
};