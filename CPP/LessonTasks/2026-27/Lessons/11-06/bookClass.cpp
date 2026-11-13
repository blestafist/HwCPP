#include <cstddef>
#include <string>
#include <iostream>


class Book {
    public: 
        Book ();
        Book (size_t npg, std::string p1c, std::string p2c);
        size_t numPages;
        std::string page1Contents;
        std::string page2Contents;
        void PrintBook();

        friend Book& operator+ (Book& b1, Book& b2) {
            b1.numPages += b2.numPages;
            return b1;
        }
};


Book::Book () {
    numPages = 2;
    page1Contents = "cześć";
    page2Contents = "meow";
}


Book::Book (size_t npg, std::string p1c, std::string p2c) {
    numPages = npg;
    page1Contents = p1c;
    page2Contents = p2c;
}


void Book::PrintBook () {
    std::cout << "Liczba stron: " <<  numPages << "\n";
    std::cout << "Zawartość strony 1: " << page1Contents << "\n";
    std::cout << "Zawartość strony 2: " << page2Contents << "\n";
}


int main () {
    Book book;
    book.numPages = 2;
    book.page1Contents = "Cześć";
    book.page2Contents = "Meow!";

    Book book2;
   
    book = book + book2;
    book.PrintBook();
    
    return 0;
}