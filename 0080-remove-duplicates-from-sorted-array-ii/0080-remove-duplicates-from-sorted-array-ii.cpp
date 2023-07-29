class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        int sz=0;
        int cnt=1;
        int ptr=0;
        for(int i=1;i<n.size();i++){
            if(cnt==2){
                if(n[i]!=n[ptr]){
                    sz++;
                    n[sz]=n[i];
                    ptr=i;
                    cnt=1;
                }
                continue;
            }
            sz++;
            if(n[i]==n[ptr]){
                n[sz]=n[i];
                cnt++;
            }else{
                n[sz]=n[i];
                cnt==1;
            }
            ptr++;
        }
        return sz+1;
    }
};