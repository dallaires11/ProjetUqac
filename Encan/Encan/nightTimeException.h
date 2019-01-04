#pragma once
#include<exception>
#include"SuperErreur.h"
#include"erreurType.h"
class nightTimeException : public std::exception, public SuperErreur, public erreurType {
	public:
	const char * what() const throw () {
		return "La nuit est arrive c'est le temps de fermer";
	}
};

