#include <iostream>
using namespace std;

int main() {
    float waga, wzrost, bmi;   // deklarowanie zmiennych

    cout << "Podaj wagę w kg: "; // pobieranie wagi od użytkownika
    cin >> waga;

    cout << "Podaj wzrost w cm: ";  // pobieranie wzrostu od użytkownika
    cin >> wzrost;

    wzrost = wzrost / 100;  // wzrost do metrów

    bmi = waga / (wzrost * wzrost);   // obliczenie BMI

    if (bmi < 18) {
        cout << "Niedowaga, BMI = " << bmi;   // komunikat o niedowadze
    }

    else if (bmi >= 18 and bmi < 24) {
        cout << "Norma, BMI = " << bmi;  // komunikat o normie
    }

    else if (bmi >= 24 and bmi < 29) {
        cout << "Nadwaga, BMI = " << bmi; // komunikat o nadwadze
    }

    else if (bmi >= 29 and bmi < 39) {
        cout << "Otyłość, BMI = " << bmi;   // komunikat o otyłośći
    }

    else {
        cout << "Poważna otyłość, BMI = " << bmi;  // komunikat o poważnej otyłośći
    }

    return 0;
}
