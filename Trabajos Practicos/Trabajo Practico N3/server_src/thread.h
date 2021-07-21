#ifndef THREAD_H
#define THREAD_H

#include <thread>

class Thread {
    private:
        std::thread thread;

    public:
        Thread();
        void start();
        void join();
        
        virtual void run() = 0;
        virtual ~Thread() = 0;

        Thread(const Thread&) = delete;
        Thread& operator=(const Thread&) = delete;

        Thread(Thread&& other);
        Thread& operator=(Thread&& other);
};

#endif /* THREAD_H */
