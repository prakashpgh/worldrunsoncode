/**
 thread
    creation of thread
    1) function
    2) functor
    3) lambda

mutex... lock,unlock

lock_guard<std::mutex>  => simple rAII
unique_lock<std::mutex> => you can create & defer locking,  use with condition varaible, move ownership

condition variable   => wait(lock, [] { })
                     notifyall, notifyone
                     
std::async
std::future

std::promise

std::atomic

std::atomic_thread_fence()


Producer consumer problem
Reader Write problem
Cancel a running thread
Spurious wake up surprise
Thread pool

 * 
 */