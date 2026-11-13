#include <iostream>
using namespace std;


int main() {
    int zp, zl, bufer;
    bool czyPierwsza;

    cout << "Podaj zakres lewy: ";
    cin >> zl;

    cout << "Podaj zakres prawy: ";
    cin >> zp;


    if (zl > zp) {
        bufer = zp;
        zp = zl;
        zl = bufer;
    }

    for (int i = zl; i <= zp; i++) {
        czyPierwsza = true;
        for (int j = 2; j * j <= i; j++) {
            if (i%j==0) {
                czyPierwsza = false;
                break;
            }
        }

        if (czyPierwsza == true) {
            cout << i << ' ';
        }
    }

    return 0;
}

