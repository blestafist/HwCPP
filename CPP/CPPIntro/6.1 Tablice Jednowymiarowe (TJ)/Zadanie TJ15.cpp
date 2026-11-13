#include <bits/stdc++.h>
#include <limits.h>
using namespace std;;

int main() {
    int maks = INT_MIN, ile, maksk = 0;

    cout << "Podaj ilosc elementow w zbiorze: ";
    cin >> ile;

    int tab[ile];

    for (int i = 0; i < ile; i++) {
        cout << "Podaj element " << i + 1 << ": ";
        cin >> tab[i];

        if (tab[i] > maks) {
            maks = tab[i];
        }
    }

    int tabk[maks + 1] {};

    for (int i = 0; i < ile; i++) {
        tabk[tab[i]]++;

        if (maksk < tabk[tab[i]]) {
            maksk = tabk[tab[i]];
        }
    }

    cout << "Dominanty: ";

    for (int i = 0; i < maks + 1; i++) {
        if (tabk[i] == maksk) {
            cout << i << ' ';
        }
    }



    return 0;
}
