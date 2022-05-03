class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // int ans = 0;
//         int sub = 2;
//         int max = nums[0];
//         bool f = false;
        
//         for(int i = 1 ; i < nums.size() ; i++)
//         {
//             if(nums[i]<max) {f = true;ans = sub;}
//             if(f) sub++;  
            
//             if(nums[i]>max) max = nums[i];
//         }
        
//         return ans;
        
        vector<int> temp = nums;
        
        sort(temp.begin(),temp.end());
        
        int i=0,j=temp.size()-1;
        
        while(i < nums.size()){
            if(temp[i] != nums[i]){
                break;
            }
            i++;
        }
        while(j >= 0){
            if(temp[j] != nums[j]){
                break;
            }
            j--;
        }
        int var = (j-i) + 1;
        if(-1*var == nums.size()) return 0;
        return  var;
    }
};