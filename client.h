#ifndef CLIENT_H
#define CLIENT_H
#include <QListWidgetItem>
#include <QMainWindow>

namespace Ui {
class client;
}

class client : public QMainWindow
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);

    struct clientType
    {
        std::string user;
        std::string pass;
        std::string mail;
        int id;
    };

    static int readClientDat(clientType clientDat[1000]);

//    static clientType temp[1000];
//    static int clientData_SIZE;
//    static clientType *clientData;

    ~client();

private slots:

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_cart_actionAdd_clicked();

    void displayBookList();

private:
    Ui::client *ui;
};

#endif // CLIENT_H
