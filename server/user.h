#ifndef USER_H
#define USER_H

#include <string>

class User
{
public:
    User(std::string login, std::string password);
    std::string getLogin() const;

    std::string getPassword() const;

    bool checkPassword(std::string) const;

private:
    std::string _login;
    std::string _password;

};

#endif // USER_H
