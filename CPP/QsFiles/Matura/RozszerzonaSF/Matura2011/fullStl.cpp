#include <iostream>
#include <fstream>
#include <string>
#include <charconv>
#include <system_error>


// =========================== CONFIGURATION =========================

const std::string INPUT_FILE_NAME = "liczby.txt";
const std::string OUTPUT_FILE_NAME = "zadanie6.txt";

// ===================================================================


std::string DecimalToBinary (long long num) {
    char buf[65];   // 64 bits + 1 for '\0'
    auto res = std::to_chars(buf, buf + 64, num, 2);

    if (res.ec == std::errc()) {
        return std::string(buf, res.ptr);
    }

    return "0";
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

        int currDec = std::stoi(word, nullptr, 2);
        if (largestDecValue < currDec) { largestDecValue = currDec; largestBin = word; }

        if (word.size() == 9) { nineDigitsCounter++; sumDecValue += currDec; }
    }

    auto Print = [&] (auto&& ... args) { (std::cout << ... << args) << '\n'; (fOut << ... << args) << '\n'; };

    Print("a\nliczb parzystych: ", evenCounter);
    Print("b\nNajwiększe słowo binarne: ", largestBin, " jej wartość w systemie dziesiętnym: ", largestDecValue);
    Print("c\nIlość liczb mających 9 cyfr: ", nineDigitsCounter, ", suma tych liczb w systemie dwójkowym: ", DecimalToBinary(sumDecValue));
    
    return 0;
}