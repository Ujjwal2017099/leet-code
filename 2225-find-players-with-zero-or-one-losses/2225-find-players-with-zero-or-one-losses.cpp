class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        int arr[100001];
        memset(arr,-1,sizeof(arr));
        int cnt=0;
        for(auto it:m){
            if(arr[it[0]]==-1) {arr[it[0]] = 0;cnt++;}
            if(arr[it[1]]==-1) arr[it[1]] = 0;
            if(arr[it[1]]<2) {arr[it[1]]++;cnt++;}
            
        }
        vector<vector<int>> ans(2);
        for(int i=0;i<=100000;i++){
            if(arr[i]==-1) continue;
            if(cnt==0) break;
            if(arr[i]==0) ans[0].push_back(i);
            if(arr[i]==1) ans[1].push_back(i);
            cnt--;
        }
        return ans;
    }
};