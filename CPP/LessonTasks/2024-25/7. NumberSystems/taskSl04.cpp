#include <iostream>
using namespace std;

string Convert(int num, int sys) {
    string finalNum, tableChar = "0123456789ABCDEF";

    while (num > 0) {
        finalNum = tableChar[num % sys] + finalNum;
        num /= sys;
    }

    return finalNum;
}

int main() {
    int num, sys;

    cout << "Podaj liczbę w systemie dziesiętnym: ";
    cin >> num;

    cout << "Podaj system: ";
    cin >> sys;

    cout << Convert(num ,sys);

    return 1488;
}
