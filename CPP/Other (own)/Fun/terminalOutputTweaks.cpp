#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string>

// ==================== TERMINAL STYLE ====================

namespace Style {
    // ! Text effects
    const std::string RESET     = "\033[0m";
    const std::string BOLD      = "\033[1m";
    const std::string UNDERLINE = "\033[4m";
    const std::string INVERSE   = "\033[7m";

    // ! Basic colors
    const std::string BLACK   = "\033[30m";
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string BLUE    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN    = "\033[36m";
    const std::string WHITE   = "\033[37m";

    // ! Bold colors
    const std::string B_RED     = "\033[91m";
    const std::string B_GREEN   = "\033[92m";
    const std::string B_YELLOW  = "\033[93m";
    const std::string B_BLUE    = "\033[94m";
    const std::string B_MAGENTA = "\033[95m";
    const std::string B_CYAN    = "\033[96m";
    const std::string B_WHITE   = "\033[97m";

    // ! Background
    const std::string BG_RED     = "\033[41m";
    const std::string BG_GREEN   = "\033[42m";
    const std::string BG_YELLOW  = "\033[43m";
    const std::string BG_BLUE    = "\033[44m";
    const std::string BG_MAGENTA = "\033[45m";
    const std::string BG_CYAN    = "\033[46m";
    const std::string BG_WHITE   = "\033[47m";
}

// =========================================================

void DrawDivider(const char c, const std::string& color) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    std::cout << color;

    for (short i = 0; i < w.ws_col; i++) {
        std::cout << c;
    }

    std::cout << Style::RESET << "\n\n";
}

int main() {
    DrawDivider('=', Style::RED);
}