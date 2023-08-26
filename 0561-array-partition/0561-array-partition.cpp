class Solution {
public:
    int arrayPairSum(vector<int>& n) {
        sort(n.begin(),n.end());
        int sum=0;
        for(int i=0;i<n.size();i+=2){
            sum+=n[i];
        }
        return sum;
    }
};