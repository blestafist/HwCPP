/*
Problem: Write out all the nums <1; 10000> which each permutation is Prime

1. Check if number is prime, then convert it into std::string
2. Check if number has an even number or 5(so 1 of permutation'll be with 0 at the end → num is non-prime or if)
3. If not, check all the permutations IsPrime
4, Print the result of counter
*/

#include <iostream>
#include <algorithm> //! for next_permutation and sort
#include <string>

bool IsPrime(unsigned short num) { // max is 10000, none of permutation > 32768
    if (num == 2) { return true; }
    if (num < 2 || num % 2 == 0) { return false; }

    for (short i = 3; i * i <= num; i+= 2) {
        if (num % i == 0) { return false; }
    }

    return true;
}

bool IsValid(const std::string& str) {
    const char notEvenNums[6] = {'0', '2', '4', '5', '6', '8'};

    for (char c : str) {
        for (char badC : notEvenNums) {
            if (c == badC) { return false; }
        }
    }

    return true;
}


int main() { // entry point
    short counter = 0;

    for (short i = 1; i <= 10000; i++) {
        if (IsPrime(i)) {
            if (i < 10) { counter++; continue; } // next operations on num >= 10
            std::string sNum = std::to_string(i);

            if (IsValid(sNum)) {
                std::sort(sNum.begin(), sNum.end());

                bool allPrime = true;

                do {
                    if (!IsPrime(std::stoi(sNum))) { allPrime = false; break; }
                } while (std::next_permutation(sNum.begin(), sNum.end()));

                if (allPrime) { counter++; }
            }
        }
    }

    std::cout << counter << std::endl;

    return 0;
}

