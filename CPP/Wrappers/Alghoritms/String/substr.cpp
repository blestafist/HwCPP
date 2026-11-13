#include <string>

// Just use std::string.substr(pos, len), in case you can't:

std::string SubStr(const std::string& str, size_t pos, size_t len) {
    if (pos > str.size()) { return ""; }

    if (len == std::string::npos) {
        len = str.size() - pos;
    }

    else {
        len = std::min(len, str.size() - pos);
    }

    std::string result;
    result.reserve(len);

    for (size_t i = pos; i < pos + len; i++) {
        result += str[i];
    }

    return result;
}
