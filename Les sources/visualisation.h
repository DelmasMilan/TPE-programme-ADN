#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class visualisation
{
public:
	visualisation();
	~visualisation();
	void start(std::string m_nucleoChainA, std::string m_nucleoChainB); // on récupère ici deux attributs qui sont les chaines de nucléotides
	void fillVec();
private:
	sf::RenderWindow window;
};

