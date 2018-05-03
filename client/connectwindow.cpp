#include "connectwindow.h"

#include "ui_connectwindow.h"
#include "startwindow.h"
#include "mainwindow.h"
#include "qhoversensitivebutton.h"
#include <QRegExp>

ConnectWindow::ConnectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->loginPage);

    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
}

ConnectWindow::~ConnectWindow()
{
    delete ui;
}


void ConnectWindow::on_loginButton_clicked()
{
    socket->connectToHost(ui->serverLineEdit->text(), 1234);
}


void ConnectWindow::on_sayButton_clicked()
{
    QString message = ui->sayLineEdit->text().trimmed();


    if(!message.isEmpty())
    {
        socket->write(QString(message).toUtf8());
    }


    ui->sayLineEdit->clear();

    ui->sayLineEdit->setFocus();
}

// This function gets called whenever the chat server has sent us some text:
void ConnectWindow::readyRead()
{

    /*while(socket->canReadLine())
    {
        // Here's the line the of text the server sent us (we use UTF-8 so
        // that non-English speakers can chat in their native language)
        QString line = QString::fromUtf8(socket->readLine()).trimmed();

        // These two regular expressions describe the kinds of messages
        // the server can send us:

        //  Normal messges look like this: "username:The message"
        QRegExp messageRegex("^([^:]+):(.*)$");

        // Any message that starts with "/users:" is the server sending us a
        // list of users so we can show that list in our GUI:
        QRegExp usersRegex("^/users:(.*)$");

        // Is this a users message:
        if(usersRegex.indexIn(line) != -1)
        {
            // If so, udpate our users list on the right:
            QStringList users = usersRegex.cap(1).split(",");
            ui->userListWidget->clear();
            foreach(QString user, users)
                new QListWidgetItem(QPixmap(":/user.png"), user, ui->userListWidget);
        }
        // Is this a normal chat message:
        else if(messageRegex.indexIn(line) != -1)
        {
            // If so, append this message to our chat box:
            QString user = messageRegex.cap(1);
            QString message = messageRegex.cap(2);

            ui->roomTextEdit->append("<b>" + user + "</b>: " + message);
        }
    }
    */
}

// This function gets called when our socket has successfully connected to the chat
// server. (see the connect() call in the ConnectWindow constructor).
void ConnectWindow::connected()
{
    // Flip over to the chat page:
    ui->stackedWidget->setCurrentWidget(ui->chatPage);


}
