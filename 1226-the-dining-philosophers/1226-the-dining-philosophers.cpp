class DiningPhilosophers {
public:
    DiningPhilosophers() {
        
    }
    mutex forks[5];
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

     int left = philosopher;
     int right = (philosopher + 1) % 5;

     scoped_lock lock(forks[left],forks[right]);

     pickLeftFork();
     pickRightFork();

     eat();

     putLeftFork();
     putRightFork();
    }
};