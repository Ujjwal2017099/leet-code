class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        vector<vector<int>> g1(n);
        vector<vector<int>> g2(n);
        for(vector<int>& it:c){
            g1[it[0]].push_back(it[1]);
            g2[it[1]].push_back(it[0]);
        }
        queue<vector<int>> q;q.push({0,0});
        int ans=0;
        vector<bool> mp(n,0);
        while(!q.empty()){
            vector<int> x=q.front();q.pop();
            ans+=x[1];
            mp[x[0]]=1;
            int j=0;
            while(j<g1[x[0]].size()){ if(!mp[g1[x[0]][j]]){ q.push({g1[x[0]][j],1});}j++;}
            j=0;
            while(j<g2[x[0]].size()){ if(!mp[g2[x[0]][j]]){ q.push({g2[x[0]][j],0});}j++;}
        }
        return ans;
    }
};