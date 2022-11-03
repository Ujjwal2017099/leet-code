class Solution {
public:
    string longestPalindrome(string s) {
        int x=0,y=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(ispal(i,j,s) and j-i>y-x){
                    x=i;
                    y=j;
                }
            }
        }
        string ans="";
        for(int i=x;i<=y;i++){
            ans+=s[i];
        }
        return ans;
    }
    bool ispal(int i,int j,string& s){
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++;j--;
        }
        return 1;
    }
};