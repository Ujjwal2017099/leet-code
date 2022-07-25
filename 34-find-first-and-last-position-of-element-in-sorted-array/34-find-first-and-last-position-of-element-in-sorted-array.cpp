class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l =0;
        int r = nums.size()-1;
        bool f = false;
        int mid = 0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(nums[mid] == target){
                f=true;
                break;
            }else if(nums[mid]>target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        
        if(!f){
            return {-1,-1};
        }
        int a1,a2;
        int temp = mid;
        while(mid>=0 and nums[mid] == target){
            
            mid--;
        }
        if(mid<0 or nums[mid]!=target) a1 =  mid+1;
        else a1 = mid;
        
        mid = temp;
        while(mid<nums.size() and nums[mid] == target){
            mid++;
        }
        if(mid >= nums.size() or nums[mid] != target) a2 = mid-1;
        else a2 = mid;
        
        return {a1,a2};
    }
};