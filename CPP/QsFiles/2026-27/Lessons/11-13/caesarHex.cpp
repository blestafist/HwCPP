#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>


constexpr std::string_view DIGITS = "0123456789ABCDEF";
constexpr int BASE = 16;
constexpr int SHIFT = 3;


// Time complexity: O(log n) - division by 16
// Space complexity: O(log n) - stores base-16 digits
std::string DecToHex(unsigned long long decimal) {
    if (decimal == 0) { return "0"; }
    std::string result;
    while (decimal > 0) {
        result += DIGITS[decimal % BASE];
        decimal /= BASE;
    }
    std::reverse(result.begin(), result.end());
    return result;
}


// Time complexity: O(L) - loop through the string (L - string size)
// Space complexity: O(1)
void EncryptCaesar(std::string& hex) {
    for (char& c : hex) {
        int currIdx = static_cast<int>(DIGITS.find(c));
        int newIdx = (currIdx + SHIFT) % BASE;
        c = DIGITS[newIdx];
    }
}


// Time complexity: O(L)
// Space complexity: O(1)
void DecryptCaesar(std::string& hex) {
    for (char& c : hex) {
        int currIdx = static_cast<int>(DIGITS.find(c));
        int newIdx = (currIdx - SHIFT + BASE) % BASE;
        c = DIGITS[newIdx];
    }
}


int main() {
    unsigned long long num = 5423534;    // Enter your number here
    std::string hex = DecToHex(num);

    auto Print = [](auto&&... args) { (std::cout << ... << args) << '\n'; };

    Print("liczba ", num, " w systemie szesnastkowym: ", hex);

    EncryptCaesar(hex);
    Print("zaszyfrowana liczba: ", hex);

    DecryptCaesar(hex);
    Print("odszyfrowana liczba: ", hex);

    return 0;
}
