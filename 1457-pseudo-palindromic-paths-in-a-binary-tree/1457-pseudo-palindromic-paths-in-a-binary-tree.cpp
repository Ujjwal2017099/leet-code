class Solution {
public:
    int cnt = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10,0);
        fun(root,v,0);
        return cnt;
    }
    void fun(TreeNode* node,vector<int>& v,int c){
        if(node == nullptr) return;
        v[node->val]++;
        c++;
        if(node ->left == nullptr and node->right == nullptr){
            if(c&1){
                int f = 1;
                for(int i=1;i<=9;i++){
                    if(v[i]&1 and f==0){
                        {v[node->val]--;return;}
                    }else if(v[i]&1) f--;
                }
            }else{
                for(int i=1;i<=9;i++){
                    if(v[i]&1) {
                        v[node->val]--;
                        return;
                    }
                }
            }
            cnt++;
        }
        
        
        fun(node->left,v,c);
        fun(node->right,v,c);
        v[node->val]--;
    }
};