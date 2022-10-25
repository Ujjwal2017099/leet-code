class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        bool ok =1 ;
        int x=0,y=0;
        int i=0,j=0;
        while(x<w1.size() and y<w2.size()){
            while(i<w1[x].length() and j<w2[y].length()){
                if(w1[x][i] != w2[y][j]) ok=0;
                i++;
                j++;
            }
            if(j==w2[y].length()) {j=0;y++;}
            if(i==w1[x].length()) {i=0;x++;}
        }
        if(x!=w1.size() or y!=w2.size()) ok=0;
        return ok;
    }
};