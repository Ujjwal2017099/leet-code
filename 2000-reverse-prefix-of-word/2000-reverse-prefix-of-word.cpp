class Solution {
public:
    string reversePrefix(string w, char ch) {
        for(int i=0;i<w.size();i++){
            if(w[i]==ch){
                reverse(w.begin(),w.begin()+i+1);
                return w;
            }
        }
        return w;
    }
};