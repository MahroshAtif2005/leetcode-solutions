class H2O {
public:
    H2O() {
        
    }
    
    binary_semaphore hydrogenSem{1};
    binary_semaphore oxygenSem{0};

    int hydrogenCount = 0;

    void hydrogen(function<void()> releaseHydrogen) {
        hydrogenSem.acquire();
        releaseHydrogen();
        hydrogenCount++;
        if(hydrogenCount==2){
            hydrogenCount = 0;
            oxygenSem.release();
        }else{
            hydrogenSem.release();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        oxygenSem.acquire();
        releaseOxygen();
        hydrogenSem.release();
    }
};