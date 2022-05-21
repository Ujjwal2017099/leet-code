#define int long long
const int sz = 3e4 + 1;
class MinStack {
    vector<int> mn;
    int st[sz];
    int tp;
public:
    MinStack() {
        tp = 0;
    }
    
    void push(int val) {
        if(mn.empty()) mn.push_back(val);
        else if(mn.back() >= val) mn.push_back(val);
        st[tp] = val;
        tp++;
    }
    
    void pop() {
        --tp;
        if(st[tp] == mn.back()) mn.pop_back();
    }
    
    int top() {
        return st[tp-1];
    }
    
    int getMin() {
        return mn.back();
    }
};
#undef int