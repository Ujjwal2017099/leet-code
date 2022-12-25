class Solution {
public:
    vector<int> answerQueries(vector<int>& n, vector<int>& q) {
        vector<int> v;
        sort(n.begin(),n.end());
        for(int i=0;i<q.size();i++){
            int sum=0;
            for(int j=0;j<n.size();j++){
                sum += n[j];
                if(sum>q[i]){
                    sum=-1;
                    v.push_back(j);
                    break;
                }
            }
            if(sum!=-1){
                v.push_back(n.size());
            }
        }
        return v;
    }
};