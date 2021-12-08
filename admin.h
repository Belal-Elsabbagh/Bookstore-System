#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>

namespace Ui {
class admin;
}

class admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_actionClients_clicked();

    void on_actionLoadBooks_clicked();

private:
    Ui::admin *ui;
};

#endif // ADMIN_H
