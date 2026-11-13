#include <iostream>
#include <cstdint>

std::string Converter(int decimalNum, uint8_t sys) {
    if (decimalNum == 0) return "0";
    
    std::string result = "";
    
    while (decimalNum > 0) {
        int remainder = decimalNum % sys;
        char currentChar;
        
        if (remainder < 10) {
            currentChar = remainder + '0';
        } else {
            currentChar = remainder - 10 + 'A';
        }
        
        result = currentChar + result;
        decimalNum /= sys;
    }
    
    return result;
}

int main() {
    uint8_t base = 2;
    int numberToConvert = 4;

    
    std::cout << "\n\nResult: " << Converter(numberToConvert, base) << std::endl;
    
    return 0;
}