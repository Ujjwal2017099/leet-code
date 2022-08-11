class Solution {
public:
    string invert(string s){
        for(char& c:s){
            if(c=='1') c='0';
            else c='1';
        }
        // cout<<s<<endl;
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        while(k>s.length()){
            string t=invert(s);
            reverse(t.begin(),t.end());
            s += "1" + t;
        }
        cout<<s<<endl;
        return s[k-1];
    }
};