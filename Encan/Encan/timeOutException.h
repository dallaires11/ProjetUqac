#pragma once
#include<exception>
#include"SuperErreur.h"
#include"erreurType.h"
class timeOutException : public std::exception , public SuperErreur, public erreurType {
	public:
	const char * what() const throw () {
		return "L'encan a atteint son echance";
	}
};
