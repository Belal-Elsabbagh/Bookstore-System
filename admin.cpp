#include "admin.h"
#include "books.h"
#include "client.h"
#include "ui_admin.h"
#include <fstream>
#include <sstream>
#include <QPixmap>
#include <QDir>
using namespace std;
admin::admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_actionClients_clicked()
{
//    for (int row = 0; row < clientData_SIZE1; row++)
//    {
//        QString tempUser, tempMail;
//        QTableWidgetItem *tempItem = new QTableWidgetItem(tempUser.fromStdString(clientData1[row].user));
//        ui->table->setItem(2,2, tempItem);
//    }
}

void admin::on_actionLoadBooks_clicked()
{
//    ifstream inBooks("D:/Programming/Qt/bookstore_system/data/book_dat.csv", ios::in);
//    books::bookType tempBook;
//    books::bookType bookDat[1000];
//    int linenum = 0;
//    string line;
//     while (getline (inBooks, line))
//     {
//         istringstream linestream(line);
//         string tempPages, tempYear, tempPrice;
//         getline(linestream, tempBook.title, ',');
//         getline(linestream, tempBook.author, ',');
//         getline(linestream, tempBook.publisher, ',');

//         getline(linestream, tempPages, ',');
//         stringstream p1(tempPages);
//         p1 >> tempBook.npages;

//         getline(linestream, tempBook.lang, ',');
//         getline(linestream, tempBook.genre, ',');

//         getline(linestream, tempYear, ',');
//         stringstream p2(tempYear);
//         p2 >> tempBook.pubYear;

//         getline(linestream, tempYear, ',');
//         stringstream p3(tempPrice);
//         p3 >> tempBook.price;

//         bookDat[linenum] = tempBook;

//         linenum++;
//     }
     for(int i = 0; i < linenum; i++)
     {
         QString title = title.fromStdString(bookDat[i].title),
                 author = author.fromStdString(bookDat[i].author),
                 pub = pub.fromStdString(bookDat[i].publisher);


         QTableWidgetItem *tempTitle = new QTableWidgetItem(title),
                          *tempAuthor = new QTableWidgetItem(author),
                          *tempPub = new QTableWidgetItem(pub);

         ui->table->setItem(i+1, 1, tempTitle), ui->table->setItem(i+1, 2, tempAuthor), ui->table->setItem(i+1, 3, tempPub);
     }
}
