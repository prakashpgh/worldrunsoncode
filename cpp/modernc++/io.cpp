/* */

#include <iostream>
#include <limits>
#include<string>
#include<sstream>


void test_read_from_console() {
    std::string line;
    std::cin.clear(); // Clear error flags if any
    std::getline(std::cin, line);
    std::cout << line << std::endl;
    
    std::stringstream ss(line);
    std::string item;
    std::cout << "printing items " << std::endl;
    while (ss >> item) {
        std::cout << item << ",";
    }
    std::cout << std::endl;


    std::string word;
    std::cin >> word; // Reads until whitespace
    std::cout << "Parsed word: " << word << std::endl;

    // Clear the input buffer before getline
    std::cin.clear(); // Clear error flags if any
    int number;
    std::cin >> number;
    std::cout << "You entered: " << number << std::endl;


    // Parse into vector
    std::cin.clear(); // Clear error flags if any
    
}

#include<string>
#include<vector>

void read_multiple_lines() {
    std::string line;
    std::vector<std::string> lines;

    std::cout << "Enter lines of text (press Ctrl+D or Ctrl+Z then Enter to finish):\n";

    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }

    std::cout << "\n--- You entered the following lines: ---\n";
    for (const auto& l : lines) {
        std::cout << l << std::endl;
    }
}


void read_N_lines() {
    int num_lines;
    std::cin >> num_lines;
    std::cin.ignore(); // Consume the newline character left by std::cin >> num_lines

    std::vector<std::string> lines(num_lines);

    for (int i = 0; i < num_lines; ++i) {
        std::getline(std::cin, lines[i]);
    }

    std::cout << "\n--- You entered the following lines: ---\n";
    for (const auto& l : lines) {
        std::cout << l << std::endl;
    }
}


#include <algorithm>
#include <cctype>

void parse_input() {
    std::string line;
    //std::cout << "Enter comma-separated values (e.g., apple, banana, orange): ";
    std::getline(std::cin, line);

    // Parse into items
    std::vector<std::string> items;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, ',')) {
        //item = item.trim(); // Remove leading/trailing spaces
        std::cout << item << std::endl;
        if (!item.empty()) {
            items.push_back(item);
        }
    }
}

void parse_input_2 () {
    std::string csv_line = "value1,value2,another value,last_value";
    std::istringstream iss(csv_line);
    std::string segment;
    std::vector<std::string> values;

    while (std::getline(iss, segment, ',')) {
        values.push_back(segment);
    }

    std::cout << "Values from CSV line:" << std::endl;
    for (const auto& value : values) {
        std::cout << "[" << value << "] ";
    }
    std::cout << std::endl;
}

void test_cout() {
    //std::setw, 
    // std::setprecision

}


int main() {
    //test_read_from_console();

    //read_multiple_lines();

    read_N_lines();

    //parse_input();

    return 0;
}




 // Trim leading whitespace
std::string ltrim(const std::string& s) {
    auto it = std::find_if(s.begin(), s.end(), [](char c){ return !std::isspace(c); });
    return std::string(it, s.end());
}

// Trim trailing whitespace
std::string rtrim(const std::string& s) {
    auto it = std::find_if(s.rbegin(), s.rend(), [](char c){ return !std::isspace(c); });
    return std::string(s.begin(), it.base());
}

// Trim leading and trailing whitespace
std::string trim(const std::string& s) {
    return ltrim(rtrim(s));
}

// In-place versions (modify the original string)
std::string& ltrim_inplace(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](char c){ return !std::isspace(c); }));
    return s;
}

std::string& rtrim_inplace(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](char c){ return !std::isspace(c); }).base(), s.end());
    return s;
}
