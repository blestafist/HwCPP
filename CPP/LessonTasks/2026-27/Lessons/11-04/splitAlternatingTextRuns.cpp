#include <iostream>
#include <fstream>
#include <cctype>
#include <cstddef>
#include <string>
#include <vector>


const std::string INPUT_FILE = "Input/dane3.txt";


std::vector<std::string> DelimString (const std::string& str) {
    std::string buffer = "";
    bool typeIsString = false;
    std::vector<std::string> result;

    if (std::isalpha(str[0])) {
        typeIsString = true;
    }

    for (size_t i = 0; i < str.size(); ++i) {
        if ((std::isalpha(str[i]) && typeIsString) || (!std::isalpha(str[i]) && !typeIsString)) {
            // no need to flush buffer
            buffer += str[i];
        } else {
            // flush the buffer
            result.push_back(buffer);
            buffer.clear();

            typeIsString = !typeIsString;
            buffer += str[i];
        }
    }

    result.push_back(buffer);
    return result;
}


int main () {
    std::ifstream inputFile (INPUT_FILE);
    
    std::string input;
    std::getline(inputFile, input);

    std::vector<std::string> res = DelimString(input);
    
    for (const auto& e : res) {
        std::cout << e << "\n";
    }

    return 0;
}
