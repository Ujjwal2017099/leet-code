class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),[&](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        vector<vector<int>> ans;
        for(int i=0;i<v.size();i++){
            vector<int> x;
            x.push_back(v[i][0]);
            int b=v[i][1];
            while(i<v.size()-1 && v[i+1][0]<=b) {b=max(b,v[i+1][1]);i++;}
            x.push_back(b);
            ans.push_back(x);
        }
        return ans;
    }
};