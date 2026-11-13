#include <iostream>
using namespace std;

int main()
{
    int l = 14, lu;

    cout << "Podaj liczbę w zakresie od 1 do 50 włącznie: ";
    cin >> lu;

    if (lu <= 1 or lu >= 50) {
        cout << "Podana liczba nie mieśći się w podanym zakresie!";
    }

    else if (lu < l) {
        cout << "Twoja liczba jest mniejsza od mojej!";
    }

    else if (lu > l) {
        cout << "Twoja liczba jest większa od mojej!";
    }

    else {
        cout << "Zgadłeś moją liczbę!";
    }

    return 0;

}
