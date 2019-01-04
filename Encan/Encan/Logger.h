#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include"MiniLog.h"

class Logger{
private:
	static Logger* instance;
	std::ofstream outFile;

	Logger();
public:
	static Logger* getInstance();

	void newLog(std::string,std::string,int);
	void newLog(std::string);
	void fermer();
};