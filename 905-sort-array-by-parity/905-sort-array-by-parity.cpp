class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;
        
        for(int i:nums){
            if(i%2) odd.push_back(i);
            else even.push_back(i);
        }
        
        even.insert(even.end(),odd.begin(),odd.end());
        
        return even;
    }
};