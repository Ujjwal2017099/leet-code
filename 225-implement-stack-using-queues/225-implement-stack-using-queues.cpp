class MyStack {
public:
    stack<int> s;
    MyStack() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        int t = s.top();
        s.pop();
        return t;
    }
    
    int top() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};