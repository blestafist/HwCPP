#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> charDist(33, 126);
uniform_int_distribution<int> startYDist(1, 10);

const string COLOR_RESET   = "\x1b[0m";
const string COLOR_GREEN   = "\x1b[32m";
const string COLOR_BRIGHT  = "\x1b[92m";
const string COLOR_DARK    = "\x1b[38;5;22m";

void gotoxy(int x, int y) {
    cout << "\x1b[" << y << ";" << x << "H";
}

struct RainStream {
    int x;
    int headY;
    int tailLength;
    int screenHeight;

    RainStream(int col, int height) : x(col), screenHeight(height) {
        reset();
    }

    void reset() {
        headY = startYDist(rng) - tailLength;
        tailLength = uniform_int_distribution<int>(5, 15)(rng);
    }

    void update() {
        headY++;

        if (headY - tailLength > screenHeight) {
            reset();
        }
    }
};


int main() {
    const int WIDTH = 80;
    const int HEIGHT = 25;

    cout << "\x1b[2J\x1b[?25l\x1b[40m";

    vector<RainStream> streams;
    for (int i = 1; i <= WIDTH; ++i) {
        streams.emplace_back(i, HEIGHT);
    }

    while (true) {
        for (auto& stream : streams) {
            stream.update();
            int head = stream.headY;
            int tail = head - stream.tailLength;

            for (int y = head - 1; y >= tail; --y) {
                if (y >= 1 && y <= HEIGHT) {
                    gotoxy(stream.x, y);
                    if (y == head - 1) cout << COLOR_GREEN;
                    else cout << COLOR_DARK;
                    cout << (char)charDist(rng);
                }
            }

            if (head >= 1 && head <= HEIGHT) {
                 gotoxy(stream.x, head);
                 cout << COLOR_BRIGHT << (char)charDist(rng);
            }

            int bottomY = tail - 1;
            if (bottomY >= 1 && bottomY <= HEIGHT) {
                gotoxy(stream.x, bottomY);
                cout << " ";
            }
        }

        cout << COLOR_RESET;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(40));
    }

    cout << "\x1b[0m\x1b[?25h";
}