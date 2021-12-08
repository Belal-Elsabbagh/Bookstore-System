#include "login.h"
#include "admin.h"
#include "client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login log;
    log.show();


    return a.exec();
}
