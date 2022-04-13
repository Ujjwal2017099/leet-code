class KthLargest {
public:
    int k;
    priority_queue<int> num;
    KthLargest(int a, vector<int>& nums) {
        k = a;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            num.push(-1*nums[i]);
        }
    }
    
    int add(int val) {
        
        num.push(-1*val);
        
        while(num.size() > k) num.pop();
        cout<<endl;
        return -1*num.top();
    }
};