#include <algorithm>    // std::count
#include <array>
#include <cstddef>
#include <iostream>
#include <string>


// ======================== CONFIGURATION ========================

constexpr size_t DECIMAL_DIGITS = 10;

// ===============================================================


size_t FillDigitOccurrences(size_t num, std::array<size_t, DECIMAL_DIGITS>& digitOccurrence) {
    size_t digits = 0;

    if (num == 0) { digitOccurrence[0] = 1; return 1; }
    while (num > 0) {
        ++digitOccurrence[num % 10];
        num /= 10;
        ++digits;
    }
    return digits;
}


[[nodiscard]] bool IsAutobiographic(size_t num, size_t size, const std::array<size_t, DECIMAL_DIGITS>& digitOccurrence) {
    if (num == 0) { return false; }
    size_t pos = size;
    while (num > 0) {
        if (digitOccurrence[--pos] != num % 10) { return false; }
        num /= 10;
    }
    return true;
}


bool IsAutobiographicSTL(size_t num) {
    std::string numStr = std::to_string(num);

    for (size_t i = 0; i < numStr.size(); ++i) {
        const int digit = numStr[i] - '0';
        const int actualCount = std::count(numStr.begin(), numStr.end(), i + '0');

        if (digit != actualCount) { return false; }
    }
    return true;
}


int main() {
    int counter = 0;
    for (size_t i = 10; i <= 10000; ++i) {
        std::array<size_t, DECIMAL_DIGITS> digitOccurrence {};
        const size_t size = FillDigitOccurrences(i, digitOccurrence);

        if (IsAutobiographic(i, size, digitOccurrence)) {
            std::cout << i << ' ';
            ++counter;
        }
    }
    std::cout << "\nIlość tych liczb: " << counter;
    return 0;
}