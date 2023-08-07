class Solution {
public:
    void wiggleSort(vector<int>& n) {
        sort(n.begin(),n.end());
        int x=(n.size()-1);
        // cout<<n[x];
        vector<int> t;
        int j=(n.size()+1)/2;
        reverse(n.begin(),n.begin()+j);
        for(int i=0;i<j;i++){
            t.push_back(n[i]);
            if(t.size()==n.size()) break;
            t.push_back(n[x--]);
        }
        n=t;
    }
};