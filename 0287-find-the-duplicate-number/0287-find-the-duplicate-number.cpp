class Solution {
public:
    int findDuplicate(vector<int>& n) {
        int i=0,j=0;
        do{
            i = n[i];
            j = n[n[j]];
        }while(i!=j);
        
        
        i=0;
        while(i!=j){
            i = n[i];
            j = n[j];
        }
        return i;
    }
};