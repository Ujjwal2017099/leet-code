class Solution {
public:
    int numRescueBoats(vector<int>& p, int k) {
        sort(p.begin(),p.end());
        int cnt=p.size();
        int i=0,j=p.size()-1;
        
        while(i<j){
            if(p[i]+p[j]<=k) {cnt--;i++;j--;}
            else j--;
        }
        // if(i<p.size()) cnt++;
        return cnt;
    }
};