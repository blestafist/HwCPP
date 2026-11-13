#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


// =========================== CONFIGURATION =========================

const std::string INPUT_FILE_NAME = "liczby.txt";
const std::string OUTPUT_FILE_NAME = "zadanie6.txt";

// ===================================================================


int BinaryToDecimal (const std::string& word) {
    long long decimal = 0;
    for (char c : word) {
        decimal = (decimal << 1) + (c - '0');
    }
    return decimal;
}


std::string DecimalToBinary (long long num) {
    if (num == 0) return "0";

    std::string binary = "";
    while (num > 0) {
        int remainder = num & 1;    // Remainder (bit mask)
        binary += (remainder + '0');     // Convert int to char
        num >>= 1;
    }
    std::reverse(binary.begin(), binary.end());
    return binary;
}


int main() {
    std::ifstream fIn(INPUT_FILE_NAME);
    if (!fIn) { std::cerr << "ERROR: File " << INPUT_FILE_NAME << " not found" << std::endl; return 1; }

    std::ofstream fOut(OUTPUT_FILE_NAME);
    if (!fOut) { std::cerr << "ERROR: Could not create output file" << std::endl; return 1; }

    std::string word, largestBin = "";

    int evenCounter = 0,
    nineDigitsCounter = 0,
    largestDecValue = 0;
    long long sumDecValue = 0;    // Sum of decimal values in numbers with 9 digits

    while (fIn >> word) {
        if (word.back() == '0') { evenCounter++; }

        int currDec = BinaryToDecimal(word);
        if (largestDecValue < currDec) { largestDecValue = currDec; largestBin = word; }

        if (word.size() == 9) { nineDigitsCounter++; sumDecValue += currDec; }
    }

    auto Print = [&] (auto&& ... args) { (std::cout << ... << args) << '\n'; (fOut << ... << args) << '\n'; };

    Print("a\nliczb parzystych: ", evenCounter);
    Print("b\nNajwiększe słowo binarne: ", largestBin, " jej wartość w systemie dziesiętnym: ", largestDecValue);
    Print("c\nIlość liczb mająca 9 cyfr ", nineDigitsCounter, " suma tych liczb w systemie dwójkowym: ", DecimalToBinary(sumDecValue));
    
    return 0;
}