
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> v;
        int i=0;
        while(!q.empty()){
            TreeNode* x = q.front();
            q.pop();
            if(x==nullptr){
                if(!q.empty()) q.push(nullptr);
                if(i&1){
                    reverse(v.begin(),v.end());
                }
                ans.push_back(v);
                i++;
                v.clear();
                continue;
            }
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
            v.push_back(x->val);
        }
        return ans;
    }
};