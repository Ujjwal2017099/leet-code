class Solution {
public:
    int canBeTypedWords(string t, string b) {
        int arr[26]={0};
        for(char c:b) arr[c-'a']=1;
        int ans=0;
        bool ok=1;
        t.push_back(' ');
        for(int i=0;i<t.size();i++){
            if(t[i]==' '){
                if(ok) ans++;
                ok=1;
                continue;
            }
            if(arr[t[i]-'a']){
                ok=0;
            }
        }
        return ans;
    }
};