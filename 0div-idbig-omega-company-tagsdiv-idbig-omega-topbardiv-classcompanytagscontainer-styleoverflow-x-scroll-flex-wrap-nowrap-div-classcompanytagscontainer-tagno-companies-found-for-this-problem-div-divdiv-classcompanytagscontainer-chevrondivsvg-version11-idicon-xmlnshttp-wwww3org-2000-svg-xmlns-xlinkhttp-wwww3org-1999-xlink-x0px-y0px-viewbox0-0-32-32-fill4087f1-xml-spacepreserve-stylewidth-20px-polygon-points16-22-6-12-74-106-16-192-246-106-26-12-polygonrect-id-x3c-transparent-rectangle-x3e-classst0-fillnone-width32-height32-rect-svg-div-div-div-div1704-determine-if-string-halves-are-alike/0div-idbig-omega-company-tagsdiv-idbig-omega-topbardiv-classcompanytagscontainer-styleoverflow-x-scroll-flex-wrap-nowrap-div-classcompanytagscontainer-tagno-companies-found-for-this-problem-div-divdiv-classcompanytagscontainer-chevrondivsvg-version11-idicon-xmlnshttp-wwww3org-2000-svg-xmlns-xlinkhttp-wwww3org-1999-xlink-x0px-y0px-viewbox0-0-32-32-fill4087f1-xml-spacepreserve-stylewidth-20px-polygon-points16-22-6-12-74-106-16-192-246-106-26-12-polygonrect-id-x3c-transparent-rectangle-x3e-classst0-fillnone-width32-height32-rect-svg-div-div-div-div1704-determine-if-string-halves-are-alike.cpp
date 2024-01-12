class Solution {
public:
    bool halvesAreAlike(string s) {
        string v = "aeiouAEIOU";
        unordered_map<int,bool> mp;
        for(char c:v) mp[c] = 1;
        
        int x=0,y=0;
        
        int i=0,j=s.size()-1;
        
        while(i<j){
            if(mp[s[i]]) x++;
            
            if(mp[s[j]]) y++;
            i++;
            j--;
        }
        
        return x==y;
    }
};