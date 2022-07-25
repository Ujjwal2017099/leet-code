
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ans; 
        vector<int> t;
        queue<TreeNode*> q;
        if(root==nullptr){
            return ans;
        }
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()){
            TreeNode* x = q.front();
            q.pop();
            if(x != nullptr){
                if(x->left!=nullptr) q.push(x->left);
                if(x->right!=nullptr) q.push(x->right);
                t.push_back(x->val);
                // cout<<x->val<<" ";
            }else if(!q.empty()){
                ans.push_back(t);
                t.clear();
                q.push(nullptr);
            }
            
        }
        if(!t.empty()) ans.push_back(t);
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};