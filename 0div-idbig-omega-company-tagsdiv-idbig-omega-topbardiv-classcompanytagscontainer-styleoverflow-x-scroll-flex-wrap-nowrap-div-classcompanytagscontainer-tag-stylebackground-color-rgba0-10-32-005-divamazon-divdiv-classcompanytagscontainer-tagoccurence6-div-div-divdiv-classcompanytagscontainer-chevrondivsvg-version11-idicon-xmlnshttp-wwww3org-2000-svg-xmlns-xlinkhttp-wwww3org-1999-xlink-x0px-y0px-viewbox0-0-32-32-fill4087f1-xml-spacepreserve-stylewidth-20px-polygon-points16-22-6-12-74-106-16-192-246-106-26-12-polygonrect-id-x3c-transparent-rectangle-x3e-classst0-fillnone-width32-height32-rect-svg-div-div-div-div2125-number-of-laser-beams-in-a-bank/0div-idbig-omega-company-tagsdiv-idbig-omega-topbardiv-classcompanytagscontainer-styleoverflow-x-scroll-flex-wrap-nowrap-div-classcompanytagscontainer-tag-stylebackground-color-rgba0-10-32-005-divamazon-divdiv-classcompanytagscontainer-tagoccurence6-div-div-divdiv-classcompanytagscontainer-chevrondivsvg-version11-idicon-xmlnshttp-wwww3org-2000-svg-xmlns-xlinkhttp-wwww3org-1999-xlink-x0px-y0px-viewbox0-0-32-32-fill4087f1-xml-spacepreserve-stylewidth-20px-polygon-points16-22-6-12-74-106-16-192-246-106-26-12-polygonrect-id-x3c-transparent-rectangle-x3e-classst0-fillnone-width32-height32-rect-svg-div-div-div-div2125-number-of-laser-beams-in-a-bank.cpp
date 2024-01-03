class Solution {
public:
    int numberOfBeams(vector<string>& b) {
        int ans=0;
        vector<int> v;
        for(string s:b){
            int cnt=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='1') cnt++;
            }
            v.push_back(cnt);
        }
        int prev=v[0];
        for(int i=1;i<v.size();i++){
            if(v[i] ){
                ans += prev*v[i];
                prev=v[i];
            }
        }
        return ans;
    }
};