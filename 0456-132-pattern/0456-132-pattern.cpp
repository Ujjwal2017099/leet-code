class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int k = INT_MIN;
        stack<int> s;
        for(int i = nums.size()-1 ; i>=0 ; i--){
            if(nums[i]<k) return true;
            
            while(!s.empty() and s.top() < nums[i]){
                k = s.top();
                s.pop();
            }
            
            s.push(nums[i]);
        }
        
        return false;
    }
};