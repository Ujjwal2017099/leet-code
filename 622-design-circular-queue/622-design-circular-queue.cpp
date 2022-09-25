class MyCircularQueue {
public:
    vector<int> q;
    int f=-1,r=-1;
    int size=0,arrsize=0;
    MyCircularQueue(int k) {
        q.resize(k);
        arrsize = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return 0;
        if(isEmpty()){
            f=0;r=0;
            q[r] = value;
            size++;
            return 1;
        }
        size++;
        r++;
        r%=arrsize;
        q[r] = value;
        return 1;
    }
    
    bool deQueue() {
        if(isEmpty()) return 0;
        
        f++;f%=arrsize;
        size--;
        return 1;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[f];   
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[r];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == arrsize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */