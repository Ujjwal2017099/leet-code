class Solution {
public:
    long long countGood(vector<int>& n, int k) {
        long long cnt=0;
        long long ans=0;
        map<int,int> mp;
        int l=0,i=0;
        int mxlen=0;
        do{
            // if((i==n.size()&& l>=i)||l>i) break;
            int st=i;
            for(i;i<n.size();i++){
                if(cnt>=k){
                    ans+=n.size()-i+1;
                    // cout<<l<<" "<<i<<endl;
                    // ans = (ans&1) ? ((ans-1)/2)*ans : (ans/2)*(ans-1);
                    mxlen = max(mxlen,i-l);
                    break;
                }
                mp[n[i]]++;
                long long x=mp[n[i]];
                long long y=x-1;
                cnt -= y&1 ? ((y-1)/2)*y : (y/2)*(y-1);
                cnt += x&1 ? ((x-1)/2)*x : (x/2)*(x-1);
                // cout<<i<<" ";
            }
            if(i==n.size()){
                if(cnt>=k){ 
                    ans+=n.size()-i+1;
                // cout<<l<<" "<<i<<endl;
                    mxlen = max(mxlen,i-l);
                }
                // break;
            }
            long long y = mp[n[l]];mp[n[l]]--;l++;
            long long x = y-1;
            cnt -= y&1 ? ((y-1)/2)*y : (y/2)*(y-1);
            cnt += x&1 ? ((x-1)/2)*x : (x/2)*(x-1);
            // cout<<cnt<<"r ";
            if(i!=st){
                // ans += l-1;
            }
        }while(!((i==n.size()&& l>=i)||l>i));
        // if(ans>1 || (ans==1 && mxlen<n.size())) ans++;
        int t=ans;
        // while(t){
        //     ans += t-1;
        //     t/=2;
        // }
        // ans += (t*(t-1))/2;
        
        return ans;
    }
};