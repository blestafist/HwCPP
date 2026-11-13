#include <iostream>
using namespace std;

string Convert(int num) {
    string str;
    char symbol;

    while (num > 0) {
        symbol = num % 2 + 48;
        str = symbol + str;
        num /= 2;
    }

    return str;
}

int main() {
    int num;

    cout << "Podaj liczbę: ";
    cin >> num;

    cout << Convert(num);
    return 1488;

}

