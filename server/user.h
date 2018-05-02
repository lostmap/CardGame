#ifndef USER_H
#define USER_H

#include <QString>


class User
{
public:
    User(QString login, QString password);
    QString getLogin(){
        return _login;
    }

    QString getPassword(){
        return _password;
    }

private:
    QString _password;
    QString _login;

};

#endif // USER_H
