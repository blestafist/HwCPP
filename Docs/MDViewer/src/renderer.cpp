#include "renderer.h"
#include "parser.h"

void PrintDivider(char flag, const std::string &style) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    std::cout << style;

    for (short i = 0; i < w.ws_col; i++) {
        std::cout << flag;
    }

    std::cout << Style::RESET << "\n\n";
}

void PrintHeader(const std::string& header) {
    char headerLevel = HeaderLever(header);
    std::string style;

    switch (headerLevel) {
        case 1:
            style = Style::RED; break;
        case 2:
            style = Style::YELLOW; break;
        case 3:
            style = Style::MAGENTA; break;
        case 4:
            style = Style::BLUE; break;
        case 5:
            style = Style::MAGENTA; break;
        case 6:
            style = Style::GREEN; break;
        default:
            std::cerr << "Error. Not a header. Check the parser\n";
            return;
    }

    std::cout << style << header << Style::RESET << "\n"; 
}
