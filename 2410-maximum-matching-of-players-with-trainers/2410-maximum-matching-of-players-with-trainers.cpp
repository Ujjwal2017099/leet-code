class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& pl, vector<int>& tr) {
        int ans =0 ;
        unordered_map<int,int> mp;
        sort(tr.begin(),tr.end());
        sort(pl.begin(),pl.end());
        set<int> t;
        
        for(int i:tr){
            t.insert(i);
            mp[i]++;
        }
        map<int,int> in;
        for(int i=0;i<tr.size();i++){
            in[tr[i]] = i;
        }
        for(int i=0;i<pl.size();i++){
            auto k = t.lower_bound(pl[i]);
            if(k==t.end()){
                break;
            }
            if(mp[*k] ) {
                ans++;
                mp[*k]--;
                if(mp[*k] == 0){
                    t.erase(*k);
                }
            }
            
            else{
                int x = in[*k] + 1;
                bool f=0;
                while(x<tr.size()){
                    if(tr[x] >= pl[i] and mp[tr[x]]) {
                        f=1;
                        break;
                        
                    }
                    
                    x++;
                }
                if(f ){
                    mp[tr[x]]--;
                    ans++;
                }else{
                    break;
                }
                
            }
        }
        
        return ans;
    }
};