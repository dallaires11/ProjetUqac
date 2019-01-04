#pragma once
#include <string>
template <class T>
class MiniLog {
public:
	std::string getLittleInfo(T test) {
		if (test != NULL)
			return "Demarage de logger";
		else
			return "Erreur erreur erreur";
	}
};