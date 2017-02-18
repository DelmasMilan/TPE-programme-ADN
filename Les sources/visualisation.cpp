#include "stdafx.h"
#include "visualisation.h"
#include <iostream>

void visualisation::start(std::string m_nucleoChainA, std::string m_nucleoChainB) // boucle principale
{
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		/*Partie où l'on charge les textures ci-dessous*/
		sf::Texture textureNuclA;
		if (!textureNuclA.loadFromFile("textures/nuclA.bmp"))
			std::cout << "erreur lors du chargement de textures/nuclA.bmp" << std::endl;

		sf::Texture textureNuclT;
		if (!textureNuclT.loadFromFile("textures/nuclT.bmp"))
			std::cout << "erreur lors du chargement de textures/nuclT.bmp" << std::endl;

		sf::Texture textureNuclC;
		if (!textureNuclC.loadFromFile("textures/nuclC.bmp"))
			std::cout << "erreur lors du chargement de textures/nuclC.bmp" << std::endl;

		sf::Texture textureNuclG;
		if (!textureNuclG.loadFromFile("textures/nuclG.bmp"))
			std::cout << "erreur lors du chargement de textures/nuclG.bmp" << std::endl;

		sf::Texture textureSaca;
		if (!textureSaca.loadFromFile("textures/saca.bmp"))
			std::cout << "erreur lors du chargement de textures/saca.bmp" << std::endl;

		sf::Texture texturePhos;
		if (!texturePhos.loadFromFile("textures/phos.bmp"))
			std::cout << "erreur lors du chargement de textures/phos.bmp" << std::endl;

		sf::Texture texturePink;
		if (!texturePink.loadFromFile("textures/pink.bmp"))
			std::cout << "erreur lors du chargement de textures/pink.bmp" << std::endl;

		sf::Texture textureGrey;
		if (!textureGrey.loadFromFile("textures/grey.bmp"))
			std::cout << "erreur lors du chargement de textures/grey.bmp" << std::endl;

		/*Fin de la partie des textures*/

		/*Début de la génération de la molécule*/
		sf::CircleShape nuclA(32);
		sf::CircleShape nuclT(32);
		sf::CircleShape nuclC(32);
		sf::CircleShape nuclG(32);
		sf::CircleShape saca(32);
		sf::CircleShape phos(16);
		nuclA.setTexture(&textureNuclA);
		nuclT.setTexture(&textureNuclT);
		nuclC.setTexture(&textureNuclC);
		nuclG.setTexture(&textureNuclG);
		saca.setTexture(&textureSaca);
		phos.setTexture(&texturePhos);

		std::vector<sf::CircleShape> array_Mol(0);
		std::vector<sf::VertexArray> array_Links(0);
		int linksArrayLength = NULL;
		std::vector<sf::VertexArray> array_LinksSaca(0);
		int linksSacaArrayLength = NULL;
		std::vector<sf::VertexArray> array_LinksPhos(0);
		int linksPhosArrayLength = NULL;

		sf::VertexArray linkNucl(sf::Quads, 4);
		sf::VertexArray linkSaca(sf::Quads, 4);
		sf::VertexArray linkPhos(sf::Quads, 4);

		float relPos = NULL;
		int nuclArrayLength = m_nucleoChainA.size();
		int molArrayLength = nuclArrayLength << 1u;
		int relPosLeft, relPosRight; // pour ne pas recalculer à chaque vertex
		for (int i = 0; i < nuclArrayLength; i++) // première chaine de nucléotides
		{
			relPosLeft = relPos + 29;
			relPosRight = relPos + 35;
			linkNucl[0].position = sf::Vector2f((relPosLeft), 282); // largeur de 6 pixels
			linkNucl[1].position = sf::Vector2f((relPosRight), 282);
			linkNucl[2].position = sf::Vector2f((relPosRight), 482);
			linkNucl[3].position = sf::Vector2f((relPosLeft), 482);
			array_Links.push_back(linkNucl);
			linksArrayLength++;
			if (m_nucleoChainA[i]=='A')
				{
					nuclA.setPosition(relPos, 250);
					array_Mol.push_back(nuclA);
				}
			else if (m_nucleoChainA[i] =='T')
				{
					nuclT.setPosition(relPos, 250);
					array_Mol.push_back(nuclT);
				}
			else if (m_nucleoChainA[i] == 'C')
				{
					nuclC.setPosition(relPos, 250);
					array_Mol.push_back(nuclC);
				}
			else //if (m_nucleoChainA[i] == 'G')
				{
					nuclG.setPosition(relPos, 250);
					array_Mol.push_back(nuclG);
				}
				saca.setPosition(relPos, 150);
				array_Mol.push_back(saca);
				molArrayLength ++;
				linkSaca[0].position = sf::Vector2f((relPosLeft), 182);
				linkSaca[1].position = sf::Vector2f((relPosRight), 182);
				linkSaca[2].position = sf::Vector2f((relPosRight), 282);
				linkSaca[3].position = sf::Vector2f((relPosLeft), 282);
				array_LinksSaca.push_back(linkSaca);
				linksSacaArrayLength++;
				if (nuclArrayLength > (i+1))
				{
					phos.setPosition((relPos + 91), 100);
					array_Mol.push_back(phos);
					molArrayLength ++;
					linkPhos[0].position = sf::Vector2f((relPos + 14), 182); //recalcul de la relPos pour une largeur plus fine
					linkPhos[1].position = sf::Vector2f((relPos + 18), 182);
					linkPhos[2].position = sf::Vector2f((relPos + 105), 116);
					linkPhos[3].position = sf::Vector2f((relPos + 109), 116);
					array_LinksPhos.push_back(linkPhos);
					linkPhos[0].position = sf::Vector2f((relPos +105), 116);
					linkPhos[1].position = sf::Vector2f((relPos +109), 116);
					linkPhos[2].position = sf::Vector2f((relPos +200), 182);
					linkPhos[3].position = sf::Vector2f((relPos +196), 182);
					array_LinksPhos.push_back(linkPhos);
					linksPhosArrayLength+=2;
				}
				relPos += 150;
		}
		relPos = NULL;
		for (int i = 0; i < nuclArrayLength; i++) // deuxième chaine de nucléotides
		{
			relPosLeft = relPos + 29;
			relPosRight = relPos + 35;
			if (m_nucleoChainB[i] == 'A')
			{
				nuclA.setPosition(relPos, 450);
				array_Mol.push_back(nuclA);
			}
			else if (m_nucleoChainB[i] == 'T')
			{
				nuclT.setPosition(relPos, 450);
				array_Mol.push_back(nuclT);
			}
			else if (m_nucleoChainB[i] == 'C')
			{
				nuclC.setPosition(relPos, 450);
				array_Mol.push_back(nuclC);
			}
			else //if (m_nucleoChainB[i] == 'G')
			{
				nuclG.setPosition(relPos, 450);
				array_Mol.push_back(nuclG);
			}
			saca.setPosition(relPos, 550);
			array_Mol.push_back(saca);
			molArrayLength ++;
			linkSaca[0].position = sf::Vector2f((relPosLeft), 482);
			linkSaca[1].position = sf::Vector2f((relPosRight), 482);
			linkSaca[2].position = sf::Vector2f((relPosRight), 582);
			linkSaca[3].position = sf::Vector2f((relPosLeft), 582);
			array_LinksSaca.push_back(linkSaca);
			linksSacaArrayLength++;
			if (nuclArrayLength > (i+1))
			{
				phos.setPosition((relPos + 91), 632);
				array_Mol.push_back(phos);
				molArrayLength ++;
				linkPhos[0].position = sf::Vector2f((relPos + 14), 582); //recalcul de la relPos pour une largeur plus fine
				linkPhos[1].position = sf::Vector2f((relPos + 18), 582);
				linkPhos[2].position = sf::Vector2f((relPos + 105), 648);
				linkPhos[3].position = sf::Vector2f((relPos + 109), 648);
				array_LinksPhos.push_back(linkPhos);
				linkPhos[0].position = sf::Vector2f((relPos + 105), 648);
				linkPhos[1].position = sf::Vector2f((relPos + 109), 648);
				linkPhos[2].position = sf::Vector2f((relPos + 200), 582);
				linkPhos[3].position = sf::Vector2f((relPos + 196), 582);
				array_LinksPhos.push_back(linkPhos);
				linksPhosArrayLength += 2;
			}
			relPos += 150;
		}
		sf::RenderWindow window(sf::VideoMode(1200, 800), "Visualisation de la moclécule séquencée", sf::Style::Default, settings);
		window.setVerticalSyncEnabled(1);
		sf::Time timeElapsed;
		sf::Clock clock;
		while (window.isOpen())
		{
			sf::Event event;
			timeElapsed = clock.restart();
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			
			for (int i = 0; i < linksArrayLength; i++) // on dessine les liaisons qui sont recouvertes par la suite
				window.draw(array_Links[i]);

			for (int i = 0; i < linksSacaArrayLength; i++)
				window.draw(array_LinksSaca[i], &texturePink);

			for (int i = 0; i < linksPhosArrayLength; i++)
				window.draw(array_LinksPhos[i], &textureGrey);

			for (int i = 0; i < molArrayLength; i++) // par les composants moléculaires
				window.draw(array_Mol[i]);
			
			window.display();
		}
}

visualisation::visualisation()
{
}


visualisation::~visualisation()
{
}

