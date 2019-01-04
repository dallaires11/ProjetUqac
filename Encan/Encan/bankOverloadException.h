#pragma once
#include<exception>
#include"SuperErreur.h"
#include"erreurType.h"
class bankOverloadException : public std::exception, public SuperErreur, public erreurType {
public:
	const char * what() const throw () {
		return "La bnaque n'acceptera pas plus d'argent aujourd'hui";
	}
};
