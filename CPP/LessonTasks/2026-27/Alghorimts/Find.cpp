#include <iostream>
#include <string>

static constexpr size_t npos = -1;


size_t FindString (const std::string& str1, const std::string& str2) {
    auto longer = str1.size() < str2.size() ? str2 : str1;
    auto shorter = str1.size() < str2.size() ? str1 : str2;

    for (size_t i = 0; i <= longer.size() - shorter.size(); ++i) {
        for (size_t j = 0; j < shorter.size(); ++j) {
            if (longer[i + j] != shorter[j]) { break; }
            if (j == shorter.size() - 1) { return i; }
        }
    }

    return npos;
}

int main () {
    std::string str1 = "aabaacabac";
    std::string str2 = "ca";

    std::cout << FindString(str1, str2);
    return 0;
}
