class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[&](vector<int>& a,vector<int>& b){
            // if(a[1]==b[1]) return a[1]<b[1];
           return a[1]<b[1]; 
        });
        // for(auto it:p){
        //     for(int i:it) cout<<i<<" ";
        //     cout<<endl;
        // }
        int cnt=1;
        int prev = p[0][1];
        for(int i=1;i<p.size();i++){
            if(p[i][0]>prev){
                cnt++;
                prev = p[i][1];
            }
            // else prev = max(prev,p[i][1]);
        }
        return cnt;
    }
};