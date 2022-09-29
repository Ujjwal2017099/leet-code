class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> t;
        vector<int> ans;
        for(int i:arr){
            t.push_back({abs(x-i),i});
        }
        sort(t.begin(),t.end(),[&](pair<int,int> a,pair<int,int> b){
           if(a.first==b.first){
               return a.second<b.second;
           } 
            return a.first<b.first;
        });
        
        for(int i=0;i<k;i++){
            ans.push_back(t[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};