class Solution {
public:
    int minimumAddedInteger(vector<int>& n1, vector<int>& n2) {
        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
        
        int ans=INT_MAX;
        
        for(int i=0;i<n1.size();i++){
            for(int j=i+1;j<n1.size();j++){
                int x=fun(n1,n2,i,j);
                ans=min(ans,x);
                
                // if(ans!=INT_MAX) cout<<ans<<" "<<i<<" "<<j<<endl;
            }
        }
        return ans;
    }
    int fun(vector<int>& n1,vector<int>& n2,int i,int j){
        int y=0;
        int prev=INT_MIN;
        for(int x=0;x<n1.size();x++){
            if(x==i || x==j) continue;
            if(prev == INT_MIN){
                prev=-1*(n1[x]-n2[y]);
            }
            else if(prev != -1*(n1[x]-n2[y])){
                return INT_MAX;
            }
            y++;
        }
        return prev;
    }
};