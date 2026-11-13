#include <iostream>
#include <string>
#include <algorithm>

bool IsAutobiographic(int num) {
    int cp = num, pos = 0, digitsCount[10] {};

    while (cp > 0) {
        ++pos;
        digitsCount[cp % 10]++;
        cp /= 10;
    }

    while (num > 0) {
        if (digitsCount[pos - 1] != num % 10) { return false; }
        num /= 10;
        --pos;
    }

    return true;
}

bool IsAutobiographicSTL(int num) {
    std::string s = std::to_string(num);

    for (size_t i = 0; i < s.size(); ++i) {
        int digit = s[i] - '0';
        int cnt = std::count(s.begin(), s.end(), '0' + i);

        if (digit != cnt) { return false; }
    }

    return true;
}

int main() {
    size_t ctr = 0;
    for (int i = 10; i <= 10000; i++) {
        if (IsAutobiographic(i)) { std::cout << i << '\n'; ++ctr; }
    }

    std::cout << "\nIlość liczb: " << ctr << "\n";

    return 0;
}
