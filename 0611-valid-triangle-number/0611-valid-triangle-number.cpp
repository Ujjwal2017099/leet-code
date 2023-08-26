class Solution {
public:
    int triangleNumber(vector<int>& n) {
        sort(n.begin(),n.end());
        int ans=0;
        for(int i=0;i<n.size();i++){
            for(int j=i+1;j<n.size();j++){
                int x=index(n,n[i]+n[j],j);
                ans += x-j;
            }
        }
        return ans;
    }
    int index(vector<int>& v,int s,int x){
        int l=x+1,r=v.size()-1;
        while(l<=r){
            int md = (l+r)/2;
            if(v[md]==s){
                r=md-1;
            }
            else if(v[md]<s){
                l=md+1;
            }else if(v[md]>s){
                r=md-1;
            }
        }
        return r;
    }
};