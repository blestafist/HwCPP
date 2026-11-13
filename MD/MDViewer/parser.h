#ifndef PARSER_H
#define PARSER_H

#include <cstddef>
#include <iostream>

enum Types : char {
    Header,
    Bold,
    Italic,
    Underline,
    Table,
    Mix
};

char HeaderLever(const std::string& header); // used by renderer to render propriate header

Types WhatType(const std::string& line);

#endif
