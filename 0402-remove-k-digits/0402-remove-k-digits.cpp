class Solution {
public:
    string removeKdigits(string n, int k) {
        if(k==n.size()) return "0";
        vector<char> ans;
        map<char,deque<int>> m;
        for(int i=0;i<n.size()-1;i++){
            if(!k) {
                while(i<n.size()-1){
                    ans.push_back(n[i++]);
                    m[n[i]].push_back(ans.size());
                }
                break;
            }
            
            if(n[i]>n[i+1]){
                k--;
                while(ans.size() && k && ans.back()>n[i+1]){
                    m[ans.back()].pop_back();
                    ans.pop_back();k--;
                }
            }else{
                ans.push_back(n[i]);
                m[n[i]].push_back(ans.size());
            }
        }
        ans.push_back(n.back());
        m[n.back()].push_back(ans.size());
        string x="";
        
        for(auto it=m.rbegin();it!=m.rend() && k;it++){
            while(it->second.size() && k){
                int y=it->second.front();it->second.pop_front();
                ans[y-1]='?';
                k--;
            }
        }
        
        // for(auto i:ans){
        //     cout<<i;
        // }
        
        for(int i=0;i<ans.size();i++){
            // cout<<ans[i];
            if(ans[i]=='?') continue;
            if((x.empty() && ans[i]!='0') || x.size() ) x.push_back(ans[i]);
        }
        
        return x.size() ? x : "0";
    }
};