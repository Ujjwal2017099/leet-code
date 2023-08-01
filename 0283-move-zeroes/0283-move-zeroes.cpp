class Solution {
public:
    void moveZeroes(vector<int>& n) {
        int cnt=0;
        int in=0;
        for(int i=0;i<n.size();i++){
            if(n[i]!=0) n[in++]=n[i];
            else cnt++;
        }
        while(cnt--){
            n[in++]=0;
        }
        
    }
};