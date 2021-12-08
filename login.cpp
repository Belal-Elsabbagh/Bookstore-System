#include "login.h"
#include "ui_login.h"
#include "admin.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <cstring>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

int clientData_SIZE;
client::clientType clientData[1000];

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    clientData_SIZE = client::readClientDat(clientData);
}


login::~login()
{
    delete ui;
}
//------------------------------------------------------------------(Login Functions)------------------------------------------------------------------------------------------//
void login::on_actionLogin_clicked()
{
    QString QUser = ui->loginUser->text(), //takes the values the user entered in the lines and puts them in variables.
            QPass = ui->loginPass->text();
    int status = 0;
    client::clientType activeClient;
    activeClient.user = QUser.toStdString(), activeClient.pass = QPass.toStdString();
    activeClient.id = 0;

    //------------------------------------------------(admin login)
    if(activeClient.user == "admin" && activeClient.pass == "admin12345")
    {
        close(); //------------------closes the login window.
        adminWindow = new admin(); //creates an admin class window
        adminWindow->show(); //------opens the admin window
    }

    //------------------------------------------------(client login)
    else
    {

        for(int i = 0; i < clientData_SIZE; i++)
        {
            if(activeClient.user == clientData[i].user)
            {
                if(activeClient.pass == clientData[i].pass)
                {
                    status = 2; //-----------------------------confirms success of the login.
                    close(); //--------------------------------closes the login window.
                    clientWindow = new client(); //------------creates a client class window.
                    clientWindow->setWindowTitle(QUser); //-----sets the client's window title to his username.
                    clientWindow->show(); //-------------------opens the client window.
                    break;
                }
                status = 1;
            }
        }
        switch (status) //-----------------------------------------defines state of the login process.
        {
        case 0:
            QMessageBox::about(this, "Login", "User not found");
        case 1:
            QMessageBox::about(this, "Login", "Incorrect Password");
        }

        }
}
//------------------------------------------------------------------(Registration Functions)-----------------------------------------------------------------------------------//
void login::on_actionReg_clicked()
{
    bool status = 1;
    //-----------------------enter the data that the user entered into variables.
    string user = (ui->regUser->text()).toStdString(),
           email = (ui->regMail->text()).toStdString(),
           pass = (ui->regPass->text()).toStdString(),
           rePass = (ui->regRePass->text()).toStdString();

//    client::clientType temp[1000];
//    int n;
//    n = login::readClientDat(temp);
//    clientType *pDat;
//    pDat = new clientType[n+1];

    //-------------------------------------------------(Data Checks when register is clicked)
    if(pass != rePass) //if passords don't match
    {
        status = 0;
        QMessageBox::about(this, "Registration Error", "Password check failed.");
    }
    if(pass == "" || user == "" || email == "") //empty fields
    {
        status = 0;
        QMessageBox::about(this, "Registration Error", "Required fields are empty. Please make sure you entered all the required data.");
    }
    for(int i = 0; i < clientData_SIZE; i++)
    {
        if(user == clientData[i].user || email == clientData[i].mail)
        {
            status = 0; //-----------------------------confirms success of the login.
            QMessageBox::about(this, "Registration Error", "User already exists.");
            break;
        }
    }

    if(status == 1) //-------------------registration checks successful.
    {

        clientData[clientData_SIZE].id = clientData_SIZE + 1;
        ofstream clients;
        clients.open("D:\\Programming\\Qt\\bookstore_system\\data\\client_dat.csv", ios::app);  // write the new client's data in the database.

        clients << clientData[clientData_SIZE].user << ","
                << clientData[clientData_SIZE].pass << ","
                << clientData[clientData_SIZE].mail << ','
                << clientData[clientData_SIZE].id << "\n"; //enters data in csv format.


        clients.close(); //-----------------------------------------closes file.
        QMessageBox::about(this, "Registration", "Successful registration!"); //Announces the success of the data entry.

        //------------------------(resets lines)
        ui->regUser->clear();
        ui->regMail->clear();
        ui->regPass->clear();
        ui->regRePass->clear();
    }
}

void login::on_regRePass_textChanged(const QString &arg1) //password match indicator
{
    if(arg1 == ui->regPass->text() || arg1 == "") //if the passowrds match
    {
        ui->pass_isMatch->setPixmap(QPixmap(":/resources/img/icons/check-mark.png"));
        ui->pass_isMatch->setToolTip("Passwords match");
    }
    else
    {
        ui->pass_isMatch->setPixmap(QPixmap(":/resources/img/icons/x-mark.png"));
        ui->pass_isMatch->setToolTip("Passwords do not match");
    }
}

void login::on_regUser_textChanged(const QString &arg1)
{
    for(int i = 0; i < clientData_SIZE; i++)
    {
        if(arg1.toStdString() == clientData[i].user) //if username does not already exist
        {
            ui->user_isExist->setPixmap(QPixmap(":/resources/img/icons/x-mark.png"));
            ui->user_isExist->setToolTip("Username already exists.");
        }
        else
        {
            ui->user_isExist->setPixmap(QPixmap(":/resources/img/icons/check-mark.png"));
            ui->user_isExist->setToolTip("Username is available.");
        }
    }
}
