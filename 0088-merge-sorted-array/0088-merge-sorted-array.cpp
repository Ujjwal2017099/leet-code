class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        vector<int> t;
        int i=0,j=0;
        while(i<m && j<n){
            if(n1[i]<=n2[j]) t.push_back(n1[i++]);
            else t.push_back(n2[j++]);
        }
        while(i<m){
            t.push_back(n1[i++]);
        }
        while(j<n){
            t.push_back(n2[j++]);
        }
        for(int i=0;i<m+n;i++){
            n1[i]=t[i];
        }
    }
};