class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        map<int,int> m;
        for(int i=0 ; i<tasks.size() ; i++)
        {
            m[tasks[i]]++;
        }
        
        int steps = 0;
        for(auto i : m)
        {
            while(i.second % 3 != 0 and i.second > 1){steps++; i.second -= 2;}
            
            while(i.second != 0 and i.second % 3 == 0){steps ++ ; i.second -= 3;}
            
            if(i.second == 1) {return -1;}
        }
        
        
 
        return steps;
    }
};