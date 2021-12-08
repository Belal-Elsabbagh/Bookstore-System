#ifndef BOOKS_H
#define BOOKS_H
#include<string>

class books
{
public:
    books();

    struct bookType
    {
        std::string title;
        std::string author;
        std::string publisher;
        int npages;
        std::string lang;
        std::string genre;
        int pubYear;
        float price;
    };

    static int loadBookDat(bookType bookDat[1000]);
     bookType bookData[1000];
    const int bookData_SIZE = loadBookDat(bookData);
};

#endif // BOOKS_H
