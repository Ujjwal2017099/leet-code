class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& n, int t) {
        sort(n.begin(),n.end());
        map<long long,int> m;
        for(int i=0;i<n.size();i++) m[n[i]]=i+1;
        vector<vector<int>> x;
        if(n.size()<4) return x;
        for(int i=0;i<n.size()-2;i++){
            for(int j=i+1;j<n.size()-1;j++){
                for(int k=j+1;k<n.size();k++){
                    long long y = t*1LL - (n[i]*1LL+n[j]*1LL+n[k]*1LL);
                    int a = m[y];
                    // cout<<a<<" ";
                    if(a>k+1){
                        x.push_back({n[i],n[j],n[k],n[a-1]});
                    }
                    while(k<n.size()-1 && n[k+1]==n[k]) k++;
                }
                while(j<n.size()-1 && n[j+1]==n[j]) j++;
            }
            while(i<n.size()-1 && n[i+1]==n[i]) i++;
        }
        return x;
    }
};