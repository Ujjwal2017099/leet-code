class MyHashSet {
bool a[1000001] = {false};
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        a[key] = true;
    }
    
    void remove(int key) {
        a[key] = false;
    }
    
    bool contains(int key) {
        return a[key];
    }
};
