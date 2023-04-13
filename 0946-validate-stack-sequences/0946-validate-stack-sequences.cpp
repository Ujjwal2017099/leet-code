class Solution {
public:
    bool validateStackSequences(vector<int>& a, vector<int>& b) {
        int i=0,j=0;
        vector<int> t;
        while(i<a.size()){
            t.push_back(a[i]);i++;
            while(t.size() && j<b.size() && b[j]==t.back()){
                j++;
                t.pop_back();
            }
        }
        
        return t.empty() && j==b.size();
    }
};