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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        map<TreeNode*,bool> mp;
        stack<TreeNode*> st;
        if(root==nullptr){
            return ans;
        }
        st.push(root);
        while(!st.empty()){
            while(st.top()->left){
                st.push(st.top()->left);
            }
            TreeNode* prev = nullptr;
            if(st.top()->right){
                st.push(st.top()->right);
            }
            else{
                while(!st.empty()){
                    if(st.top()->right && st.top()->right != prev){
                        st.push(st.top()->right);
                        break;
                    }
                    ans.push_back(st.top()->val);
                    prev = st.top();st.pop();
                }
            }
        }
        return ans;
    }
};