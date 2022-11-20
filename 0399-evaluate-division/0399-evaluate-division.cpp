class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string,vector<int>> g;
        for(int i=0;i<e.size();i++){
            g[e[i][0]].push_back(i);
            g[e[i][1]].push_back(-1*(i+1));
        }
        vector<double> ans;
        for(vector<string> t:q){
            string u = t[0];
            string d = t[1];
            set<string> vis;
            if(g.find(u)==g.end() || g[u].empty()) {ans.push_back(-1);continue;}
            if(u==d) {ans.push_back(1.0);continue;}
            double x = fun(g,v,e,vis,u,d);   
            ans.push_back(x);
            // vis.clear();
        }
        return ans;
    }
    double fun(map<string,vector<int>>& g,vector<double>& v,vector<vector<string>>& e,set<string>& vis,string& u,string& d){
        if(u==d) return 1.0;
        if(g.find(u)==g.end() || g[u].empty()) return 0.0;
        
        double x=-1.0;
        vis.insert(u);
        // cout<<u<<" ";
        for(int i:g[u]){
            // cout<<i<<" ";
            int c = i>=0 ? i : -1*i - 1;
            if(i>=0 && vis.find(e[c][1])!=vis.end()) continue;
            if(i<0 && vis.find(e[c][0])!=vis.end()) continue;
            if(i>=0) x = fun(g,v,e,vis,e[c][1],d)*v[c];
            if(i<0) x = fun(g,v,e,vis,e[c][0],d)*(1/v[c]);
            if(x>0.0) return x;
            // cout<<x<<" ";
        }
        // vis.erase(u);
        return -1.0;
    }
};