#ifndef USER_H
#define USER_H

#include <string>


class User
{
public:
    User(std::string login);
    std::string getLogin();
    std::string getPassword();
    

private:
    std::string _login;

};

#endif // USER_H
