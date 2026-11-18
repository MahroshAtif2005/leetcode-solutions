class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }

    binary_semaphore sem1{1};
    binary_semaphore sem2{0};

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem1.acquire();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem2.release();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem2.acquire();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem1.release();
        }
    }
};