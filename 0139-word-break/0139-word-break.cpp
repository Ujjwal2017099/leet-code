class Trie {
    public:
    unordered_map<char,Trie*> w;
    bool eow;
    Trie(){
        eow=0;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& word) {
        Trie* x=new Trie();
        for(string& a:word){
            insert(x,a,0);
        }
        vector<bool> dp(s.length()+1,0);
        dp[0]=1;
        for(int i=0;i<s.length();i++){
            if(dp[i]){
                Trie* ptr=x;
                for(int j=i;i<s.length();j++){
                    if(!ptr->w[s[j]]) break;
                    
                    ptr = ptr->w[s[j]];
                    if(ptr->eow) dp[j+1]=1;
                }
            }
        }
        return dp.back();
    }
    void insert(Trie* x,string& s,int i){
        // if(i==s.length()) return;
        if(i==s.length()){
            x->eow=1;
            return;
        }
        if(x->w[s[i]]) insert(x->w[s[i]],s,i+1);
        else {x->w[s[i]] = new Trie();insert(x->w[s[i]],s,i+1);}
    }
    
};







