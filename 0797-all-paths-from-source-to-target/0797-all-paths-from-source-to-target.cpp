class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> t;
        fun(graph,t,0);
        return ans;
    }
    void fun(vector<vector<int>>& g,vector<int>& t,int x){
        t.push_back(x);
        if(x==g.size()-1){
            ans.push_back(t);
            t.pop_back();
            return;
        }
        for(int i:g[x]){
            fun(g,t,i);
        }
        t.pop_back();
    }
};