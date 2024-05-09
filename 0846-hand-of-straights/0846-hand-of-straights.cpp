class Solution {
public:
    bool isNStraightHand(vector<int>& n, int k) {
        int x=n.size();
        if(x%k) return 0;
        
        map<int,int> mp;
        for(int i:n) mp[i]++;
        
        for(auto& it:mp){
            int i=it.first;
            while(it.second){
                int y=1;
                mp[i]--;
                // it.second--;
                while(y<k){
                    if(mp[i+y]==0) {cout<<mp[i+y];return 0;}
                    
                    mp[i+y]--;
                    y++;
                }
            }
        }
        
        return 1;
    }
};