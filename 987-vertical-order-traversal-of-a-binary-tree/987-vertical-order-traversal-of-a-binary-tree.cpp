
class Solution {
public:
    map<pair<int,int>,vector<int>> d;
    map<int,vector<int>> m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        fun(root,0,0);
        for(auto it:d){
            int x = it.first.first;
            sort(it.second.begin(),it.second.end());
            m[x].insert(m[x].end(),it.second.begin(),it.second.end());
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
    void fun(TreeNode* node,int dis,int h){
        if(node==nullptr){
            return ;
        }
        d[{dis,h}].push_back(node->val);
        fun(node->left,dis-1,h+1);
        fun(node->right,dis+1,h+1);
    }
};