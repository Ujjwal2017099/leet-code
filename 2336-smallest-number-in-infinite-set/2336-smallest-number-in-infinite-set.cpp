class SmallestInfiniteSet {
public:
    int sm=1;
    priority_queue<int,vector<int>,greater<int>> q;
    map<int,bool> m;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(q.empty()){
            return sm++;
        }
        int x=q.top();
        q.pop();
        m[x]=0;
        return x;
    }
    
    void addBack(int num) {
        if(num>=sm || m[num]) return;
        q.push(num);
        m[num]=1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */