class StockSpanner {
public:
    vector<int> v;
    vector<int> cnt;
    StockSpanner() {
        
    }
    
    int next(int p) {
        if(v.empty()){
            v.push_back(p);
            cnt.push_back(1);
            return 1;
        }
        if(p<v.back()){
            v.push_back(p);
            cnt.push_back(1);
            return 1;
        }
        int ans=0;
        v.back() = p;
        cnt.back()++;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]>p) break;
            
            ans+=cnt[i];
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */