class Solution {
public:
    string s;
    Solution(){
        s="0";
    }
    string invert(string s){
        for(char& c:s){
            if(c=='1') c='0';
            else c='1';
        }
        // cout<<s<<endl;
        return s;
    }
    char findKthBit(int n, int k) {
        if(n==0){
            return s[k-1];
        }
        string t = invert(s);reverse(t.begin(),t.end());
        s += "1" + t;
        return findKthBit(n-1,k);
    }
};