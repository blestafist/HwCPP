#include <fstream>
#include <iostream>
#include <string>
#include <vector>


const std::string STRING_FILE = "trening_file1.txt";
const std::string INT_FILE = "trening_file2.txt";


struct Item{
    std::string text;
    int value;
};


int main() {
    std::ifstream stringFile(STRING_FILE);
    if (!stringFile) { std::cerr << "ERROR: Could not open file: " << STRING_FILE << std::endl; return 1; }

    std::ifstream intFile(INT_FILE);
    if (!intFile) { std::cerr << "ERROR: Could not open file: " << INT_FILE << std::endl; return 1; }

    std::vector<Item> items;

    std::string word;
    int num;
    while (stringFile >> word && intFile >> num) {
        items.push_back({word, num});
    }

    for (const auto& [text, num] : items) {
        std::cout << text << ' ' << num << '\n';
    }

    return 0;
}

