#include <iostream>


void binary(double x, int k) {
    // std::cout << "0,";
    double y = x;


    for (int i = 1; i <= k; ++i) {
        // std::cout << y << ' ';
        if (y >= 0.5) {
            // std::cout << "1";
        } else {
            // std::cout << "0";
        }
        y = y * 2;
        if (y >= 1) {
            y = y - 1;
        }
    }
    std::cout << y;
}


int main() {
    double x = 0.0625;
    int k = 4;

    binary(x, k);

    return 0;
}

/*
    2.1 - 0,6; 0,2; 0,4; 0,8; 0,6
    liczba: 0,10011

    2.2 - 1/16
    2.3 -
    funkcja trojkowy(x, k)
        wypisz "0,"
        y <- x
        dla i = 1, 2, ..., k wykonuj
            jezeli y >= 2/3
                wypisz "2"
            jezeli y >= 1/3 oraz y < 2/3
                wypisz "1"
            jezeli y < 1/3
                wypisz "0"
            y = y * 3
            jezeli y >= 2
                y <- y - 2
            jezeli y >= 1
                y <- y - 1
*/
