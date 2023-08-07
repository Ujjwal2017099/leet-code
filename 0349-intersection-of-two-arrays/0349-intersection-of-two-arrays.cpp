class Solution {
public:
    vector<int> intersection(vector<int>& n1, vector<int>& n2) {
        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
        set<int> s;
        for(int i=0;i<n1.size();i++){
            auto it=lower_bound(n2.begin(),n2.end(),n1[i]);
            if(it==n2.end() || *it!=n1[i]) continue;
            s.insert(n1[i]);
        }
        vector<int> ans(s.begin(),s.end());
        return ans;
    }
};