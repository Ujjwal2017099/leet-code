class BSTIterator {
public:
    vector<int> v;
    void function(TreeNode* r)
    {
        if(!r) return;
        
        function(r->left);
        v.push_back(r->val);
        function(r->right);
    }
    BSTIterator(TreeNode* root) {
        
        function(root);
        reverse(v.begin(),v.end());
    }
    
    int next() {
        int t = v.back();
        v.pop_back();
        
        return t;
    }
    
    bool hasNext() {
        if(v.size())
        return true;
        
        return false;
    }
};