class Solution {
    int cnt;
    bool f;
public:
    Solution(){
        cnt = 0;
        f = true;
    }
    bool isPalindrome(int l,int r,string s) {
        if(l>r) return false;
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void count(string s,int l,int r){
        if(l >= r) {f = false;return;}
        if(isPalindrome(l,r,s)) {
            cnt++;
        }
        if(f) count(s,l+1,r);
        count(s,l,r-1);
    }
    int countSubstrings(string s) {
        count(s,0,s.length()-1);
        return s.length() + cnt;
    }
};