class FizzBuzz {
private:
    int n;

public:
    FizzBuzz(int n) {
        this->n = n;
    }
    
    binary_semaphore numSem{1};
    binary_semaphore fizzSem{0};
    binary_semaphore buzzSem{0};
    binary_semaphore fizzBuzzSem{0};

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i = 1; i<=n; i++){
            if(i%3==0 && i%5!=0){
            fizzSem.acquire();
             printFizz();
             numSem.release();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
      for(int i = 1; i<=n; i++){
        if(i%3!=0 && i%5==0){
        buzzSem.acquire();
        printBuzz();
        numSem.release();
        }
    }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i = 1; i<=n; i++){
         if(i%3==0 && i%5==0){
          fizzBuzzSem.acquire();
          printFizzBuzz();
          numSem.release();
         }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i = 1; i<=n; i++){
            numSem.acquire();
            if(i%3==0 && i%5==0){
                fizzBuzzSem.release();
            }else if(i%3==0){
                fizzSem.release();
            }else if(i%5==0){
               buzzSem.release();
            }else{
                printNumber(i);
                numSem.release();
            }
        }
    }
};