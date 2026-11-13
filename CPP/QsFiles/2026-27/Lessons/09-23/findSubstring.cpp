#include <iostream>
#include <string>


size_t findSubstring(const std::string& str1, const std::string& str2) {
    size_t len1 = str1.size();
    size_t len2 = str2.size();

    const std::string& shorter = (len1 <= len2) ? str1 : str2;
    const std::string& longer = (len1 <= len2) ? str2 : str1;

    if (shorter.empty()) { return 0; }

    for (size_t i = 0; i <= longer.size() - shorter.size(); ++i) {
        size_t j = 0;
        for (; j < shorter.size(); ++j) {
            if (longer[i + j] != shorter[j]) { break; }
        }
        if (j == shorter.size()) { return i; }
    }
    return std::string::npos;
}


int main() {
    std::string str1 = "ala";
    std::string str2 = "43al12saalakqqqqala";

    std::cout << findSubstring(str1, str2);

    return 0;
}



