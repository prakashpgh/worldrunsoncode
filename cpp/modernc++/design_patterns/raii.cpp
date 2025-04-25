#include <iostream>
#include <fstream>

class FileManager {
public:
    FileManager(const std::string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~FileManager() {
        if (file.is_open()) {
            file.close();
        }
    }

    void write(const std::string& data) {
        if (file.is_open()) {
            file << data;
        }
    }

private:
    std::ofstream file;
};

int main() {
    try {
        FileManager fileManager("example.txt");
        fileManager.write("Hello, RAII!");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}