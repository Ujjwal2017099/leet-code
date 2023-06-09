class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        for(char c:l){
            if(c>t) return c;
        }
        return l[0];
    }
};