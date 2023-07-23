class Solution {
public:
    string largestNumber(vector<int>& n) {
        vector<vector<int>> v;
        int cnt=0;
        for(int i:n){
            vector<int> x;
            if(i==0) cnt++;
            while(i){
                x.push_back(i%10);i/=10;
            }
            if(x.empty()) x.push_back(0);
            reverse(x.begin(),x.end());
            v.push_back(x);
            // cout<<x.size()<<" "<<i<<endl;
        }
        if(cnt==n.size()) return "0";
        sort(v.begin(),v.end(),[&](vector<int>& a,vector<int>& b){
            int i=0;
            // cout<<a.size()<<" "<<b.size()<<endl;
            while(i<a.size()+b.size()){
                if(i<a.size()){
                    if(i<b.size()){
                        if(a[i]!=b[i]) return a[i]>b[i];
                    }else{
                        if(a[i]!=a[i%b.size()]) return a[i]>a[i%b.size()];
                    }
                }else{
                    if(i<b.size()){
                        if(b[i%a.size()]!=b[i]) return b[i%a.size()]>b[i];
                    }else{
                        if(b[i%a.size()]!=a[i%b.size()]) return b[i%a.size()]>a[i%b.size()];
                    }
                }
                i++;
            }
            return true;
        });
        
        string ans="";
        for(vector<int> x:v){
            for(int i:x) {
                ans.push_back(i+'0');
            }
            // cout<<" ";
        }
        return ans;
    }
};