class Solution {
public:
    int longestSubarray(vector<int>& n) {
        int o=0,z=0;
        stack<int> s;
        s.push(0);
        bool f=0;
        for(int i=0;i<n.size();i++){
            if(n[i]) {
                if(z==1) o*=-1;
                if(z){
                    s.push(o);
                    o=0;
                    z=0;
                }
                o++;
            }
            else {
                z++;
                f=1;
            }
        }
        if(o){
            if(z==1) o*=-1;
            s.push(o);
        }
        int mx=0;
        while(1){
            int x=abs(s.top());s.pop();
            if(s.empty()) break;
            if(s.top()>=0){
                mx=max(mx,x- (f ? 0 : 1));
            }
            else{
                mx=max(mx,abs(s.top()) + x);
            }
        }
        return mx;
    }
};