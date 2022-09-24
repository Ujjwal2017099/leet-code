
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        fun(root,target,0,{});
        return ans;
    }
    void fun(TreeNode* node,int target,int sum,vector<int> v){
        if(node==nullptr ) return;
        sum += node->val;
        v.push_back(node->val);
        if(node->left ) fun(node->left,target,sum,v);
        if(node->right ) fun(node->right,target,sum,v);
        
        if(sum == target and !node->left and !node->right){
            ans.push_back(v);
        }
    }
};