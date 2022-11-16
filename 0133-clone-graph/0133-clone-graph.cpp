class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        if(node->neighbors.empty()) return new Node(node->val);
        map<int,vector<int>> mp;
        map<Node*,bool> vis;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* x=q.front(); q.pop();
            vis[x]=1;
            for(Node* n:x->neighbors){
                mp[x->val].push_back(n->val);
                if(!vis[n]){
                    q.push(n);
                    vis[n]=1;
                }
            }
        }
        map<int,Node*> ptr;
        
        for(auto it:mp){
            Node* p = new Node(it.first);
            ptr[it.first] = p;
        }
        for(auto it:mp){
            for(int x:it.second){
                ptr[it.first]->neighbors.push_back(ptr[x]);
            }
        }
        
        return ptr[node->val];
    }
};