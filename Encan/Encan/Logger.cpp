#include "Logger.h"

Logger* Logger::instance = 0;

Logger::Logger(){
	outFile.open("transaction.log", std::ios::out | std::ios::trunc);
	MiniLog<int>* minilog = new MiniLog<int>();
	minilog->getLittleInfo(1);
	delete minilog;
}

Logger* Logger::getInstance() {
	if (instance == 0) {
		instance = new Logger();
	}
	return instance;
}

void Logger::newLog(std::string nom,std::string vente, int montant) {
	outFile << "L'acheteur " << nom << " a debourse " << montant << "$ pour la vente de " << vente << std::endl;
} 

void Logger::newLog(std::string description) {
	outFile << "La vente de " << description <<" est arrive a echeance sans acheteur" << std::endl;
}

void Logger::fermer() {
	outFile.close();
}