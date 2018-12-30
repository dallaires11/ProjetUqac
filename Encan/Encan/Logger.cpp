#include "Logger.h"

Logger* Logger::instance = 0;

Logger::Logger(){
	outFile.open("transaction.log", std::ios::out | std::ios::trunc);
}

Logger* Logger::getInstance() {
	if (instance == 0) {
		instance = new Logger();
	}
	return instance;
}

void Logger::newLog() {
	outFile << "eee" << std::endl;
}

void Logger::fermer() {
	outFile.close();
}