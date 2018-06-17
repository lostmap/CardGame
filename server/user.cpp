#include "user.h"

User::User(std::string login, std::string password):
    _login(login), _password(password)
{

}

bool User::checkPassword(std::string password) const
{
    return _password == password;
}

std::string User::getLogin() const {
    return _login;
}

std::string User::getPassword() const{
    return _password;
}
