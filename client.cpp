#include "client.h"
#include "ui_client.h"
#include "books.h"
#include <fstream>
#include <sstream>
#include <QMessageBox>
#include <QDialogButtonBox>
using namespace std;

client::client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
  //  displayBookList();
}

client::~client()
{
    delete ui;
}

void client::on_listWidget_itemClicked(QListWidgetItem *item) // view item in book viewer
{

}
void client::on_cart_actionAdd_clicked()
{

}

void client::displayBookList()
{

}

int client::readClientDat(clientType clientDat[1000])
{
    string line;
    int linenum = 0;
    ifstream inClients;
    inClients.open("D:/Programming/Qt/bookstore_system/data/client_dat.csv", ios::in);

    clientType tempClient;
     while (!inClients.eof())
     {
         stringstream linestream(line);
         string tempID;

         getline(linestream, tempClient.user, ',');
         getline(linestream, tempClient.pass, ',');
         getline(linestream, tempClient.mail, ',');
         getline(linestream, tempID, ',');
         stringstream ss(tempID);
         ss >> tempClient.id;

         inClients.read((char *) &tempClient, sizeof(tempClient));
         clientDat[linenum] = tempClient;

         linenum++;
     }
     inClients.close();
     return linenum;
}
