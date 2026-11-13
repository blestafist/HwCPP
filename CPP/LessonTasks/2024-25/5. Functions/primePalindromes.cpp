#include <iostream>
using namespace std;

bool isPierwsza(int liczba) {
    if (liczba < 2) { return false; }
    for (int i = 2; i * i <= liczba; i++) {
        if (liczba % i == 0)
            return false;
    }
    return true;
}

bool isPalindrom(int liczba) {
    int kopia = liczba, wspak = 0;
    while (kopia != 0) {
        wspak *= 10;
        wspak += kopia % 10;
        kopia /= 10;
    }
    
    if (wspak == liczba)
        return true;
    return false;
}


int main()
{
    for (int i = 10; i <= 1000; i++) {
        if (isPierwsza(i) and isPalindrom(i)) {
            cout << i << ' ';
        }
    }
}

