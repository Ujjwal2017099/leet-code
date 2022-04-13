class Solution {
public:
    long check(vector<vector<int>> temp , int i,int j,int m,int n)
    {
        int count = 0;
        
        count += i+1 < m and temp[i+1][j] ? 1 : 0;
        count += i-1 >= 0 and temp[i-1][j] ? 1 : 0;
        count += j+1 < n and temp[i][j+1] ? 1 : 0;
        count += j-1 >= 0 and temp[i][j-1] ? 1 : 0;
        count += i+1 < m and j+1 < n and temp[i+1][j+1] ? 1 : 0;
        count += i-1 >= 0 and j-1 >= 0 and temp[i-1][j-1] ? 1 : 0;
        count += i-1 >= 0 and j+1 < n and temp[i-1][j+1] ? 1 : 0;
        count += i+1 < m and j-1 >= 0 and temp[i+1][j-1] ? 1 : 0;
        
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;        
        long m = board.size();
        long n = board[0].size();

        for(long i = 0 ; i < m ; i++)
        {
            for(long j = 0 ; j < n ; j++)
            {
                long count = 0;
                count = check(temp , i , j , m , n );
               
                if(count < 2 or count > 3) board[i][j] = 0;
                else if(count == 3 ) board[i][j] = 1;
                else if(temp[i][j] == 1 and count == 2) board[i][j] = 1;
            }
            cout<<endl;
        }
    }
};