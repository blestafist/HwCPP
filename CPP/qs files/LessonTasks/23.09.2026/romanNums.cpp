#include <iostream>
#include <string>
#include <unordered_map>


static const std::unordered_map<char, int> romanValues {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};


bool isRomanValid(const std::string& roman) {
    for (char c : roman) {
        if (romanValues.count(c) == 0) { return false; }
    }
    return true;
}


int romanToDecimal(const std::string& roman) {
    int decimal = 0;
    for (size_t i = 0; i < roman.size(); ++i) {
        int curr = romanValues.at(roman[i]);
        int next = (i + 1 < roman.size()) ? romanValues.at(roman[i + 1]) : 0;

        if (curr < next) {
            decimal -= curr;
        } else {
            decimal += curr;
        }
    }
    return decimal;
}


int main() {
    std::string input = "MCMXCIV"; // Enter a Roman number here

    if (!isRomanValid(input)) {
        std::cout << "Enter correct num";
    } else {
        std::cout << romanToDecimal(input);
    }

    return 0;
}
