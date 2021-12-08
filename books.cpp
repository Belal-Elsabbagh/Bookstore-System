#include "books.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;




books::books()
{

}

int books::loadBookDat(bookType bookDat[1000])
{
    string line;
    int linenum = 0;
    ifstream inClients;
    inClients.open("D:/Programming/Qt/bookstore_system/data/book_dat.csv", ios::in);
    bookType tempBook;
     while (getline (inClients, line))
     {
         istringstream linestream(line);
         string tempPages;

         getline(linestream, tempBook.title, ',');
         getline(linestream, tempBook.author, ',');
         getline(linestream, tempBook.publisher, ',');
         getline(linestream, tempPages, ',');
         stringstream p(tempPages);
         p >> tempBook.npages;
         getline(linestream, tempBook.title, ',');
         getline(linestream, tempBook.author, ',');

         bookDat[linenum] = tempBook;

         linenum++;
     }
     return linenum;
}
