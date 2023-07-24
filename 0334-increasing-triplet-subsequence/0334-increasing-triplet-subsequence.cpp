class Solution {
public:
    bool increasingTriplet(vector<int>& n) {
        int x=INT_MAX,y=INT_MAX;
        for(int i:n){
            if(i<=x) x=i;
            else if(i<=y) y=i;
            else return 1;
        }
        return 0;
    }
};