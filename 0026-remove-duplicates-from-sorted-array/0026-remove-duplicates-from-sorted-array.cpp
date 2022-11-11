class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        int j=0;
        for(int i=1;i<n.size();i++){
            while(i<n.size() && n[i]==n[j]) i++;
            if(i==n.size()) break;
            if(j+1!=i) swap(n[i],n[j+1]);
            j++;
        }
        return j+1;
    }
};