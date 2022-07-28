class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;
        
        int i=0;
        
        while(i<=m and n>=0){
            if(matrix[i][n]==target) return true;
            
            if(matrix[i][n] > target) n--;
            else i++;
        }
        
        return false;
    }
};