class Solution {
public:
    string convert(string s, int n) {
        vector<vector<char>> v(n,vector<char>(s.length(),'?'));
        string ans="";
        int in=0, j=0;
        if(n==1) return s;
        int a=0;
        while(1){
            if(in == s.size()) break;
            for(int i=a;i<n;i++){
                if(in==s.size()) break;
                v[i][j] = s[in];in++;
            }
            for(int i=n-2;i>=0;i--){
                if(in==s.size()) break;
                v[i][++j] = s[in];in++;
            }
            a=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<s.length();j++){
                if(v[i][j]!='?') ans.push_back(v[i][j]);
                // cout<<v[i][j]<<" ";
            }
            // cout<<endl;
        }
        return ans;
    }
};