class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0 , r = nums.size()-1;
        int index = (l + r)/2;
        
        while(l <= r)
        {
            if(target == nums[index]) return index;
            
            else if(target > nums[index])
            {
                l = index + 1;
                index = (l+r)/2;
            }
            else
            {
                r = index - 1;
                index = (l+r)/2;
            }
        }
        return -1;
    }
};