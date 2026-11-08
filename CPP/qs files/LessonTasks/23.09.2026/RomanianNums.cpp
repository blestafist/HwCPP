#include <cstddef>
#include <iostream>
#include <unordered_map>


static std::unordered_map<char, int> romanValues {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};


size_t stringSize(const std::string& roman) {
    size_t len = 0;
    while (roman[len] != '\0') {
        ++len;
    }
    return len;
}


bool isRomanValid (const std::string& roman, size_t strSize) {
    for (size_t i = 0; i < strSize; ++i) {
        bool flag = false;

        for (const auto& pair : romanValues) {
            char key = pair.first;
            if (roman[i] == key) { flag = true; break; }
        }
        if (!flag) { return false; }
    }
    return true;
}


int RomanToDecimal (const std::string& roman, size_t strSize) {
    int decimal = 0;

    for (size_t i = 0; i < strSize; ++i) {
        if (i + 1 < strSize && romanValues[roman[i]] < romanValues[roman[i + 1]] ) {
            decimal -= romanValues[roman[i]];
        } else {
            decimal += romanValues[roman[i]];
        }
    }
    return decimal;
}


int main() {
    std::string input = "MCMXCIV"; // Enter a Roman number here
    size_t strSize = stringSize(input);

    if (!isRomanValid(input, strSize)) {
        std::cout << "Enter correct num";
    } else {
        std::cout << RomanToDecimal(input, strSize);
    }

    return 0;
}
