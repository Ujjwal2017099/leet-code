class Solution {
public:
    vector<int> ans;
    unordered_map<int,bool> mp;
    vector<int> grayCode(int n) {
        // ans.push_back(0);
        for(int i=0;i<(1<<n);i++){
            ans.push_back(i^(i>>1));
        }
        return ans;
    }
//     bool fun(int n,int num){
//         if(mp[num]){
//             return 0;
//         }
//         if(ans.size()+1 == (1<<n)){
//             int x = log2(num);
//             if(num!=(1<<x)) return 0;
//         } 
        
//         int x = ans.back()^num;
//         int y = log2(x);
//         if(x!=(1<<y)) return 0;
        
//         ans.push_back(num);
//         mp[num] = 1;
//         bool f=0;
//         for(int i=1;i<(1<<n);i++) {
//             f|=fun(n,i);
//             if(ans.size() == (1<<n) or f){
//                 return 1;
//             }
//         }
//         if(!f and ans.size() < (1<<n)){
//             ans.pop_back();
//             mp[num] =0;
//         }
//         return f;
//     }
};