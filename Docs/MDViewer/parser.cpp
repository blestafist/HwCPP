#include "parser.h"

char HeaderLever(const std::string &header) {
    char i; // 0 means invalid header

    for (i = 0; i < header.size() - 1; i++) {
        if (header[i] != '#') { i--; break; }
    }

    if (header[i + 1] == ' ') { return (i + 1 <= 6) ? i + 1 : -1; }
    return -1;
}

Types WhatType(const std::string &line) {
    for (char c : line) {
        
    }
}

