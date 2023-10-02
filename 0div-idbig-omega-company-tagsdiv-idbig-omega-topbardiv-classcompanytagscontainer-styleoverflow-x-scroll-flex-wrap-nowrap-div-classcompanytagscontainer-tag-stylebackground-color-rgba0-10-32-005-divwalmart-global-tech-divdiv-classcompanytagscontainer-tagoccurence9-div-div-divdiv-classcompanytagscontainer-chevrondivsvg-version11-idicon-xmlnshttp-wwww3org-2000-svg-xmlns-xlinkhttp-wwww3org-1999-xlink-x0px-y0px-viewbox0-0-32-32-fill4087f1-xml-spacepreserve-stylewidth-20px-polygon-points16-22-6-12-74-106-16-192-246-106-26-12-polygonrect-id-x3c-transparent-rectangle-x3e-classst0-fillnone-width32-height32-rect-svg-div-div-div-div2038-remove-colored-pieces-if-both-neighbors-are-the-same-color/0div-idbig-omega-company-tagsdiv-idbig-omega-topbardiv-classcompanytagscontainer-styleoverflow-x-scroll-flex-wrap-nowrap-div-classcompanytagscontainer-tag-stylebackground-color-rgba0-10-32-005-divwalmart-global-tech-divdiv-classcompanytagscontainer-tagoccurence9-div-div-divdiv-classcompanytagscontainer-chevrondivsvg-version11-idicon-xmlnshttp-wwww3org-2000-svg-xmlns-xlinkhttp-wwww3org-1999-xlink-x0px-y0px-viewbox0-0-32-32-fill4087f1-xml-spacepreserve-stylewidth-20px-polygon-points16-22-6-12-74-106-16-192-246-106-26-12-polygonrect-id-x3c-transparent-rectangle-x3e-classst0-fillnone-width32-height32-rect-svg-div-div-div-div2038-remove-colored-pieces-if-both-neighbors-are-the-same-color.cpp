class Solution {
public:
    bool winnerOfGame(string v) {
        int a=0,b=0;
        for(int i=1;i<=(int)v.size()-2;i++){
            if(v[i]=='B' && v[i]==v[i-1] && v[i]==v[i+1]) b++;
            if(v[i]=='A' && v[i]==v[i-1] && v[i]==v[i+1]) a++;
        }
        return a>b;
    }
};