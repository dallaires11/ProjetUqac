#pragma once
class UsineTraitement{
private:
	static int instanceUsine;
public:
	UsineTraitement();
	~UsineTraitement();

	static const int getNbInstance() {
		return UsineTraitement::instanceUsine;
	}
};