
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        vector<int> a;
        queue<TreeNode*> q;q.push(root);
        bool f=0;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                TreeNode* x = q.front();q.pop();
                if(!x) {f=1;a.push_back(-1);continue;}
                if(f) return 0;
                a.push_back(x->val);
                q.push(x->left);
                q.push(x->right);
            }
        }
        // for(int i:a){
        //     if(i!=-1 && f) return 0;
        //     if(i==-1) f=1;
        // }
        return 1;
    }
    
};