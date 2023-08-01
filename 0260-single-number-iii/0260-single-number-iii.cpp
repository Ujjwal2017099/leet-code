class Solution {
public:
    vector<int> singleNumber(vector<int>& n) {
        int p=0;
        for(int i=0;i<n.size();i++) p^=n[i];
        
        int cnt=1;
        while(1){
            if((cnt&p)==0) cnt=cnt<<1;
            else break;
        }
        // cout<<(-1>>2);
        int a=0,b=0;
        for(int i=0;i<n.size();i++){
            if(n[i]&(cnt)){
                a^=n[i];
            }else{
                b^=n[i];
            }
        }
        return {a,b};
    }
};