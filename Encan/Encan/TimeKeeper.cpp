#include "TimeKeeper.h"

int TimeKeeper::instanceTimeKeeper = 0;

TimeKeeper::TimeKeeper(){
	running = false;
}

TimeKeeper::~TimeKeeper(){}

void TimeKeeper::updateTime() {
	enchere* currentEnchere;
	currentEnchere = Encan::getInstance()->encheresAntique;
	while (currentEnchere != nullptr&&currentEnchere->encanteur != nullptr) {
		currentEnchere->encanteur->timeCheck();
		currentEnchere = currentEnchere->next;
	}
	currentEnchere = Encan::getInstance()->encheresArt;
	while (currentEnchere != nullptr&&currentEnchere->encanteur != nullptr) {
		currentEnchere->encanteur->timeCheck();
		currentEnchere = currentEnchere->next;
	}
	currentEnchere = Encan::getInstance()->encheresService;
	while (currentEnchere != nullptr&&currentEnchere->encanteur !=nullptr) {
		currentEnchere->encanteur->timeCheck();
		currentEnchere = currentEnchere->next;
	}
}

void TimeKeeper::start() {
	running = true;
	comportement = std::thread(&TimeKeeper::run, this);
}

void TimeKeeper::run() {
	while (running) {
		updateTime();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void TimeKeeper::stop() {
	running = false;
	comportement.join();
}