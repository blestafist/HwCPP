#include <cstddef>
#include <iostream>

int Res (int i, int* ctr) {
    if (i < 3) { ++*(ctr); return 1; } // всегда нечетное, все дороги ведут сюда
    else {
        if (i % 2 == 0) {
            return Res(i - 3, ctr) + Res(i - 1, ctr) + 1;
            // Нечетное + Нечетное → (четное) + 1 → нечетное
        } else {
            return Res (i - 1, ctr) % 7;
            // соотвественно новый branch прийдет сюда, здесь всегда i → нечетное
            // нечетное - 1 → четное, а это вернет либо единицу, либо какое то нечетное число
        }
    }
}

int main () {
    for (size_t i = 0; i <= 12; ++i) {
        int ctr = 0;
        std::cout << i << " → " << Res(i, &ctr) << " wywoł → " << ctr << "\n";
    }

    return 0;
}
