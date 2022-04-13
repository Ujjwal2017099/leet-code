class Solution {
public:
    vector<int> sum(vector<vector<int>> mat)
    {
        int m = mat.size();
        vector<int> _sum ;
        for(int i = 0 ; i < m ; i++)
        {
            int SUM = 0;
            for(int j = 0 ; j < mat[i].size() ; j++)
            {
                SUM += mat[i][j];    
            }
            _sum.push_back(SUM);
        }
        
        return _sum;
    }
    
    void sorting(vector<int>& _sum,vector<int>& index)
    {
        for(int i = 0 ; i < _sum.size() ; i++)
        {
            for(int j = 0 ; j < _sum.size() - i -1; j++)
            {
                if(_sum[j] > _sum[j+1])
                {
                    int temp = _sum[j];
                    _sum[j] = _sum[j+1];
                    _sum[j+1] = temp;
                    
                     temp = index[j];
                    index[j] = index[j+1];
                    index[j+1] = temp;
                }
            }
        }
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<int> _sum = sum(mat);
        vector<int> index;
        for(int i=0 ; i < mat.size() ; i++)
        {
            index.push_back(i);    
        }
        
        sorting(_sum , index);
        vector<int> ans;
        int i = 0;
        while(k > 0)
        {
            ans.push_back(index[i]);
            i++;
            k--;
        }
        
        return ans;
    }
};