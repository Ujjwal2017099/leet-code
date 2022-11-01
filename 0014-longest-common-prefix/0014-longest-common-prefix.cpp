class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        sort(s.begin(),s.end(),[&](string& a,string& b){
           return a.length()<b.length(); 
        });
        int l = s[0].size();
        for(int i=1;i<s.size();i++){
            int x=0;
            for(int j=0;j<s[i].size() and j<l;j++){
                if(s[0][x]!=s[i][j]){
                    l=x;
                    break;
                }
                x++;
            }
        }
        return s[0].substr(0,l);
    }
};