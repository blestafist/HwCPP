#include <iostream>

long przestaw (long num) {
    int r = num % 100, a = r / 10, b = r % 10;

    // std::cout << "R: " << r << " a: " << a << " b: " << b;
    num = num / 100;
    long result;

    if (num > 0) {
        result = a + 10 * b + 100 * przestaw(num);
    } else {
        if (a > 0) {
            result = a + 10 * b;
        } else {
            result = b;
        }
    }

    return result;
}

unsigned long przestawI (unsigned long num) {
    unsigned long result = 0;
    int shift = 1;
    
    while (num > 0) {
        int copy = num;
        while (copy > 0) {
            if (copy < 10) {
                result += copy % 10;
                break;
            } else if (copy < 100) {
                int first = copy / 10;
                int second = copy % 10;

                result *= 100;
                result += second * 10 + first;
                break;
            }
        }   
    }

    return result;
}

int main () {
    std::cout << przestaw(1234) << "\n";
}
