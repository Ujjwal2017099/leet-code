class MyHashMap {
public:
    int arr[1000007][2] = {{0}};
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        arr[key][0] = 1;
        arr[key][1] = value;
    }
    
    int get(int key) {
        if(arr[key][0] == 0)return -1;
        
        return arr[key][1];
    }
    
    void remove(int key) {
        arr[key][0] = 0;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */