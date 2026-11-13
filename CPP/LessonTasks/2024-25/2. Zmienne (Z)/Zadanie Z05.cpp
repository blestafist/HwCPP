#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float a, h, x;

    cout << "Podaj długość pierwszej przyprostokątnej: ";
    cin >> a;

    cout << "Podaj długość drugiej przyprostokątnej: ";
    cin >> h;

    x = sqrt(a * a + h * h);

    cout << "Długość przeciwprostokątnej wynosi: " << x << endl;
    cout << "Pole trójkątu wynosi: " << (a * h) / 2 << endl;
    cout << "Obwód trójkątu wynosi: " << a + h + x;

    return 0;
}
