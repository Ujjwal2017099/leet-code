class Solution {
public:
    vector<int> getRow(int r) {
        if(r==0) {return {1};}
        
        vector<int> t(r+1,1);
        for(int j=2;j<=r;j++){
            int prev=1;
            for(int i=1;i<j;i++){
                int x=t[i];
                t[i]+=(prev);
                prev=x;
            }
            // for(int i=0;i<x.size();i++){
            //     if(i>=t.size()){
            //         t.push_back(x[i]);
            //     }else{
            //         t[i]=x[i];
            //     }
            // }
        }
        return t;
    }
};