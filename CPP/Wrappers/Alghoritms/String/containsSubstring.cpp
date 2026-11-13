#include <string>

bool ContainsSubstringFull(const std::string& str1, const std::string& str2) {
    if (str1.size() < str2.size()) { return false; }
    size_t maxLen = str1.size() - str2.size() + 1;

    for (size_t shift = 0; shift < maxLen; shift++) {
        bool match = true;
        for (size_t i = 0; i < str2.size(); i++) {
            if (str1[shift + i] != str2[i]) { match = false; break; }
        }

        if (match) { return true; }
    }

    return false; 
}

bool ContainsSubstringShort(const std::string& str1, const std::string& str2) {
    return str1.find(str2) != std::string::npos;
}
