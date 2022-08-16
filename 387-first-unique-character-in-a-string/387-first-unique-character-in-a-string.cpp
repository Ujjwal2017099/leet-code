class Solution {
public:
    int firstUniqChar(string s) {
        int arr['z'+1]={0};
        for(char i:s) arr[i]++;
        for(int i=0;i<s.length();i++){
            if(arr[s[i]]==1) return i;
        }
        return -1;
    }
};