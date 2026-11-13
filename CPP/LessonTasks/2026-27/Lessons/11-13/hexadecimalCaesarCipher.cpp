#include <iostream>
#include <cstddef>
#include <cstdint>
#include <string>
#include <array>


static constexpr uint8_t nullpos = 255;
static constexpr std::array<char, 16> vals = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};


std::string ConvertToHex (unsigned long long decimal) {
    if (decimal == 0) return "0";

    
    std::string result = "";
    const uint8_t base = 16;

    while (decimal > 0) {
        result = vals[decimal % base] + result;
        decimal /= base;
    }

    return result;
}


uint8_t FindInVals (char c) {
    for (size_t i = 0; i < vals.size(); ++i) {
        if (c == vals[i]) {
            return i;
        }
    }

    return nullpos;
}


void CryptCesar (std::string& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        uint8_t normalised = FindInVals(str[i]);
        normalised = (normalised + 3) % vals.size();
        str[i] = vals[normalised];
    }
}


void DecryptCesar (std::string& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        uint8_t normalised = FindInVals(str[i]);
        normalised = (normalised - 3 + vals.size()) % vals.size();
        str[i] = vals[normalised];
    }
}


int main () {
    unsigned long long input = 14819917481248;
    std::string str = ConvertToHex(input);
    std::cout << str << "\n";
    CryptCesar(str);

    std::cout << str << "\n";

    DecryptCesar(str);
    std::cout << str << "\n";
}
