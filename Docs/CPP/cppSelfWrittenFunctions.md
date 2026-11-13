# Basic functions in C++ (self-written)

bool IsPrime(int num) { // 1
    if (num == 2 || num == 3) { return true; }
    if (num % 2 == 0 || num % 3 == 0 || num < 2) { return false; }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) { return false; }
    }
    
    return true;

}


int SumDigitsBin(int num) {
    int result = 0;
    while (num > 0) { result += num % 2; num /= 2; }

    return result;
}


int SumDigitsPrime(int num) {
    int result = 0;
    while (num > 0) { result += num % 10; num /= 10; }

    return result;
}


bool SumDigitsPrime(int num) {
    int result = 0;
    while (num > 0) { result += num % 10; num /= 10; }

    return IsPrime(result);
}


bool SumDigitsPrimeBin(int num) {
    int result = 0;
    while (num > 0) { result += num % 2; num /= 2; }

    return IsPrime(result);
}


bool IsSuperB(int num) {
    return IsPrime(num) && SumDigitsPrimeBin(num);
}


bool IsPalindrome(const std::string& str) {
    for (size_t i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i]) { return false; }
    }

    return true;
}


void ReverseString(std::string& str) {
    char temp;

    for (short i = 0; i < str.size() / 2; i++) {
        temp = str[i];
        str[i] = str[str.size() - i - 1];
        str[str.size() - i - 1] = temp;
    }
}


std::string ComposeW2(const std::string& origin) {
    int w1Len = 1;

    for (int i = origin.size(); i >= 1; i--) {
        if (IsPalindrome(origin, i)) { w1Len = i; break; }
    }

    std::string result = "";
    for (int i = origin.size() - 1; i >= w1Len; i--) {
        result += origin[i];
    }

    return result;
}


bool ContainsSubstring(const std::string& a, const std::string& b) {
    if (b.size() > a.size()) { return false; }
    int maxLen = a.size() - b.size() + 1;

    for (size_t i = 0; i < maxLen; i++) {
        bool match = true;

        for (size_t j = 0; j < b.size(); j++) {
            if (a[i + j] != b[j]) { match = false; break; }
        }

        if (match) { return true; }
    }

    return false;
}


bool ContainsSubstringShort(const std::string& a, const std::string& b) {
    return a.find(b) != std::string::npos;
}


bool Match(const std::string& a, const std::string& b, int offset) {
    for (int i = 0; i + offset < a.size() && i < b.size(); i++) {
        if (a[i + offset] != b[i]) { return false; }
    }

    return true;
}


std::string MergeWithOverlap(const std::string& first, const std::string& second) {
    int maxOverlap = 0;
    
    for (int i = 1; i <= first.size() && i <= second.size(); i++) {
        bool matches = true;
        
        for (int j = 0; j < i; j++) {
            if (first[first.size() - i + j] != second[j]) {
                matches = false;
                break;
            }
        }
        
        if (matches) { maxOverlap = i; }
    }
    
    std::string result = first;
    for (size_t i = maxOverlap; i < second.size(); i++) {
        result += second[i];
    }
    
    return result;
}


bool More0Than1(const std::string& str) {
    char occ = 0;

    for (char c : str) {
        if (c == '0') { occ++; } else { occ--; }
    }

    return occ > 0;
}


bool TwoBlocksContainer(const std::string& str) {
    if (str[0] != '0' || str[str.size() - 1] != '1') { return false; }
    bool wasChange = false;

    for (unsigned char i = 0; i < str.size() - 1; i++) {
        if (str[i] != str[i + 1]) { 
            if (wasChange) { return false; }
            wasChange = true;
        }
    }

    return wasChange;
}


char CountLongest0Occ(const std::string& str) {
    char occ = 0, maxOcc = 0;
    for (char c : str) {
        if (c == '0') { occ++; if (occ > maxOcc) { maxOcc = occ; } } else { occ = 0; }
    }

    return maxOcc;
}


