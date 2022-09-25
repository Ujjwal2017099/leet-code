/**
 * @param {number} k
 */
let q;
let f=-1,r=-1;
let size=0,arrsize=0;
var MyCircularQueue = function(k) {
    q = new Array(k);
    arrsize = k;
    f=-1;r=-1;
    size=0;
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularQueue.prototype.enQueue = function(value) {
    if(MyCircularQueue.prototype.isFull()) return false;
    
    if(MyCircularQueue.prototype.isEmpty()){
        f=0;r=0;
        q[r] = value;
        size++;
        return true;
    }
    
    r++;
    r%=arrsize;
    size++;
    q[r] = value;
    return true;
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.deQueue = function() {
    if(MyCircularQueue.prototype.isEmpty()) return false;
    f++;
    f%=arrsize;
    size--;
    return true;
};

/**
 * @return {number}
 */
MyCircularQueue.prototype.Front = function() {
    if(size == 0) return -1;
    return q[f];
};

/**
 * @return {number}
 */
MyCircularQueue.prototype.Rear = function() {
    if(size == 0) return -1;
    return q[r];  
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.isEmpty = function() {
    return size == 0;
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.isFull = function() {
    return size == arrsize;
};

/** 
 * Your MyCircularQueue object will be instantiated and called as such:
 * var obj = new MyCircularQueue(k)
 * var param_1 = obj.enQueue(value)
 * var param_2 = obj.deQueue()
 * var param_3 = obj.Front()
 * var param_4 = obj.Rear()
 * var param_5 = obj.isEmpty()
 * var param_6 = obj.isFull()
 */