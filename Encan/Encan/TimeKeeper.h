#pragma once
#include<thread>
#include"Encan.h"
class TimeKeeper{
private:
	static int instanceTimeKeeper;

	std::thread comportement;
	bool running;

	void updateTime();
	void run();
public:
	TimeKeeper();
	~TimeKeeper();

	void start();
	void stop();
};

