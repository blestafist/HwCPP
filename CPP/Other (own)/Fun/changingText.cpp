#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <unistd.h>



const std::string inputWord = "Ja takaja kak vse, on skazal eto vseeem i ja takaja kak vse, glupaja sovsem"; // here place your word 
const int delayInMicroSeconds = 500; // delay in microseconds (800-1000 recommended)



char GenerateRandomChar() { // 32 - 126 = 93
    return rand() % 94 + 32;
}

std::string GenerateRandomWord() { // generate seed
    std::string result;

    for (uint8_t i = 0; i < inputWord.size(); i++) {
        result += GenerateRandomChar();
    }

    return result;
}

int main() { // entry point
    srand(time(NULL));

    std::string inputWordTemp = GenerateRandomWord();

    for (int i = 0; i < inputWord.size(); i++) {
        while (true) {
            if (inputWord[i] == GenerateRandomChar()) {
                inputWordTemp[i] = inputWord[i];
                std::cout << inputWordTemp << std::endl;
                break;
            }

            inputWordTemp[i] = GenerateRandomChar();

            std::cout << inputWordTemp << std::endl;
            usleep(delayInMicroSeconds);
        }
    }
}

