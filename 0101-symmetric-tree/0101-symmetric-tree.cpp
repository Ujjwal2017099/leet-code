class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root->left==nullptr || root->right==nullptr){
            if(!root->left && !root->right) return 1;
            return 0;
        }
        
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        
        queue<TreeNode*> x,y;x.push(l);y.push(r);
        while(x.size() && y.size()){
            vector<int> a,b;
            int sz=x.size(),s=y.size();
            while(sz--){
                TreeNode* p = x.front();x.pop();
                if(p==nullptr){
                    a.push_back(-1);
                    // x.push(nullptr);x.push(nullptr);
                    continue;
                }
                a.push_back(p->val);
                x.push(p->left);
                x.push(p->right);
            }
            
            while(s--){
                TreeNode* p = y.front();y.pop();
                if(p==nullptr){
                    b.push_back(-1);
                    // x.push(nullptr);x.push(nullptr);
                    continue;
                }
                b.push_back(p->val);
                y.push(p->right);
                y.push(p->left);
            }
            
            if(a.size()!=b.size()) return 0;
            for(int i=0;i<a.size();i++) if(a[i]!=b[i]) return 0;
        }
        
        if(x.size() || y.size()) return 0;
        
        return 1;
    }
    
};