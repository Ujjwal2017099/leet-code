class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> out(2,0);
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            for(int j=i+1 ; j < nums.size() ; j++){
                
                if(nums.at(i) + nums.at(j) == target){
                    
                    out.at(0) = i;
                    out.at(1) = j;
                    
                    
                    return out;
                }
                
            }
            
        }
        return out;
    }
};