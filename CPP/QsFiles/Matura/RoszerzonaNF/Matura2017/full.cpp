#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "wyniki6.txt";

const int DIMENSION_Y = 200;
const int DIMENSION_X = 320;

const char Y_OFFSET [4] { -1, 0, 0, 1 };
const char X_OFFSET [4] { 0, -1, 1, 0 };

// ==================================================================


void ParseFile (unsigned char (&pixels)[DIMENSION_Y][DIMENSION_X]) {
    std::ifstream inputFile(INPUT_FILE_NAME);
    
    if (!inputFile) {
        std::cerr << "ERROR: File " << INPUT_FILE_NAME << " not found!" <<std::endl;
        std::exit(1);
    }

    int tempValue;
    for (int y = 0; y < DIMENSION_Y; y++) {
        for (int x = 0; x < DIMENSION_X; x++) {
            if (inputFile >> tempValue) {
                pixels[y][x] = (unsigned char)tempValue;
            }   
            else {
                std::cerr << "ERROR: Failed to read value at [" << y << "][" << x << "]" << std::endl;
                std::exit(1);
            }
        } 
    }
}


// a helper func, not used in real program
void Print2D_Array (const unsigned char (&arr)[DIMENSION_Y][DIMENSION_X]) {
    for (int y = 0; y < DIMENSION_Y; y++) {
        for (int x = 0; x < DIMENSION_X; x++) {
            std::cout << (int)arr[y][x] << " ";
        }
        std::cout << '\n';
    }
}


void FindMinMax (const unsigned char (&arr)[DIMENSION_Y][DIMENSION_X], unsigned char& min, unsigned char& max) {
    for (int y = 0; y < DIMENSION_Y; y++) {
        for (int x = 0; x < DIMENSION_X; x++) {
            if (arr[y][x] < min) { min = arr[y][x]; }
            if (arr[y][x] > max) { max = arr[y][x]; }
        }
    }
}


int CountUnsymetrialRows (const unsigned char (&arr)[DIMENSION_Y][DIMENSION_X]) {
    int counter = 0;

    for (int y = 0; y < DIMENSION_Y; y++) {
        for (int x = 0; x < DIMENSION_X / 2; x++) {
            if (arr[y][x] != arr[y][DIMENSION_X - x - 1]) { counter++; break; }
        }
    }
    return counter;
}


int CountContrastingPix (const unsigned char (&arr)[DIMENSION_Y][DIMENSION_X]) {
    int counter = 0,
    ny, nx;

    for (int y = 0; y < DIMENSION_Y; y++) {
        for (int x = 0; x < DIMENSION_X; x++) {
            for (int i = 0; i < 4; i++) {
                ny = y + Y_OFFSET[i];
                nx = x + X_OFFSET[i];

                if (ny < 0 || ny >= DIMENSION_Y || nx < 0 || nx >= DIMENSION_X) { continue; }
                if (std::abs((int)arr[y][x] - (int)arr[ny][nx]) > 128) { counter++; break;}
            }
        }
    }
    return counter; 
}


int LongestSameBrightnesSequence (const unsigned char (&arr)[DIMENSION_Y][DIMENSION_X]) {
    int max = 1;

    for (int x = 0; x < DIMENSION_X; x++) {
        int counter = 1;

        for (int y = 0; y < DIMENSION_Y - 1; y++) {
            if (arr[y][x] == arr[y + 1][x]) { counter ++;}
            else {
                if (max < counter) { max = counter; }
                counter = 1;
            }
        }
        if (max < counter) { max = counter; }
    }
    return max;
}


int main() {
    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return -1; }

    unsigned char pixels[DIMENSION_Y][DIMENSION_X];
    unsigned char min = 255, max = 0;

    ParseFile(pixels);
    
    FindMinMax(pixels, min, max);

    auto Print = [&] (auto&& ... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("6.1:\njasność najjaśniejszego piksela: ", (int)max, "\njasność najciemniejszego piksela: ", (int)min);
    Print("6.2:\nnajmniejsza liczba wierszy do usunięcia: ", CountUnsymetrialRows(pixels));
    Print("6.3:\nliczba kontrastujących pikseli: ", CountContrastingPix(pixels));
    Print("6.4:\nliczba najdłuższej linii pionowej: ", LongestSameBrightnesSequence(pixels));

    return 0;
}