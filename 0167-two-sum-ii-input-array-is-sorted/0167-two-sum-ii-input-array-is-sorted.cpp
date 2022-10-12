class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int i=0,j=n.size()-1;
        while(i<j){
            int s = n[i]+n[j];
            if(s==t) return {i+1,j+1};
            if(s>t) j--;
            if(s<t) i++;
        }
        return {};
    }
};