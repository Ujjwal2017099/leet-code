class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int> cnt;
        for(char c:m) cnt[c]++;
        for(char c:r){
            if(!cnt[c]) return 0;
            cnt[c]--;
        }
        return 1;
    }
};