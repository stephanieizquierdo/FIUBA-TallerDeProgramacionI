#include "mutex.h"
#include <mutex>

Lock::Lock(std::mutex &m) : m(m) {
    m.lock();
}

Lock::~Lock() {
    m.unlock();
}
