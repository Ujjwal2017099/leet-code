class Solution {
public:
    int mod = 1e9 + 7;
    map<TreeNode*,int> sum;
    long long prd = 0;
    int maxProduct(TreeNode* root) {
        fun(root);
        find(root,0);
        return prd%mod;
    }
    int fun(TreeNode* node){
        if(!node->left && !node->right){
            sum[node] = node->val;
            return node->val;
        }
        
        int a = -1,b = -1;
        if(node->left) a = fun(node->left);
        if(node->right) b = fun(node->right);
        
        int t = node->val;
        if(a!=-1) t+=a;
        if(b!=-1) t+=b;
        sum[node] = t;
        return t;
    }
    void find(TreeNode* node,long long par){
        if(!node->left && !node->right){
            return;
        }
        long long one = 0;
        long long two = 0;
        long long t = 0;
        if(node->left){
            one = sum[node->left];
            t = sum[node]-one;
            t += par;
            if(prd < one*t){
                prd = one*t;
            }
            find(node->left,sum[node]-sum[node->left]+par);
        }
        if(node->right){
            two = sum[node->right];
            t = sum[node]-two;
            t+=par;
            if(prd < two*t){
                prd = two*t;
            }
            find(node->right,sum[node]-sum[node->right]+par);
        }
    }
};