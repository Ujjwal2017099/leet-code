class Solution {
public:
    long long countVowels(string w) {
        long long cnt=0;
        long long x=0;
        for(int i=0;i<w.size();i++){
            if(w[i]=='a' || w[i]=='e' || w[i]=='i' || w[i]=='o' || w[i]=='u') cnt+=(i+1)*(w.size()-i);
            
        }
        return cnt;
    }
};