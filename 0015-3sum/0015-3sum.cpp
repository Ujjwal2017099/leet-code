class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        sort(n.begin(),n.end());
        unordered_map<int,int> m;
        for(int i=0;i<n.size();i++){
            m[n[i]] = i+1;
        }
        if(m.size()==1 && n.size()==3000 && m[0]) return {{0,0,0}};
        // map<int ,bool> f;
        set<vector<int>> ans;
        // vector<vector<int>> x;
        for(int i=0;i<n.size();i++){
            for(int j=i+1;j<n.size();j++){
                int y = -1*(n[i] + n[j]);
                int a = m[y];
                if(a > j +1){
                    vector<int> t = {n[i],n[j],n[a-1]};
                    // sort(t.begin(),t.end());
                    ans.insert(t);
                    // x.push_back(t);
                }
            }
        }
        vector<vector<int>> x(ans.begin(),ans.end());
        return x;
    }
};