/*
reader writeproblem: you have a shared resource.  
    multiple readers
    multiple writers.
    multiple readers can access the resource at once.
    where writer is writing , no other reader or writer should be allowed.

*/

#include<mutex>
#include<condition_variable>
#include<iostream>
#include<vector>
#include<thread>

int shared_data = 0;
std::mutex m;
std::condition_variable cv_reader;
std::condition_variable cv_writer;
bool writer_active;
int reader_count = 0;

void reader(int id) {
    std::unique_lock<std::mutex> lock(m);
    cv_reader.wait(lock, [] { return !writer_active; });
    reader_count++;
    std::cout << "reading buffer: " << id << " data: " << shared_data << std::endl;
    lock.unlock();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    lock.lock();
    --reader_count;
    if (reader_count == 0) {
        cv_writer.notify_all();
    }
    lock.unlock();
}

void writer(int id) {
    std::unique_lock<std::mutex> lock(m);
    cv_writer.wait(lock, [] { return (reader_count==0 && !writer_active); });
    writer_active=true;

    std::cout << "writing buffer: " << id << " data: " << shared_data << std::endl;
    shared_data += 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    writer_active=false;
    cv_writer.notify_all();
    cv_reader.notify_all();
}

int readers_number= 100;
int writers_number= 15;

int main() {
    std::vector<std::thread> readers;
    std::vector<std::thread> writers;

    for (int i = 0; i < writers_number; ++i ) {
        writers.emplace_back(writer, i);
    }
    for (int i = 0; i < readers_number; ++i ) {
        readers.emplace_back(reader, i);
    }


    //join
    for(auto& t : readers) {
        t.join();
    }
    for(auto& t : writers) {
        t.join();
    }
    return 0;
}
