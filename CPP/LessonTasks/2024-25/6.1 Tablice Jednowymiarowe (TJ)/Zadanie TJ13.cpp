#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));
    int tablica[20], maxSum = 0, para1 = 0, para2 = 0;

    for (int i = 0; i < 20; i++) {
        tablica[i] = rand()%101;
    }

    cout << "Tablica liczb: " << endl;

    for (int i = 0; i < 20; i++) {
        cout << tablica[i] << ' ';

        if (i != 0) {
            int suma = tablica[i] + tablica[i - 1];
            if (suma > maxSum) {
                maxSum = suma;
                para1 = tablica[i - 1];
                para2 = tablica[i];
            }
        }
    }

    cout << endl << endl << "Największa suma " << maxSum << " dla liczb " << para1 << " + " << para2;


    return 0;

}
