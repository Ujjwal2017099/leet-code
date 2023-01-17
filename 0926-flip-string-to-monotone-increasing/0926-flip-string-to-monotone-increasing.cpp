class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int x=0;
        for(char c:s){
            if(c=='0'){
                x++;
            }
        }
        int y=x;
        for(char c:s){
            if(c=='1') x++;
            else y = min(y,--x);
        }
        return y;
    }
};