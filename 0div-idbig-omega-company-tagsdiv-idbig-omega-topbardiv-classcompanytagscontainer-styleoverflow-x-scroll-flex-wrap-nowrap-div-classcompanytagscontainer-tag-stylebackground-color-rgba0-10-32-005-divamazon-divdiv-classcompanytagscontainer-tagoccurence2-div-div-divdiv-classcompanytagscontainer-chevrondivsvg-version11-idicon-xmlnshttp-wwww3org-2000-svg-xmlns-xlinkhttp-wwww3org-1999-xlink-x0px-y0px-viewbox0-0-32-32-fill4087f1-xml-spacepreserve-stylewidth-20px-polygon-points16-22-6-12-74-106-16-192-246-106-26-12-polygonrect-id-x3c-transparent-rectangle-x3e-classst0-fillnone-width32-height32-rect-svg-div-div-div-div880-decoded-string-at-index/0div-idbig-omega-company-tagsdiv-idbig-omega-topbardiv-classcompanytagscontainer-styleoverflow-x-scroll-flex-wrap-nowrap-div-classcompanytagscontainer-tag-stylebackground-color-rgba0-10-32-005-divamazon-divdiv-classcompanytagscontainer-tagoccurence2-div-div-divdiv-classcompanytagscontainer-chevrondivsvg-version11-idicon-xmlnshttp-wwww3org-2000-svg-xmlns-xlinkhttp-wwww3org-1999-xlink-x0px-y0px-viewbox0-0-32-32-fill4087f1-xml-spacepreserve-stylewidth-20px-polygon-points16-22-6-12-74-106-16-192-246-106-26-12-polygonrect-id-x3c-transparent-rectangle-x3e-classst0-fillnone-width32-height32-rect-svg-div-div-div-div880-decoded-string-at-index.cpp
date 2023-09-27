class Solution {
public:
    long long x=-1;
    long long y=-1;
    bool ch=0;
    string decodeAtIndex(string s, int k) {
        // cout<<k<<" ";
        // if(k==1) {
        //     string ans;ans.push_back(s[0]);
        //     return ans;
        // }
        if(x!=-1 && k<=x*y){
            // cout<<k;
            return s.substr((k-1)%x,1);
        }
        long long cnt=0;
        long long prev=0;
        long long l=0;
        
        for(int i=0;i<s.size();i++){
            bool f=0;
            if(s[i]>='2' && s[i]<='9'){
                if(x==-1) {
                    x=i;ch=1;
                    y=(s[i]-'0');
                }
                else if(ch){
                    y*=s[i]-'0';
                }
                prev=cnt;
                cnt += cnt*1LL*(s[i]-'1');
                f=1;
                if(cnt>k){
                    return decodeAtIndex(s,k-prev);
                }
                if(cnt==k){
                    return s.substr(l,1);
                }
            }
            if(!f) {l=i;cnt++;ch=0;}
            if(cnt==k){
                return s.substr(i,1);
            }
            
        }
        return s;
    }
};