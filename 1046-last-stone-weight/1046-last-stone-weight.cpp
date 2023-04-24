class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1)
            {
              sort(stones.begin(),stones.end());
            int n=stones.size();
            stones[n-2]=stones[n-1]-stones[n-2];
            stones.pop_back();
            }
        
        if(stones.size() == 1)
            {
            return stones[0];
            }
        return 0;
    }
};