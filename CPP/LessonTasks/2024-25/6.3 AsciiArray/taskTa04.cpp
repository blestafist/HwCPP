#include <iostream>
using namespace std;

int main() {
    char c;
    cout << "Podaj znak: ";
    cin >> c;

    cout << endl << endl;

    int code = (int)c;
    if (code >= 65 && code <= 91) {code += 32;}
    else {code -= 32;}

    cout << "Zamieniony znak: " << (char)code;
}
