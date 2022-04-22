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
