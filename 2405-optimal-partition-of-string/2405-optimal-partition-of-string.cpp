class Solution {
public:
    int partitionString(string s) {
        int cnt[26]={0};
        int ans=1;
        for(int i=0;i<s.size();i++){
            if(cnt[s[i]-'a']){
                ans++;
                for(int j=0;j<26;j++) cnt[j]=0;
                cnt[s[i]-'a']=1;
            }
            else{
                cnt[s[i]-'a']=1;
            }
        }
        return ans;
    }
};