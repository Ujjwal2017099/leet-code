class Solution {
public:
    int compareVersion(string v1, string v2) {
        vector<int> a,b;
        int t=0;
        for(int i=0;i<v1.size();i++){
            if(v1[i]=='.'){
                a.push_back(t);t=0;
            }else{
                t = t*10 + (v1[i]-'0');
            }
        }
        a.push_back(t);
        t=0;
        for(int i=0;i<v2.size();i++){
            if(v2[i]=='.'){
                b.push_back(t);t=0;
            }else{
                t = t*10 + (v2[i]-'0');
            }
        }
        b.push_back(t);
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]) return -1;
            if(a[i]>b[j]) return 1;
            i++;j++;
        }
        while(i<a.size()){
            if(a[i]!=0) return 1;
            i++;
        }
        while(j<b.size()){
            if(b[j]!=0) return -1;
            j++;
        }
        
        return 0;
    }
};