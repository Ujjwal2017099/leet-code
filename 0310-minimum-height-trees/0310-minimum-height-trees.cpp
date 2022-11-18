class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        vector<set<int>> g(n);
        set<int> s;
        
        for(vector<int> t:e){
            int u=t[0],v=t[1];
            g[u].insert(v);
            g[v].insert(u);
        }
        
        vector<int> leaves;
        for(int i=0;i<n;i++){
            if(g[i].size()==1){
                leaves.push_back(i);
            }
            s.insert(i);
        }
        int r = n;
        while(!leaves.empty() and r>2){
            r-=leaves.size();
            vector<int> nleaves;
            for(int i:leaves){
                s.erase(i);
                g[*g[i].begin()].erase(i);
                if(g[*g[i].begin()].size()==1) nleaves.push_back(*g[i].begin());
            }
            leaves = nleaves;
        }
        vector<int> ans;
        for(int i:s) ans.push_back(i);
        return ans;
    }
};