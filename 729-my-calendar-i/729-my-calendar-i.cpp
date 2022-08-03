class MyCalendar {
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto i:v){
            if(i.second >= end and i.first < end) return false;
            if(i.first<=start and i.second >= end) return false;
            if(i.first <= start and  i.second > start) return false;
            if(start < i.first and end > i.second) return false;
            // if(i.second == start or i.first == end) return false;
        }
        v.push_back({start,end});
        cout<<start<<" "<<end<<endl;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */