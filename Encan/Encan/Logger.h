#pragma once
#include<fstream>
#include<iostream>

class Logger{
private:
	static Logger* instance;
	std::ofstream outFile;

	Logger();
public:
	static Logger* getInstance();

	void newLog();
	void fermer();
};