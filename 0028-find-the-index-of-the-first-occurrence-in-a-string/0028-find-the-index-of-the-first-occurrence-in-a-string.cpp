class Solution {
public:
    int strStr(string h, string n) {
        vector<int> t(n.size());
        t[0] = 0;
        int l = 0;
        for(int i=1;i<n.size();i++){
            if(n[i]==n[l]){
                l++;
            }else{
                if(l!=0) {l = t[l-1];i--;}
                else {t[i] = 0;}
                continue;
            }
            t[i] = l;
        }
        // for(int i:t) cout<<i<<" ";
        int s = h.size();
        int j = 0;
        int i = 0;
        while(i<s){
            // cout<<endl<<i<<" "<<j;
            if(j==n.size()) return i-j;
            if(n[j] == h[i]){i++;j++;}
            else if(j>0) j = t[j-1] ;
            else i++;
        }
        if(j==n.size()) return i-j;
        return -1;
    }
};