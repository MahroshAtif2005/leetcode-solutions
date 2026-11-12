class Foo {
public:
    Foo() {
        
    }
    int step = 0;
    mutex mtx;
    condition_variable cv;
    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        cv.notify_all();
        step++;
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        while(step!=1){
            cv.wait(lock);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        step++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        while(step!=2){
            cv.wait(lock);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};