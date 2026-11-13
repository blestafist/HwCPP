#include <iostream>
using namespace std;

int main() {
    for (int i = 36; i < 127; i++) {
        cout << i << " - " << (char)i << "    ";
        if (i < 100) {cout << ' '; }
        if (i % 7 == 0) {cout << endl;}
    }
}
