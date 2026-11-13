#include <iostream>
using namespace std;

int Potega(int num, int wykl) {
    int finalNum = num;
    for (int i = 0; i < wykl - 1; i++) {
        finalNum *= num;
    }
    return finalNum;
}

int Convert(string numStr) {
    int l10 = 0;
    for (int i = 0; i < numStr.size(); i++) {
        l10 += Potega(2, i) * (numStr[numStr.size() - 1 - i] - 48);
    }
    return l10;
}

int main() {
    string num;

    cout << "Podaj liczbę: ";
    cin >> num;

    cout << Convert(num);
}
