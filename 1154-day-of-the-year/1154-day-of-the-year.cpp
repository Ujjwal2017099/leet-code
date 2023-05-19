class Solution {
public:
    int dayOfYear(string d) {
        int m[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int y=stoi(d.substr(0,4));
        if(y%400==0 || (y%100!=0 && y%4==0)) m[2]++;
        int mo=stoi(d.substr(5,2));
        int da=stoi(d.substr(8,2));
        for(int i=1;i<13;i++) m[i]+=m[i-1];
        // cout<<mo<<" "<<da;
        return m[mo-1]+da;
    }
};