#include <algorithm>
#include <iostream>
#include <string>


std::string IntToStr(long long num) {
    if (num == 0) { return "0"; }

    std::string res = "";
    while (num > 0) {
        res += (num % 10) + '0';
        num /= 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}


int StringToInt(const std::string& str) {
    int res = 0;
    for (char c : str) {
        res *= 10;
        res += c - '0';
    }
    return res;
}


bool IsKaprekar(const int num, const std::string& square) {
    for (size_t i = 1; i < square.size(); ++i) {
        std::string left = square.substr(0, i);
        std::string right = square.substr(i, square.size() - i);

        int leftInt = StringToInt(left);
        int rightInt = StringToInt(right);

        if (leftInt + rightInt == num) { return true; }
    }

    return false;
}


int main() {
    int counter = 0;
    for (int i = 10; i <= 1000; ++i) {
        long long square = static_cast<long long>(i) * i;

        if (IsKaprekar(i, IntToStr(square))) {
            std::cout << i << '\n';
            ++counter;
        }
    }
    std::cout << "\nIlość liczb: " << counter;
    return 0;
}