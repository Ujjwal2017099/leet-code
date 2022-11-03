class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        int ans=0;
        unordered_map<string,int> mp;
        for(string s:w){
            mp[s]++;
        }
        priority_queue<int> pq;
        for(auto it:mp){
            if(it.first[0]==it.first[1]){
                pq.push(it.second);
            }
        }
        int mx=0;
        int t=0;
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            if(x==1 and mx!=0 and t==1) {
                break;
            }
            if(x&1 and !t and !(mx&1)){
                ans+=x;
                t=1;
            }else if(x==1){
                ans++;
            }else if(x&1){
                ans+=x-1;
            }else{
                ans+=x;
            }
            mx = max(mx,x);
        }
        for(string s:w){
            if(s[0]!=s[1]){
                string x = "";
                x+=s[1];x+=s[0];
                if(mp[s] and mp[x]){
                    ans+=2;
                    mp[s]--;mp[x]--;
                }
            }
        }
        return ans<<1;
    }
};