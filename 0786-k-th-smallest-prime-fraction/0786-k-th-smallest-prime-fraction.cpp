class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<vector<int>> v;
        
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                v.push_back({arr[i],arr[j]});
            }
        }
        
        sort(v.begin(),v.end(),[&](vector<int>& a,vector<int>& b){
            int x=b[1],y=a[1];
            
            // b[0]*=y;b[1]*=y;
            // a[0]*=x;a[1]*=x;
            
            return a[0]*x<b[0]*y;
        });
        
        return v[k-1];
    }
};