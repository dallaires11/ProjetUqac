#include "MaitreEncan.h"

MaitreEncan::MaitreEncan(){
	Encan::getInstance();
	Logger::getInstance();
	salleAtt = new SalleAttente();
	bouncer = new Bouncer(salleAtt);
	tk = new TimeKeeper();
	aFactory = new AcheteurFactory(salleAtt);
	vFactory = new VendeurFactory(salleAtt);

	ouvertureEncan();
}

MaitreEncan::~MaitreEncan(){
	delete bouncer;
	delete aFactory;
	delete vFactory;
	delete tk;
	delete salleAtt;
	Encan::getInstance()->fermeture();
	cout << Acheteur::getNbInstance() << " " << Vendeur::getNbInstance() << " " << Objet::getNbInstance() << endl;
	Logger::getInstance()->fermer();
}

void MaitreEncan::ouvertureEncan() {
	aFactory->start();
	vFactory->start();
	std::this_thread::sleep_for(std::chrono::seconds(10));
	bouncer->start();
	tk->start();
	std::this_thread::sleep_for(std::chrono::seconds(30));
	tk->stop();
	bouncer->stop();
	aFactory->stop();
	vFactory->stop();
	salleAtt->getSize();
	cout << Acheteur::getNbInstance() << " " << Vendeur::getNbInstance() << " " << Objet::getNbInstance() << endl;
	cout << Encan::getInstance()->tailleEnchereAntique << " " << Encan::getInstance()->tailleEnchereArt << " " << Encan::getInstance()->tailleEnchereService << endl;
}