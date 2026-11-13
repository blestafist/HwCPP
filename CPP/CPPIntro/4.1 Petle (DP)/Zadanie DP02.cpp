#include <iostream>
using namespace std;

int main() {
    int counter = 9;
    bool notFound = true;

    while (notFound) {
        for (int i = 9; i >= 1; i--) {
            if (i == 1){
                notFound = false;
                break;
            }

            if (counter % i == (i - 1)) {
                continue;
            }
            else {
                break;
            }
        }

        cout << counter << endl;
        counter += 10;
    }

    return 0;
}

