/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return fun(root);
    }
    int fun(TreeNode* node){
        
        int amn=node->val;
        int bmn=node->val;
        int amx=node->val;
        int bmx=node->val;
        
        if(node->left) amn = mn(node->left,INT_MAX);
        if(node->left) amx = mx(node->left,INT_MIN);
        if(node->right) bmn = mn(node->right,INT_MAX);
        if(node->right) bmx = mx(node->right,INT_MIN);
        if(!node->left && !node->right){
            return max(max(abs(node->val-amn),abs(node->val-amx)),max(abs(node->val-bmn),abs(node->val-bmx)));
        }
        int x=0,y=0;
        if(node->left) x = fun(node->left);
        if(node->right) y = fun(node->right);
        
        int a = max(abs(node->val-amn),abs(node->val-amx));
        int b = max(abs(node->val-bmn),abs(node->val-bmx));
        
        return max(max(a,b),max(x,y));
    }
    int mn(TreeNode* node,int val){
        if(!node) return -1;
        if(!node->left && !node->right){
            return min(node->val,val);
        }
        if(node->val < val) val = node->val;
        int a = INT_MAX , b = INT_MAX;
        if(node->left) a = mn(node->left,val);
        if(node->right) b = mn(node->right,val);
        
        return min(a,b);
    }
    int mx(TreeNode* node,int val){
        if(!node) return -1;
        if(!node->left && !node->right){
            return max(node->val,val);
        }
        if(node->val > val) val = node->val;
        int a = INT_MIN , b = INT_MIN;
        if(node->left) a = mx(node->left,val);
        if(node->right) b = mx(node->right,val);
        
        return max(a,b);
    }
};