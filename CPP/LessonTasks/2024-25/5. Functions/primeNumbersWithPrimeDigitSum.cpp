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

bool isSumPierwsza(int liczba) {
    int kopia = liczba, suma = 0;
    while (kopia != 0) {
        suma += kopia % 10;
        kopia /= 10;
    }
    
    if (isPierwsza(suma))
        return true;
    return false;
}


int main()
{
    for (int i = 0; i <= 100; i++) {
        if (isPierwsza(i) and isSumPierwsza(i)) {
            cout << i << ' ';
        }
    }
}

