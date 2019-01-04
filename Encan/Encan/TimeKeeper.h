#pragma once
#include<thread>
#include"Encan.h"
class TimeKeeper{
private:
	static int instanceTimeKeeper;

	int temps;
	std::thread comportement;
	bool running;

	void updateTime();
	void run();
public:
	TimeKeeper();
	~TimeKeeper();

	int getTime() {
		return temps;
	}

	void start();
	void stop();
};

