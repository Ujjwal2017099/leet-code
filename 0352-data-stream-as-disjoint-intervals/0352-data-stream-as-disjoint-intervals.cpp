class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto it=s.begin();it!=s.end();it++){
            // if(it+1==s.end()) break;
            if(ans.empty()){
                ans.push_back({*it,*it});
            }else{
                if(ans.back()[1]+1 == *it){
                    ans.back()[1] = *it;
                }else{
                    ans.push_back({*it,*it});
                }
            }
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */