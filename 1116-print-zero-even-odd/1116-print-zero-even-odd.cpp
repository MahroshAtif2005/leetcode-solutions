class ZeroEvenOdd {
private:
    int n;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    binary_semaphore zeroSem{1}; //i want it to start with 0
    binary_semaphore evenSem{0};
    binary_semaphore oddSem{0};

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
         for(int i = 1; i<=n; i++){
            zeroSem.acquire();
            printNumber(0);
            if(i%2==1){
                oddSem.release();
            }else{
                evenSem.release();
            }
         }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i<=n; i+=2){
            evenSem.acquire();
            printNumber(i);
            zeroSem.release();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i<=n; i+=2){
            oddSem.acquire();
            printNumber(i);
            zeroSem.release();
        }
    }
};