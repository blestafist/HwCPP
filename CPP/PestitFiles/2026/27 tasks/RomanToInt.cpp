#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>

static const std::unordered_map<char, int> values = {
    { 'I', 1 },
    { 'V', 5 },
    { 'X', 10 },
    { 'L', 50 },
    { 'C', 100 },
    { 'D', 500 },
    { 'M', 1000 }
};


bool IsInputValid (const std::string& roman) {
    for (char c : roman) {
        if (!values.count(c)) { return false; }
    }

    return true;
}


int RomanToInt (const std::string& roman) {
    if (!IsInputValid(roman)) { throw std::invalid_argument("Invalid roman numeral: " + roman); }
    int result = 0;

    for (size_t i = 0; i < roman.size(); ++i) {
        int current = values.at(roman[i]);

        // comparing to a right neightboor
        if (i + 1 < roman.size() && values.at(roman[i + 1]) > current) {
            result -= current;
        } else { result += current; }
    }

    return result;
}


int main() {
    std::string input;
    std::cin >> input;

    std::cout << RomanToInt(input);
    return 0;
}
