#include <iostream>
using namespace std;

int main() {
    int reszta;
    int dengi[15] = { 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };

    {
        float doZaplatyTime, zaplaconoTime;

        cout << "Ile pieniądzy do zapłaty? : ";
        cin >> doZaplatyTime;

        cout << "Ile kupujący zapłacił? : ";
        cin >> zaplaconoTime;

        reszta = (zaplaconoTime * 100) - (doZaplatyTime * 100);

        cout << "Reszta do wydania: " << float(reszta) / 100 << endl << endl;
    }

    for (int i = 0; i < 15; i++) {
        int num = 0;
        while (reszta >= dengi[i]) {
            num++;
            reszta -= dengi[i];
        }

        if (num > 0) {
            if (i <= 5)
                cout << num << " banknotow " << dengi[i] / 100 << " złotowych" << endl;
            else if (i <= 8)
                cout << num << " monet " << dengi[i] / 100 << " złotowych" << endl;
            else
                cout << num << " monet " << dengi[i] << " groszowych " << endl;
        }
    }
    return 0;
}
