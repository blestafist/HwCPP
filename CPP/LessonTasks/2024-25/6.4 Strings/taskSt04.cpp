#include <iostream>
using namespace std;

int f(string s) {
    int quantity = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 48 and s[i] <= 57) { quantity++; }
    }
    return quantity;
}

int main() { // enter point
    string str;
    cout << "Podaj tekst: ";
    getline(cin, str);

    cout << "Podany tekst zawiera cyfr: " << f(str);
}

