class Solution {
public:
    void rotate(vector<int>& n, int k) {
        vector<int> t;
        if(k>n.size()) k%=n.size();
        for(int i=1;i<=k;i++){
            t.push_back(n.back());
            n.pop_back();
        }
        reverse(t.begin(),t.end());
        for(int i:n){
            t.push_back(i);
        }
        n=t;
    }
};