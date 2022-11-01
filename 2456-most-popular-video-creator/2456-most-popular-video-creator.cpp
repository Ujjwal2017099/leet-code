class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& id, vector<int>& v) {
        unordered_map<string,int> p;
        unordered_map<string,pair<string,int>> mv;
        unordered_map<string,bool> vis;
        int mx=0;
        for(int i=0;i<v.size();i++){
            p[c[i]] += v[i];
            mx = max(mx,p[c[i]]);
            if(vis[c[i]] and mv[c[i]].second == v[i]){
                mv[c[i]].first = mv[c[i]].first < id[i]?mv[c[i]].first:id[i];
            }else if(vis[c[i]] and mv[c[i]].second < v[i]){
                mv[c[i]].first = id[i];
                mv[c[i]].second = v[i];
            }
            
            if(!vis[c[i]]){
                mv[c[i]].first = id[i];
                mv[c[i]].second = v[i];
            }
            vis[c[i]] = 1;
        }
        vector<vector<string>> ans;
        for(auto it:p){
            if(it.second==mx){
                ans.push_back({it.first,mv[it.first].first});
            }
        }
        return ans;
    }
};