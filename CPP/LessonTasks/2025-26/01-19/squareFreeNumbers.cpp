#include <iostream>

bool IsCorrect(short num) {
    short lastDiv = -1, currentDiv = 2;

    while (num != 1) {
        if (num % currentDiv == 0) {
            if (lastDiv == currentDiv) { return false;}
            num /= currentDiv;
            lastDiv = currentDiv;
        }

        else { currentDiv++; }
    }

    return true;
}

int main() { // Program entry point
    short counter = 0;
    for (short i = 1; i <= 1000; i++) {
        if (IsCorrect(i)) { counter++; }
    }

    std::cout << counter << std::endl;

    return 0;
}