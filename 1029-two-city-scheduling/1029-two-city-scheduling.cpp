class Solution {
public:
    void sorting(int diff[][2],int size)
    {
        for(int j = 1 ; j < size ; j++)
        {
            for(int i = 0 ; i < size-j ; i++)
            {
                if(diff[i][0] > diff[i+1][0])
                {
                    int temp = diff[i][0];
                    int _temp = diff[i][1];
                    
                    diff[i][0] = diff[i+1][0];
                    diff[i][1] = diff[i+1][1];
                    
                    diff[i+1][0] = temp;
                    diff[i+1][1] = _temp;
                }
            }
        }
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int size = costs.size();
        int cost = 0;
        
        int diff[size][2];
        for(int i = 0 ; i < costs.size() ; i++)
        {
            diff[i][0]=(costs[i][0] - costs[i][1]);
            diff[i][1]=(i);
        }
        
        
        sorting(diff,size);
        
        
        for(int i = 0 ; i < size/2 ; i++)
        {
            cost += costs[diff[i][1]][0];
        }
        for(int i = size/2 ; i < size ; i++)
        {
            cost += costs[diff[i][1]][1];
        }
        
        
        return cost;
    }     
};