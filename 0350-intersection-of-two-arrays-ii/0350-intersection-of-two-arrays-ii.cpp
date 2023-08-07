class Solution {
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) {
        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i:n2) m[i]++;
        for(int i:n1){
            auto it=lower_bound(n2.begin(),n2.end(),i);
            if(it==n2.end() || !m[*it] || *it!=i) continue;
            m[i]--;
            ans.push_back(i);
        }
        return ans;
    }
};