class Solution {
public:
    int maxOperations(vector<int>& n, int k) {
        int i = 0;
        int j = n.size()-1;
        int count = 0;
        
        sort(n.begin(),n.end());
        
        while(i<j)
        {
            if(n[i] + n[j] == k){
                i++;
                j--;
                count++;
            }
            else if(n[i] + n[j] > k){
                j--;
            }
            else{
                i++;
            }
        }
        
        return count;
    }
};