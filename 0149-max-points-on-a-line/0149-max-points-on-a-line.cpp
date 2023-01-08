class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int n = p.size();
        vector<vector<double>> arr(n,vector<double>(n,-1));
        // vector<int> cnt(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            map<double,int> cnt;
            for(int j=0;j<n;j++){
                if(i!=j){
                    double x = (p[j][1] - p[i][1]);
                    double y = (p[j][0] - p[i][0]);
                    if(y==0.0) arr[i][j] = INT_MAX;
                    else arr[i][j] = y/x;
                    // cnt[arr[i][j]]++;
                    ans = max(ans,++cnt[arr[i][j]]);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return ans+1;
    }
};