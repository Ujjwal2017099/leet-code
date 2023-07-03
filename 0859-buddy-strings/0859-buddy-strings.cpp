class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.size()!=g.size()) return 0;
        vector<int> v;
        int arr[26]={0};
        for(int i=0;i<s.size();i++){
            if(s[i]!=g[i]){
                v.push_back(i);
            }
            arr[s[i]-'a']++;
        }
        if(v.size()>2) return 0;
        if(v.empty()){
            for(int i=0;i<26;i++){
                if(arr[i]>1) return 1;
            }
            return 0;
        }
        if(v.size()==2){
            swap(s[v[0]],s[v[1]]);
            if(s[v[0]]==g[v[0]] && s[v[1]]==g[v[1]]) return 1;
            return 0;
        }
        return 0;
    }
};