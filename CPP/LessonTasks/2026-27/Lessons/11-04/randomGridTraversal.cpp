#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstdint>
#include <ctime>
#include <vector>


const std::string INPUT_FILE = "Input/dane2.txt";

static constexpr uint_fast8_t ROWS = 10;
static constexpr uint_fast8_t COLS = 10;

static constexpr int_fast8_t vectorsX [] = { 0, 0, 1, 1, 1, -1, -1, -1 };
static constexpr int_fast8_t vectorsY [] = { 1, -1, 1, 0, -1, 1, 0, -1 };


struct Move {
    int_fast8_t moveX = 0;
    int_fast8_t moveY = 0;
};

struct Pos {
    int_fast8_t posX = 0;
    int_fast8_t posY = 0;
};


void PrintArr (char (&arr)[ROWS][COLS]) {
    for (size_t y = 0; y < ROWS; ++y) {
        for (size_t x = 0; x < COLS; ++x) {
            std::cout << arr[y][x] << ' ';
        }

        std::cout << "\n";
    }
}


bool MoveToOne (char (&arr)[ROWS][COLS], Pos& pPos) {
    std::vector<Move> possibleMoves;

    Pos newPos;
    for (size_t i = 0; i < 8; ++i) {
        newPos.posX = pPos.posX + vectorsX[i];
        newPos.posY = pPos.posY + vectorsY[i];

        if (newPos.posX < COLS && newPos.posX >= 0 &&
            newPos.posY < ROWS && newPos.posY >= 0 &&
            arr[newPos.posY][newPos.posX] == '1') {
            possibleMoves.push_back(Move { vectorsX[i], vectorsY[i] });
        }
    }

    size_t maxMoves = possibleMoves.size();

    if (possibleMoves.empty()) { return false; } // no more moves availible
    size_t randMove = rand() % maxMoves;

    arr[pPos.posY][pPos.posX] = '0';

    // apply move
    pPos.posX += possibleMoves[randMove].moveX;
    pPos.posY += possibleMoves[randMove].moveY;

    arr[pPos.posY][pPos.posX] = 'P';

    return true;
}


int main () {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    srand(time(NULL));

    char arr[ROWS][COLS];
    Pos pPosCurr;

    for (size_t y = 0; y < ROWS; ++y) {
        for (size_t x = 0; x < COLS; ++x) {
            inputFile >> arr[y][x];
            if (arr[y][x] == 'P') { pPosCurr.posX = x, pPosCurr.posY = y; }
        }
    }

    PrintArr(arr);


    bool statusCode = true;
    while (statusCode) {
        statusCode = MoveToOne(arr, pPosCurr);
        PrintArr(arr);
        
        std::cout << "\n";
    }

    std::cout << "No moves availible!";

    return 0;
}
