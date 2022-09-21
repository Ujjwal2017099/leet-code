class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& n, vector<vector<int>>& q){
        vector<int> ans;
        int sum = 0;
        for(int i:n){
            if(!(i&1)){
                sum += i;
            }
        }
        for(auto i:q){
            int val = i[0],x = i[1];
            int prev = n[x];
            n[x] += val;
            if(!(n[x]&1)){
                sum += val;
                if(prev&1) sum += prev;
            }else if(!(prev&1)){
                sum -= prev;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};