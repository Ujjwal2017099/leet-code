class Solution {
public:
    int maximumPrimeDifference(vector<int>& n) {
        vector<int> sv(101,0);
        
        for(int i=2;i<=100;i++){
            
            for(int j=i+i;j<=100;j+=i){
                sv[j]=1;
            }
        }
        // for(int i=0;i<=10;i++) cout<<sv[i]<<" ";
        int l=0,r=0;
        bool ok=0;
        for(int i=0;i<n.size();i++){
            if(!sv[n[i]] && n[i]!=1){
                if(ok){
                    r=i;
                }else{
                    l=i;
                    r=i;
                    ok=1;
                }
            }
        }
        // cout<<r<<" "<<l;
        return r-l;
    }
};