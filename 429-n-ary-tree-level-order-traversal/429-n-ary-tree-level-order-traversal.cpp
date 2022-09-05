
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        vector<int> t;
        while(!q.empty()){
            Node* x = q.front();q.pop();
            if(x==nullptr){
                ans.push_back(t);t.clear();
                if(!q.empty()) q.push(nullptr);
                continue;
            }
            t.push_back(x->val);
            for(Node* node:x->children){
                if(node) q.push(node);
            }
        }
        return ans;
    }
};