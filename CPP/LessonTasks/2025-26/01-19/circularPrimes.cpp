#include <cmath>
#include <iostream>


bool IsPrime(short num) { // Most optimised IsPrime
    if (num == 2) { return true; } // 2 is the only even prime num
    if (num < 2 || num % 2 == 0) { return false; } // exclude < 2 and even nums (2 -> prev line)

    for (char i = 3; i * i <= num; i += 2) { // char limit is 255, but max of var is 32 (31.6) :)
        if (num % i == 0) { return false; } // checking only !even nums
    }

    return true;
}

bool CircularNumPrime(short num) {
    unsigned char digits;

    auto countDigits = [](short num) -> unsigned char {
        unsigned char counter = 0;

        while (num > 0) {
            num /= 10;
            counter++;
        }

        return counter;
    };

    digits = countDigits(num); // count digits in num
    if (digits < 2) { return true;} // if num is 1 dig long && IsPrime return true

    for (int i = 1; i < digits; i++) {
        num += (num % 10) * (int)(std::pow(10, digits));
        num /= 10;
        if (!IsPrime(num)) { return false; }
    }

    return true;
}


int main() { // Program entry point
    short counter = 0;

    for (short i = 1; i <= 1000; i++) {
        if (IsPrime(i)) {
            if (CircularNumPrime(i)) { counter++; }
        }
    }

    std::cout << counter << std::endl;

    return 0;
}