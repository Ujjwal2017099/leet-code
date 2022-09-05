
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>> ans;
        vector<int> t;
        queue<TreeNode*> q;q.push(root);q.push(nullptr);
        while(!q.empty()){
            TreeNode* x = q.front();q.pop();
            if(x==nullptr){
                ans.push_back(t);
                t.clear();
                if(!q.empty()){
                    q.push(nullptr);
                }
                continue;
            }
            t.push_back(x->val);
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        return ans;
    }
};