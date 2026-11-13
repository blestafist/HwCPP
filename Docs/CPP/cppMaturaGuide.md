# Kompleksowy Przewodnik C++ do Matury
## Od Podstaw do Rozszerzonego Poziomu

---

## 📋 Spis Treści

1. [Podstawy Programowania](#podstawy)
2. [Zmienne i Typy Danych](#zmienne)
3. [Instrukcje Warunkowe](#warunki)
4. [Pętle](#petle)
5. [Funkcje](#funkcje)
6. [Tablice](#tablice)
7. [Obsługa Plików](#pliki)
8. [Algorytmy Maturalne](#algorytmy)
9. [Wzorce Zadań Maturalnych](#wzorce)

---

## <a name="podstawy"></a>1. Podstawy Programowania

### Struktura podstawowego programu

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    return 0;
}
```

**Objaśnienie:**
- `#include <iostream>` - dołączenie biblioteki wejścia/wyjścia
- `using namespace std;` - używanie standardowej przestrzeni nazw
- `int main()` - funkcja główna programu
- `cout` - wypisywanie na ekran
- `endl` - znak nowej linii
- `return 0;` - zakończenie programu

### Najważniejsze biblioteki

```cpp
#include <iostream>   // Wejście/wyjście
#include <fstream>    // Obsługa plików
#include <cmath>      // Funkcje matematyczne
#include <algorithm>  // Sortowanie, max, min
#include <string>     // Operacje na stringach
#include <vector>     // Wektory dynamiczne
```

---

## <a name="zmienne"></a>2. Zmienne i Typy Danych

### Podstawowe typy danych

```cpp
int liczba = 10;           // Liczby całkowite (-2147483648 do 2147483647)
long long duza = 1000000;  // Większe liczby całkowite
double rzeczywista = 3.14; // Liczby rzeczywiste
char znak = 'A';           // Pojedynczy znak
bool prawda = true;        // Wartość logiczna (true/false)
string tekst = "Hello";    // Ciąg znaków
```

### Operacje matematyczne

```cpp
int a = 10, b = 3;

cout << a + b;  // Dodawanie: 13
cout << a - b;  // Odejmowanie: 7
cout << a * b;  // Mnożenie: 30
cout << a / b;  // Dzielenie całkowite: 3
cout << a % b;  // Reszta z dzielenia (modulo): 1

double x = 10.0, y = 3.0;
cout << x / y;  // Dzielenie rzeczywiste: 3.333...
```

### Wczytywanie danych

```cpp
int liczba;
string imie;

// Wczytywanie pojedynczej wartości
cin >> liczba;

// Wczytywanie wielu wartości
cin >> liczba >> imie;

// Wczytywanie całej linii
getline(cin, imie);
```

### Konwersje typów

```cpp
// String na int
string s = "123";
int liczba = stoi(s);

// Int na string
int x = 456;
string str = to_string(x);

// Char na int (cyfra na liczbę)
char c = '5';
int digit = c - '0';  // Wynik: 5
```

---

## <a name="warunki"></a>3. Instrukcje Warunkowe

### Instrukcja if-else

```cpp
int x = 10;

if (x > 0) {
    cout << "Liczba dodatnia";
} else if (x < 0) {
    cout << "Liczba ujemna";
} else {
    cout << "Zero";
}
```

### Operatory logiczne

```cpp
int a = 5, b = 10;

// AND (i)
if (a > 0 && b > 0) {
    cout << "Obie liczby dodatnie";
}

// OR (lub)
if (a > 0 || b > 0) {
    cout << "Przynajmniej jedna dodatnia";
}

// NOT (negacja)
if (!(a > 10)) {
    cout << "a nie jest większe od 10";
}
```

### Operator warunkowy (ternary)

```cpp
int max = (a > b) ? a : b;  // Jeśli a > b, to max = a, w przeciwnym razie max = b
```

---

## <a name="petle"></a>4. Pętle

### Pętla for

```cpp
// Podstawowa pętla for
for (int i = 0; i < 10; i++) {
    cout << i << " ";
}
// Wynik: 0 1 2 3 4 5 6 7 8 9

// Pętla od tyłu
for (int i = 9; i >= 0; i--) {
    cout << i << " ";
}

// Pętla po tablicy
int tab[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) {
    cout << tab[i] << " ";
}
```

### Pętla while

```cpp
int i = 0;
while (i < 10) {
    cout << i << " ";
    i++;
}
```

### Pętla do-while

```cpp
int i = 0;
do {
    cout << i << " ";
    i++;
} while (i < 10);
```

### Kontrola pętli

```cpp
for (int i = 0; i < 10; i++) {
    if (i == 5) break;      // Przerwij pętlę
    if (i % 2 == 0) continue;  // Pomiń resztę i przejdź do następnej iteracji
    cout << i << " ";
}
// Wynik: 1 3
```

---

## <a name="funkcje"></a>5. Funkcje

### Deklaracja i definicja funkcji

```cpp
// Funkcja zwracająca wartość
int suma(int a, int b) {
    return a + b;
}

// Funkcja nie zwracająca wartości
void wypisz(string tekst) {
    cout << tekst << endl;
}

// Użycie funkcji
int main() {
    int wynik = suma(5, 3);
    wypisz("Hello!");
    return 0;
}
```

### Przydatne funkcje matematyczne

```cpp
#include <cmath>

int x = -5;
double y = 2.7;

abs(x);        // Wartość bezwzględna: 5
pow(2, 3);     // Potęgowanie: 8
sqrt(16);      // Pierwiastek: 4
floor(y);      // Zaokrąglenie w dół: 2
ceil(y);       // Zaokrąglenie w górę: 3
```

### Funkcje na stringach

```cpp
string s = "Hello";

s.length();      // Długość: 5
s.size();        // Długość: 5
s[0];            // Pierwszy znak: 'H'
s.substr(1, 3);  // Podciąg od indeksu 1, długość 3: "ell"
s.find("ll");    // Znajdź podciąg: zwraca 2
s.erase(1, 2);   // Usuń 2 znaki od indeksu 1: "Hlo"
s.insert(1, "i");// Wstaw "i" na pozycję 1: "Hiello"
```

---

## <a name="tablice"></a>6. Tablice

### Tablice jednowymiarowe

```cpp
// Deklaracja i inicjalizacja
int tab[5] = {1, 2, 3, 4, 5};

// Dostęp do elementów
cout << tab[0];  // Pierwszy element: 1
cout << tab[4];  // Ostatni element: 5

// Wczytywanie tablicy
int n = 5;
int liczby[100];
for (int i = 0; i < n; i++) {
    cin >> liczby[i];
}

// Wypisywanie tablicy
for (int i = 0; i < n; i++) {
    cout << liczby[i] << " ";
}
```

### Przydatne operacje na tablicach

```cpp
#include <algorithm>

int tab[5] = {3, 1, 4, 1, 5};

// Sortowanie rosnąco
sort(tab, tab + 5);
// Wynik: 1 1 3 4 5

// Sortowanie malejąco
sort(tab, tab + 5, greater<int>());
// Wynik: 5 4 3 1 1

// Znajdowanie minimum i maksimum
int minElement = *min_element(tab, tab + 5);
int maxElement = *max_element(tab, tab + 5);
```

### Tablice znakowe (C-stringi)

```cpp
char napis[100];

// Wczytywanie
cin >> napis;           // Wczytuje do pierwszej spacji
cin.getline(napis, 100); // Wczytuje całą linię

// Długość napisu
int dlugosc = strlen(napis);

// Kopiowanie
char kopia[100];
strcpy(kopia, napis);

// Porównywanie
if (strcmp(napis1, napis2) == 0) {
    cout << "Napisy są równe";
}
```

### Tablice dynamiczne (vector)

```cpp
#include <vector>

// Deklaracja
vector<int> v;

// Dodawanie elementów
v.push_back(1);
v.push_back(2);
v.push_back(3);

// Dostęp do elementów
cout << v[0];    // Pierwszy element
cout << v.back(); // Ostatni element

// Rozmiar
cout << v.size();

// Iterowanie
for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}

// Sortowanie
sort(v.begin(), v.end());
```

---

## <a name="pliki"></a>7. Obsługa Plików

### Czytanie z pliku

```cpp
#include <fstream>

ifstream plik;
plik.open("dane.txt");

// Sprawdzenie czy plik się otworzył
if (!plik.good()) {
    cout << "Błąd otwarcia pliku!" << endl;
    return 1;
}

// Czytanie pojedynczych wartości
int liczba;
while (plik >> liczba) {
    cout << liczba << endl;
}

// Czytanie linii po linii
string linia;
while (getline(plik, linia)) {
    cout << linia << endl;
}

plik.close();
```

### Zapis do pliku

```cpp
ofstream plik;
plik.open("wyniki.txt");

plik << "Pierwsza linia" << endl;
plik << "Druga linia" << endl;
plik << 42 << endl;

plik.close();
```

### Typowy wzorzec zadania maturalnego z plikiem

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream plik("dane.txt");
    
    if (!plik.good()) {
        cout << "Błąd!" << endl;
        return 1;
    }
    
    int liczba;
    int suma = 0;
    
    while (plik >> liczba) {
        suma += liczba;
        // Tutaj przetwarzanie danych
    }
    
    plik.close();
    
    cout << "Wynik: " << suma << endl;
    
    return 0;
}
```

---

## <a name="algorytmy"></a>8. Algorytmy Maturalne

### Sprawdzanie czy liczba jest pierwsza

```cpp
bool czyjest_pierwsza(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
```

### NWD (Największy Wspólny Dzielnik) - Algorytm Euklidesa

```cpp
int nwd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Wersja rekurencyjna
int nwd_rek(int a, int b) {
    if (b == 0) return a;
    return nwd_rek(b, a % b);
}
```

### NWW (Najmniejsza Wspólna Wielokrotność)

```cpp
int nww(int a, int b) {
    return (a * b) / nwd(a, b);
}
```

### Rozkład na czynniki pierwsze

```cpp
void rozklad(int n) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) cout << n;
}
```

### Palindrom

```cpp
bool czy_palindrom(string s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i]) {
            return false;
        }
    }
    return true;
}

// Dla liczb
bool czy_palindrom_liczba(int n) {
    int oryginalna = n;
    int odwrocona = 0;
    
    while (n > 0) {
        odwrocona = odwrocona * 10 + n % 10;
        n /= 10;
    }
    
    return oryginalna == odwrocona;
}
```

### Suma cyfr liczby

```cpp
int suma_cyfr(int n) {
    int suma = 0;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}
```

### Silnia

```cpp
// Wersja iteracyjna
long long silnia(int n) {
    long long wynik = 1;
    for (int i = 2; i <= n; i++) {
        wynik *= i;
    }
    return wynik;
}

// Wersja rekurencyjna
long long silnia_rek(int n) {
    if (n <= 1) return 1;
    return n * silnia_rek(n - 1);
}
```

### Ciąg Fibonacciego

```cpp
int fibonacci(int n) {
    if (n <= 1) return n;
    
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
```

### Sito Eratostenesa (liczby pierwsze do n)

```cpp
void sito_eratostenesa(int n) {
    bool pierwsza[n+1];
    
    // Inicjalizacja - wszystkie liczby jako pierwsze
    for (int i = 0; i <= n; i++) {
        pierwsza[i] = true;
    }
    
    pierwsza[0] = pierwsza[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (pierwsza[i]) {
            for (int j = i * i; j <= n; j += i) {
                pierwsza[j] = false;
            }
        }
    }
    
    // Wypisanie liczb pierwszych
    for (int i = 2; i <= n; i++) {
        if (pierwsza[i]) {
            cout << i << " ";
        }
    }
}
```

### Konwersja systemów liczbowych

```cpp
// Dziesiętny na binarny
string dec_to_bin(int n) {
    string wynik = "";
    while (n > 0) {
        wynik = to_string(n % 2) + wynik;
        n /= 2;
    }
    return wynik.empty() ? "0" : wynik;
}

// Binarny na dziesiętny
int bin_to_dec(string bin) {
    int wynik = 0;
    int potega = 1;
    
    for (int i = bin.length() - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            wynik += potega;
        }
        potega *= 2;
    }
    return wynik;
}
```

---

## <a name="wzorce"></a>9. Wzorce Zadań Maturalnych

### Wzorzec 1: Analiza liczb z pliku

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream plik("liczby.txt");
    
    int liczba;
    int ile_parzystych = 0;
    int ile_pierwszych = 0;
    int max_liczba = 0;
    
    while (plik >> liczba) {
        // Zliczanie parzystych
        if (liczba % 2 == 0) {
            ile_parzystych++;
        }
        
        // Sprawdzanie czy pierwsza
        if (czy_pierwsza(liczba)) {
            ile_pierwszych++;
        }
        
        // Szukanie maksimum
        if (liczba > max_liczba) {
            max_liczba = liczba;
        }
    }
    
    cout << "Parzyste: " << ile_parzystych << endl;
    cout << "Pierwsze: " << ile_pierwszych << endl;
    cout << "Maksimum: " << max_liczba << endl;
    
    plik.close();
    return 0;
}
```

### Wzorzec 2: Analiza napisów

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream plik("napisy.txt");
    
    string napis;
    int ile_palindromow = 0;
    string najdluzszy = "";
    
    while (plik >> napis) {
        // Sprawdzanie palindromów
        if (czy_palindrom(napis)) {
            ile_palindromow++;
        }
        
        // Szukanie najdłuższego
        if (napis.length() > najdluzszy.length()) {
            najdluzszy = napis;
        }
    }
    
    cout << "Palindromy: " << ile_palindromow << endl;
    cout << "Najdluzszy: " << najdluzszy << endl;
    
    plik.close();
    return 0;
}
```

### Wzorzec 3: Operacje na parach liczb

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream plik("pary.txt");
    
    int a, b;
    int ile_wzglednie_pierwszych = 0;
    
    while (plik >> a >> b) {
        // Sprawdzanie czy liczby są względnie pierwsze (NWD = 1)
        if (nwd(a, b) == 1) {
            ile_wzglednie_pierwszych++;
        }
    }
    
    cout << "Wzglednie pierwsze: " << ile_wzglednie_pierwszych << endl;
    
    plik.close();
    return 0;
}
```

### Wzorzec 4: Szyfrowanie/Deszyfrowanie

```cpp
// Szyfr Cezara
string szyfruj_cezar(string tekst, int przesuniecie) {
    string wynik = "";
    
    for (int i = 0; i < tekst.length(); i++) {
        char znak = tekst[i];
        
        if (znak >= 'A' && znak <= 'Z') {
            znak = ((znak - 'A' + przesuniecie) % 26) + 'A';
        }
        else if (znak >= 'a' && znak <= 'z') {
            znak = ((znak - 'a' + przesuniecie) % 26) + 'a';
        }
        
        wynik += znak;
    }
    
    return wynik;
}

string deszyfruj_cezar(string tekst, int przesuniecie) {
    return szyfruj_cezar(tekst, 26 - przesuniecie);
}
```

### Wzorzec 5: Anagramy

```cpp
#include <algorithm>

bool czy_anagramy(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    return s1 == s2;
}
```

---

## 🎯 Wskazówki do Matury

### Strategia rozwiązywania zadań:

1. **Przeczytaj dokładnie polecenie** - zrozum co jest dane i co ma być wynikiem
2. **Zaplanuj rozwiązanie** - rozpisz algorytm w punktach
3. **Pisz kod modularnie** - używaj funkcji dla powtarzających się operacji
4. **Testuj na prostych przykładach** - sprawdź czy kod działa poprawnie
5. **Pamiętaj o obsłudze plików** - większość zadań wymaga czytania z pliku
6. **Zwróć uwagę na typy danych** - używaj `long long` dla dużych liczb
7. **Optymalizuj gdy trzeba** - niektóre zadania wymagają efektywnych algorytmów

### Najczęstsze błędy:

- ❌ Brak sprawdzenia czy plik się otworzył
- ❌ Użycie `int` zamiast `long long` dla dużych liczb
- ❌ Przekroczenie zakresu tablicy
- ❌ Błędy przy dzieleniu całkowitym (5/2 = 2, nie 2.5!)
- ❌ Zapomnienie o `return 0;` w main
- ❌ Brak zamknięcia pliku

### Checklisty przed oddaniem:

✅ Program się kompiluje bez błędów  
✅ Program daje poprawne wyniki dla przykładowych danych  
✅ Plik jest poprawnie otwierany i zamykany  
✅ Używam odpowiednich typów danych  
✅ Kod jest czytelny i skomentowany  
✅ Sprawdziłem przypadki brzegowe

---

## 📚 Dodatkowe Zasoby

Polecane strony do ćwiczeń:
- https://www.iws.edu.pl/cpp - materiały z tej strony
- https://szkopul.edu.pl - zbiór zadań
- https://cke.gov.pl - oficjalne arkusze maturalne

**Powodzenia na maturze! 🚀**