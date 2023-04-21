class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long unsigned>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            long long unsigned mn=ULLONG_MAX,mx=0;
            while(sz--){
                TreeNode* x=q.front().first;
                long long unsigned a=q.front().second;
                mx=max(a,mx);
                mn=min(a,mn);
                q.pop();
                if(x->left) q.push({x->left,a*2+1});
                if(x->right) q.push({x->right,a*2+2});
            }
            int t=mx-mn;
            ans = max(ans,t);
        }
        return ans+1;
    }
};