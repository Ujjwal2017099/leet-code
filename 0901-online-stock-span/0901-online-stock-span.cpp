class StockSpanner {
public:
    vector<int> v;
    StockSpanner() {
        
    }
    
    int next(int p) {
        v.push_back(p);
        int cnt=0;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]>p) break;
            
            cnt++;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */