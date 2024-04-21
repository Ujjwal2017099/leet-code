class Solution {
public:
    int numberOfSpecialChars(string w) {
        int l[26] , u[26];
        
        for(int i=0;i<=25;i++){
            l[i]=-1;
            u[i]=-1;
        }
        
        for(int i=0;i<w.size();i++){
            if(isupper(w[i])){
                if(u[w[i]-'A']==-1) u[w[i]-'A'] = i;
            }else{
                l[w[i]-'a']=i;
            }
        }
        int ans=0;
        for(int i=0;i<=25;i++){
            if(l[i]<u[i] && l[i]!=-1) ans++;
        }
        
        return ans;
    }
};