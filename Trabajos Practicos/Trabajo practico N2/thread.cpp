#include "thread.h"
#include <utility>

Thread::Thread() {}

void Thread::start(){
    thread = std::thread(&Thread::run, this);
}

void Thread::join(){
    if (thread.joinable()) {
        thread.join();
    }
}

Thread::~Thread() {}
