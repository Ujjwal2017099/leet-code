class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int prev = 0;
    priority_queue<int> l;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
    }
    
    double findMedian() {
        int s = prev + pq.size();
        // cout<<pq.top()<<" ";
        if(s&1){
            int shifts = s/2 - prev;
            while(shifts--){
                prev++;
                l.push(pq.top());
                pq.pop();
            }
            while(!l.empty() && pq.top() < l.top()){
                int x = pq.top();
                pq.pop();
                
                pq.push(l.top());
                l.pop();
                l.push(x);
            }
            return pq.top();
        }
        
        int shifts = s/2 - prev -1;
        while(shifts--){
            prev++;
            l.push(pq.top());
            pq.pop();
        }
        while(!l.empty() && l.top() > pq.top()){
            int x = pq.top();
            pq.pop();
            
            pq.push(l.top());
            l.pop();
            l.push(x);
        }
        int sum = pq.top();pq.pop();
        sum+=pq.top();
        pq.push(sum-pq.top());
        
        return sum/2.0;
    }
};