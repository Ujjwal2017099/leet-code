class Foo {
public:
    vector<int> t;
    Foo() {
        t.resize(3,0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        t[0]=1;
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        while(t[0]==0){}
        printSecond();
        t[1]=1;
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        while(t[1]==0){}
        printThird();
    }
};