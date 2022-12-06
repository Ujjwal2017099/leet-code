class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        map<int,int> mp;
        for(int i=0;i<n.size();i++){
            mp[n[i]] = i;
        }
        for(int i=0;i<n.size();i++){
            if(mp.find(target - n[i]) != mp.end()){
                int x = mp[target - n[i]];
                if(x==i) continue;
                return {x , i};
            }
        }
        return {0,1};
    }
};