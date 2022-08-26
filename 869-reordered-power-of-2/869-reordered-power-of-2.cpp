class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = sortit(n);
        for(int i=0;i<32;i++){
            if(s == sortit(1<<i)) return 1;
        }
        return 0;
    }
    string sortit(int n){
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
};