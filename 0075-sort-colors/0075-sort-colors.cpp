class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3,0);
        for(int i:nums) v[i]++;
        int x=0;
        for(int i=0;i<nums.size();i++){
            while(!v[x]) x++;
            nums[i] = x;
            v[x]--;
        }
    }
};