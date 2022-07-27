
class Solution {
public:
    bool canWinNim(int n) {
//         vector<bool> v(n+1,false);
//         if(n>=1) v[1] = true;
//         if(n>=2) v[2] = true;
//         if(n>=3) v[3] = true;
        
//         for(int i=4;i<=n;i++){
//             for(int j=1;j<=3;j++){
//                 bool f = v[i-j];
//                 if(!f){
//                     v[i] = true;
//                     break;
//                 }
//             }
//         }
//         return v[n];
        
        return !(n%4==0);
    }
};