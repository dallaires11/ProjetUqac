#include "Operateur.h"

Operateur::Operateur(TimeKeeper* tk){
	this->tk = tk;
}

Operateur::~Operateur(){}

void Operateur::run() {
	try {
		while (true) {
			if (Encanteur::venteReussi>= 10)
				throw bankOverloadException();
			if (tk->getTime()>=100)
				throw nightTimeException();
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << tk->getTime()<<"\n";
		}
	}
	catch (bankOverloadException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (nightTimeException e) {
		std::cout << e.what() << std::endl;
	}
}