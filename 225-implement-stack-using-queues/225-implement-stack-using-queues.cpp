class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    void push(int x) {
        queue<int> empty;
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        q2 = q1;
        swap(q1,empty);
    }
    
    int pop() {
        int t = q2.front();
        q2.pop();
        return t;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        return q2.empty();
    }
};