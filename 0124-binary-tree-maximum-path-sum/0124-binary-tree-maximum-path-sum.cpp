class Solution {
public:
    long long ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        ans = root->val;
        fun(root);
        return ans;
    }
    int fun(TreeNode* node){
        if(!node->left && !node->right){
            ans = max(ans,(long long)node->val);
            return node->val;
        }
        long long a = INT_MIN,b=INT_MIN;
        if(node->left) a = fun(node->left);
        if(node->right) b = fun(node->right);
        
        ans = max(ans,a);
        ans = max(ans,b);
        ans = max((long long)node->val,ans);
        long long t = 0;
        if(a!=INT_MIN) t += a;
        if(b!=INT_MIN) t += b;
        ans = max(ans,t+node->val);
        if(a<0 && b<0){
            if(node->val > 0){
                ans = max(ans,(long long)node->val);
                return node->val;
            }
            long long t = max(a,max((long long)node->val,b));
            ans = max(ans,t);
            return t;
        }
        // if(node->val>0){
            a+=node->val;
            b+=node->val;
        // }
        long long f = max(a,b);
        ans = max(ans,f);
        
        return f;
    }
};