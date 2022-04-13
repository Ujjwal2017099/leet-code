class Solution {
public:
    
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        if(binary_search(nums.begin(),nums.end(),target)) return true;
        else return false;
    }
};