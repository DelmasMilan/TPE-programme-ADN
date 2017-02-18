#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class visualisation
{
public:
	visualisation();
	~visualisation();
	void start(std::string m_nucleoChainA, std::string m_nucleoChainB); // on r�cup�re ici deux attributs qui sont les chaines de nucl�otides
	void fillVec();
private:
	sf::RenderWindow window;
};

