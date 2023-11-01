class Solution {
public:
    int mx=0;
    unordered_map<int,int> cnt;
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        fun(root);
        for(auto it:cnt){
            if(it.second==mx)ans.push_back(it.first);
        }
        return ans;
    }
    void fun(TreeNode* node){
        if(!node) return;
        
        mx=max(mx,++cnt[node->val]);
        
        fun(node->left);
        fun(node->right);
    }
};