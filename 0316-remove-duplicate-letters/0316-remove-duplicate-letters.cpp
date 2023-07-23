class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> arr(26,0);
        for(char c:s) arr[c-'a']++;
        map<char,int> m;
        string ans="";
        
        for(int i=0;i<s.size();i++){
            if(arr[s[i]-'a']==1 || !m[s[i]]){
                m[s[i]]=i+1;
                continue;
            }
            int x = m[s[i]]-1;
            if(sm_ahead(x,m,s,arr,i)){
                // cout<<s[i]<<" "<<i<<endl;
                m[s[i]] = i+1;
                // arr[s[i]-'a']--;
            }
        }
        vector<int> v;
        for(auto& it:m){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        for(int i:v){
            ans.push_back(s[i-1]);
        }
        return ans;
    }
    bool sm_ahead(int x,map<char,int>& m,string& s,vector<int>& arr,int y){
        arr[s[y]-'a']--;
        for(int i=x+1;i<y;i++){
            if(s[x]<s[i] && arr[s[i]-'a']==1 && m[s[i]]==i+1){
                break;
            }else if(s[x]==s[i]) continue;
            else if(s[x]>s[i] && m[s[i]]==i+1) return true;
        }
        return false;
    }
};