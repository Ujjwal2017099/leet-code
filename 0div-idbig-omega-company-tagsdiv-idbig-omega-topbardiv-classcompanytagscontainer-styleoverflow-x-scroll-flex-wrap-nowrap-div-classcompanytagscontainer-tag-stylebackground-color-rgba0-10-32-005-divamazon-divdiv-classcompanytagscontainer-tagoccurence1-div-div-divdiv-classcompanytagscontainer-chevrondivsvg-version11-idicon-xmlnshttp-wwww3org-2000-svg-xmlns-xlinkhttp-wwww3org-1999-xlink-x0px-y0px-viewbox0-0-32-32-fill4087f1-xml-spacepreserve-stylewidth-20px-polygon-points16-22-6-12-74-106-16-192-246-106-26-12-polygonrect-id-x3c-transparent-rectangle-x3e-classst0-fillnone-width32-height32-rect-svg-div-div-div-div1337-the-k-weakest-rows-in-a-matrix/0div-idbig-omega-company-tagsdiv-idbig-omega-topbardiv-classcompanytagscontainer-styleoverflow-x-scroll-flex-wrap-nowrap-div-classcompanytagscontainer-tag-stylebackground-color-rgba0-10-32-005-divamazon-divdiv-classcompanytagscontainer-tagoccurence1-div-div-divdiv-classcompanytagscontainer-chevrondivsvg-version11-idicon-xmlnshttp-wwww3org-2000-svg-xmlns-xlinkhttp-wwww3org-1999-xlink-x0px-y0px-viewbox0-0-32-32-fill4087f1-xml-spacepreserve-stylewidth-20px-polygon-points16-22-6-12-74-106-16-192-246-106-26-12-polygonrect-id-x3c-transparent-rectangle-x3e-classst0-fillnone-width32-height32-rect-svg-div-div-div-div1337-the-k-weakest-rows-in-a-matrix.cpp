class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& m, int k) {
        vector<vector<int>> v(m.size(),vector<int>(2,0));
        for(int i=0;i<m.size();i++){
            v[i][1]=i;
            for(int j=0;j<m[0].size();j++){
                v[i][0]+=m[i][j];
            }
        }
        sort(v.begin(),v.end(),[&](vector<int> a,vector<int> b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i][1]);
        }
        return ans;
    }
};