#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCORE 100

int main() {
    srand(time(NULL)); // init with time-based seed
    int score = rand() % 101; // getting a random number in <0, 100>

    float per = (float)score / (float)MAX_SCORE;

    printf("%f\n", per);
    return 0;
}
