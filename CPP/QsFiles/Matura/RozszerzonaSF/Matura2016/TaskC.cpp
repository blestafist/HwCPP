#include <iostream>
#include <fstream>


// ====================================== CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "gra.txt";
const std::string OUTPUT_FILE_NAME = "wyniki_5.txt";
 
const unsigned char DIMENSION_Y = 12; 
const unsigned char DIMENSION_X = 20;

const char Y_OFFSET [8] { -1, -1, -1, 0, 0, 1, 1, 1 };
const char X_OFFSET [8] { -1, 0, 1, -1, 1, -1, 0, 1 };

// ========================================================================================


int AliveNeighboursCount (const bool (&generation)[DIMENSION_Y][DIMENSION_X], int y, int x)  // Count of alive neighbours around the cell
{
    int counter = 0;

    for (int i = 0; i < 8; i++)
    {
        int nY = (y + Y_OFFSET[i] + DIMENSION_Y) % DIMENSION_Y;
        int nX = (x + X_OFFSET[i] + DIMENSION_X) % DIMENSION_X;

        if (generation[nY][nX]) { counter++; }
    }
    return counter;
}


bool IsCellAlive (const bool (&generation)[DIMENSION_Y][DIMENSION_X], int y, int x)   // Checks if the cell is alive in the next generation
{
    int AliveNeighbours = AliveNeighboursCount(generation, y, x);

    if (generation[y][x]) {                                     // Conditions of cell live in a new generation
        return (AliveNeighbours == 2 || AliveNeighbours == 3); 
    }  
    return (AliveNeighbours == 3);
}


void ComputeNextGen (const bool (&generation)[DIMENSION_Y][DIMENSION_X], bool (&nextGen)[DIMENSION_Y][DIMENSION_X])    // Simulates the life of cells in a next generation
{
    for (int y = 0; y < DIMENSION_Y; y++)
    {
        for (int x = 0; x < DIMENSION_X; x++)   // Goes throught previous generation
        {
            nextGen[y][x] = (IsCellAlive(generation, y, x));    
        }
    }
}


bool AreGenerationsEqual (const bool (&gen1)[DIMENSION_Y][DIMENSION_X], const bool (&gen2)[DIMENSION_Y][DIMENSION_X])
{
    for (int y = 0; y < DIMENSION_Y; y++)
    {
        for (int x = 0; x < DIMENSION_X; x++)
        {
            if (gen1[y][x] != gen2[y][x]) { return false; }
        }
    }
    return true;
}


void CopyGeneration (const bool (&source)[DIMENSION_Y][DIMENSION_X], bool (&dest)[DIMENSION_Y][DIMENSION_X] )
{
    for (int y = 0; y < DIMENSION_Y; y++)
    {
        for (int x = 0; x < DIMENSION_X; x++)
        {
            dest[y][x] = source[y][x];
        }
    }
}


int main()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return -1; }

    bool crrGen[DIMENSION_Y][DIMENSION_X];

    char tempChar;
    
    for (int y = 0; y < DIMENSION_Y; y++)    
    {
        for (int x = 0; x < DIMENSION_X; x++)   // Fill the 2D array of first generation 
        {
            inputFile >> tempChar;
            crrGen[y][x] = (tempChar == 'X');
        }
    }

    int genNum = 2;

    bool nextGen[DIMENSION_Y][DIMENSION_X];

    while (genNum <= 100)
    {
        ComputeNextGen(crrGen, nextGen);

        if (AreGenerationsEqual(crrGen, nextGen)) { break; }

        CopyGeneration(nextGen, crrGen);

        genNum++;
    }
    
    int cellsCounter = 0;

    for (int y = 0; y < DIMENSION_Y; y++)
    {
        for (int x = 0; x < DIMENSION_X; x++)
        {
            if (crrGen[y][x]) { cellsCounter++; }
        }
    }
    
    std::cout << "C\nW pokoleniu nr " << genNum <<", liczba żywych komórek : " << cellsCounter;
    outputFile << "C\nW pokoleniu nr " << genNum <<", liczba żywych komórek : " << cellsCounter;

    return 0;
}