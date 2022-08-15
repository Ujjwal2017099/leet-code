class Solution {
public:
    vector<int> set;
    vector<int> weight;
    int minCostConnectPoints(vector<vector<int>>& p) {
        vector<vector<int>> g;
        for(int i=0;i<p.size();i++){
            for(int j=i+1;j<p.size();j++){
                int w = abs(p[i][0]-p[j][0]) + abs(p[i][1]-p[j][1]);
                g.push_back({w,i,j});
            }
        }
        
        sort(g.begin(),g.end());
        set.resize(p.size());
        weight.resize(p.size());
        for(int i=0;i<p.size();i++) {
            set[i] = i;
            weight[i] = 0;
        }
        
        int cost=0;
        
        for(auto i:g){
            int u=i[1];
            int v=i[2];
            
            int x=find(u);
            int y=find(v);
            
            if(x==y) continue;
            Union(x,y);
            cost+=i[0];
        }
        
        return cost;
    }
    int find(int x){
        if(set[x] == x) return x;
        
        return set[x] = find(set[x]);
    }
    void Union(int a,int b){
        int x = find(a);
        int y = find(b);
        
        if(x==y) return;
        if(weight[x] >= weight[y]) {
            set[y] = x;
            weight[x]+=weight[y];
        }
        else {
            set[x] = y;
            weight[y]+=weight[x];
        }
    }
};