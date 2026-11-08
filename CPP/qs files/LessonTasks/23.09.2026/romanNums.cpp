#include <iostream>
#include <string>


int romanCharValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;
    }
}


bool isRomanValid(const std::string& roman) {
    for (char c : roman) {
        if (romanCharValue(c) == -1) { return false; }
    }
    return true;
}


int romanToDecimal(const std::string& roman) {
    int decimal = 0;
    for (size_t i = 0; i < roman.size(); ++i) {
        int curr = romanCharValue(roman[i]);
        int next = (i + 1 < roman.size()) ? romanCharValue(roman[i + 1]) : 0;

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
