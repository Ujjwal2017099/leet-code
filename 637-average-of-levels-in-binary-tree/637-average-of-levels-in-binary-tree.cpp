
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> t;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        double sum=0.0;
        int cnt=0;
        while(!q.empty()){
            TreeNode* node = q.front();q.pop();
            if(node==nullptr){
                t.push_back(sum/cnt);
                sum=0.0;cnt=0;
                if(!q.empty())q.push(nullptr);
            }
            else{
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                sum += node->val;cnt++;
            }
            
        }
        return t;
    }
};