class Solution {
public:
    bool ans;
    vector<int> col;
    bool isBipartite(vector<vector<int>>& graph) {
        col.resize(graph.size(),-1);
        ans=1;
        for(int i=0;i<graph.size();i++){
            if(col[i] == -1){
                fun(graph,i,0);
            }
        }
        return ans;
    }
    void fun(vector<vector<int>>& g,int x,int curr){
        if(col[x]!=-1 and col[x] != curr){
            ans = 0;
            return;
        }else if(col[x] != -1) return;
        col[x] = curr;
        for(int i:g[x]){
            // if(col[i]==-1){
                fun(g,i,curr xor 1);
            // }
        }
    }
};