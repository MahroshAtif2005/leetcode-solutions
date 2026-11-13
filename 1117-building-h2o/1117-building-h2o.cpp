class H2O {
public:
    H2O() {
        
    }
    mutex mtx;
    condition_variable cv;

    int hydrogenCount = 0;
    int oxygenCount = 0;

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        while(hydrogenCount == 2){ //If two hydrogen atoms have already printed for the current molecule, the next hydrogen thread must wait.
            cv.wait(lock);
        }
        hydrogenCount++;
        releaseHydrogen();

        if(hydrogenCount == 2 && oxygenCount ==1){
            hydrogenCount = 0;
            oxygenCount = 0;
        }

        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);

        while (oxygenCount==1){
            cv.wait(lock);
        }

        oxygenCount++;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

          if (hydrogenCount == 2 && oxygenCount == 1) {
            hydrogenCount = 0;
            oxygenCount = 0;
        }
        cv.notify_all();
    }
};