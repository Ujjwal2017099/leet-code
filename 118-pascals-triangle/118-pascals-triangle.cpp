class Solution {
public:
    vector<vector<int>> generate(int n) {
        int a=2;
        vector<vector<int>> v;
        for(int i=1;i<=n;i++){
            vector<int> k;
            k.push_back(1);
            for(int j=a;j<i;j++){
                vector<int> t = v[j-1];
                a++;
                for(int it = 0 ; it < t.size()-1 ;it++){
                    k.push_back(t[it] + t[it+1]);
                }
            }
            if(i!=1) k.push_back(1);
            v.push_back(k);
        }
        
        return v;
    }
};