class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        int prev=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(s.begin()+prev+1,s.begin()+i);
                prev=i;
            }
        }
        s.pop_back();
        return s;
    }
};