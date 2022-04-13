
class Solution {
public:
    int largestInteger(int num) {
        
        vector<int> vec;
        
        while(num !=0)
        {
            vec.push_back(num%10);
            num = num/10;
        }
        reverse(vec.begin(),vec.end());
               
        priority_queue<int> even;
        priority_queue<int> odd;
        
        for(int i=0 ; i<vec.size() ; i++)
        {
            if(vec[i]%2 == 0) even.push(vec[i]);
            else odd.push(vec[i]);
        }
        int ans = 0;
        for(int i=0 ; i<vec.size() ; i++)
        {
            if(vec[i]%2 == 0)
            {
                ans = ans*10 + even.top();
                even.pop();
            }
            else
            {
                ans = ans*10 + odd.top();
                odd.pop();
            }
        }
        return ans;
    }
};