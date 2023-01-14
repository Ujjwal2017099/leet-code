class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string bs) {
        vector<int> par(26,-1);
        for(int i=0;i<s1.size();i++){
            Union(par,s1[i],s2[i]);
        }
        for(int i=0;i<bs.size();i++){
            int a = find(par,bs[i]);
            bs[i] = a+'a';
        }
        return bs;
    }
    void Union (vector<int>& par,char a,char b){
        int x = find(par,a);
        int y = find(par,b);
        if(x==y) return;
        
        if(x<y){
            par[x] += par[y];
            par[y] = x;
        }else{
            par[y] += par[x];
            par[x] = y;
        }
    }
    int find(vector<int>& par,char a){
        if(par[a-'a'] < 0) return a-'a';
        return find(par,par[a-'a']+'a');
    }
};