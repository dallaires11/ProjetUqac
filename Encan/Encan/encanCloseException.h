#pragma once
#include<exception>
#include"SuperErreur.h"
#include"erreurType.h"
class encanCloseException : public std::exception, public SuperErreur, public erreurType {
	public:
	const char * what() const throw () {
		return "Mon produit n'est plus disponible :(";
	}
};

