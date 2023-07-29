class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        sort(n.begin(),n.end());
        vector<int> s;
        int ans=0;
        int cnt=0;
        for(int i=0;i<n.size();i++){
            if(s.empty()) {s.push_back(n[i]);cnt=1;}
            else if(s.back()==n[i]) continue;
            else if(s.back()+1==n[i]){
                cnt++;
            }
            else cnt=1;
            s.push_back(n[i]);
            ans=max(ans,cnt);
        }
        return ans;
    }
};