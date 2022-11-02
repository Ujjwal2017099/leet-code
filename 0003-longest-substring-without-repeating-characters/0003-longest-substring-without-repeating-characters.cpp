class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> arr;
        int prev=0;
        int len=0;
        int ans=0;
        // return 0;
        for(int i=0;i<s.length();i++){
            while(arr[s[i]]){
                len--;
                arr[s[prev]]--;
                prev++;
            }
            
            arr[s[i]]++;
            len++;
            ans=max(ans,len);
        }
        return ans;
    }
};