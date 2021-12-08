#ifndef LOGIN_H
#define LOGIN_H
#include "admin.h"
#include "client.h"
#include <QWidget>
#include <QFile>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);

    ~login();

private slots:
    void on_actionLogin_clicked();
    void on_actionReg_clicked();
    void on_regRePass_textChanged(const QString &arg1);
    void on_regUser_textChanged(const QString &arg1);

private:
    Ui::login *ui;
    admin *adminWindow;
    client *clientWindow;
};

#endif // LOGIN_H
