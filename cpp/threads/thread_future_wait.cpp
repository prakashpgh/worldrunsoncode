#include <iostream>
#include <mutex>
#include <vector>
#include <future>
#include <thread>

bool dataloader(int i)
{
    std::cout << "in the data_loader " << i << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(i));
    return true;
}

int main()
{
    std::future<bool> f = std::async(&dataloader, 10);

    while (true)
    {
        std::cout << "in the main thread " << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::future_status fs = f.wait_for(std::chrono::seconds(1));
        if (fs == std::future_status::ready)
        {
            std::cout << "dataloader ready..." << std::endl;
            break;
        }
        else
        {
            std::cout << "dataloader NOT yet ready..." << std::endl;
        }
    }

    int sq = f.get();
    std::cout << "result: " << sq << std::endl;
}
