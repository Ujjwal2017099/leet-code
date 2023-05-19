class Solution {
public:
    int minStartValue(vector<int>& n) {
        for(int i=1;i<n.size();i++){
            n[i] +=n[i-1];
        }
        int mn=1;
        for(int i=0;i<n.size();i++){
            mn=min(mn,n[i]);
        }
        if(mn<=0){
            return abs(mn)+1;
        }
        
        return 1;
    }
};