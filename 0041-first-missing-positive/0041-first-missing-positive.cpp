class Solution {
public:
    int firstMissingPositive(vector<int>& n) {
        set<int> s;
        for(int i:n){
            if(i>0) s.insert(i);
        }
        
        int k=1;
        for(int i:s){
            if(i>k) return k;
            k++;
        }
        return k;
    }
};