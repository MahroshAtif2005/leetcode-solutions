class Foo {
public:
    Foo() {
        
    }

    binary_semaphore sem1{0}; //initialise counter to 0
    binary_semaphore sem2{0};

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem1.release();
    }

    void second(function<void()> printSecond) {
        sem1.acquire();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem2.release();
    }

    void third(function<void()> printThird) {
        sem2.acquire();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};