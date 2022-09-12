class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        if(t.empty()) return 0;
        int cnt=0;
        int ans = 0;
        int l = t.size()-1;
        int f=0;
        sort(t.begin(),t.end());
        int i=0;
        for(i=0;i<=l;i++){
            if(p >= t[i]){
                p-=t[i];
                cnt++;
                ans = max(ans,cnt);
            }else if(cnt>=1){
                p+=t[l-f];
                l--;cnt--;i--;
            }
        //     if(l+1 < t.size() and p-t[l+1] == t[i+1] and i+1 == l+1) ans = max(ans,cnt+2);
        }
        // if(t[i] == p) ans = max(ans,cnt+1);
        return ans;
    }
};