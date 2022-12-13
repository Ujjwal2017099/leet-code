class Solution {
public:
    map<vector<int>,int> mp;
    int minFallingPathSum(vector<vector<int>>& m) {
        int ans = INT_MAX;
        for(int i=0;i<m[0].size();i++){
            ans = min(ans,fun(m,0,i));
        }
        return ans;
    }
    int fun(vector<vector<int>>& m,int i,int j){
        if(i==m.size()-1){
            return m[i][j];
        }
        if(mp.find({i,j})!=mp.end()) return mp[{i,j}];
        int a = m[i].size();
        int x=INT_MAX,y=INT_MAX,z=fun(m,i+1,j)+m[i][j];
        if(j-1>=0) x = fun(m,i+1,j-1) + m[i][j];
        if(j+1<a) y = fun(m,i+1,j+1) + m[i][j];
        
        return mp[{i,j}] = min(min(x,y),z);
    }
};