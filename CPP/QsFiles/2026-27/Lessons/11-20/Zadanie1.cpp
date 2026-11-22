#include <iostream>


int counter = 0;    // elementarne wykonania


int wynik(int i) {
    if (i < 3) {
        ++counter;
        return 1;
    } else {
        if (i % 2 == 0) {
            return wynik(i - 3) + wynik(i - 1) + 1;
        } else {
            return wynik(i - 1) % 7;
        }
    }
}


int main() {
    /* for (int i = 2; i <= 8; ++i) {
        std::cout << wynik(i) << ' ';
    } */

    int i = 10;
    wynik(i);

    std::cout << counter;

    return 0;
}

/*
    1.1 - 1, 1, 3, 3, 5, 5, 9
    1.2 - 1, 1, 2, 3, 5, 8
    E(i - 3) + E(i - 1)
    E(i - 1)

    1.3 -
    W[0] <- 1
    W[1] <- 1
    W[2] <- 1
    max_wart <- 1
    dla i = 3, 4 ..., 1000 wykonuj
        jezeli i mod 2 = 0
            W[i] <- W[i-3] + W[i-1] + 1
        w przeciwnym razie
            W[i] <- W[i - 1] mod 7
        jezeli W[i] > max_wart
            max_wart <- W[i]
    zwroc max_wart
 */
