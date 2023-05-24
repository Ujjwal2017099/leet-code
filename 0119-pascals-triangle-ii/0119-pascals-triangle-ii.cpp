class Solution {
public:
    vector<int> getRow(int r) {
        if(r==0) {return {1};}
        
        vector<int> t(2,1);
        for(int j=2;j<=r;j++){
            vector<int> x;
            x.push_back(1);
            for(int i=1;i<j;i++){
                x.push_back(t[i-1]+t[i]);
            }
            x.push_back(1);
            for(int i=0;i<x.size();i++){
                if(i>=t.size()){
                    t.push_back(x[i]);
                }else{
                    t[i]=x[i];
                }
            }
        }
        return t;
    }
};