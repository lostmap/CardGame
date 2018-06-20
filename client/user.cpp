#include "user.h"

#include <cstdlib>
#include <ctime>

User::User(std::string login):
    _login(login)
{

}


 
std::string User::getLogin() {
	std::srand(unsigned(std::time(0)));
	return "lostmap" + std::to_string(std::rand() % 50);
	//return "lostmap";
}

std::string User::getPassword() {
	return "12345";
}
