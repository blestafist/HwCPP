#include <iostream>
using namespace std;

int main() { // enter point
    string str;
    cout << "Podaj tekst: ";
    getline(cin, str);

    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] == ' ' and str[i + 1] != ' ') {
            cout << str[i + 1];
            return 0;
        }
    }

    cout << "Nie znaleziono takiej sytuacji";
}

