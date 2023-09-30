class Solution {
public:
    bool isMonotonic(vector<int>& n) {
        bool x=1,y=1;
        for(int i=1;i<n.size();i++){
            if(n[i-1]>n[i]) x=0;
        }
        for(int i=1;i<n.size();i++){
            if(n[i-1]<n[i]) y=0;
        }
        return x|y;
    }
};