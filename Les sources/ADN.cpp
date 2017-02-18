#include "stdafx.h" // en-t�tes pr�compil�es de visual studio, notre IDE (interface de d�veloppement)
#include <iostream> // fonctions standard d'entr�es et sorties console
#include <string> // pour avoir acc�s aux fonctions de chaines dynamiques (les "strings")
#include <Windows.h> // pour pouvoir faire "dormir" le programme ainsi que tester les entr�es claviers sans cout ou cin
#include "visualisation.h" // notre autre partie de code utilis�e � la fin pour visualiser l'ADN

using namespace std; // en C++ le namespace sert � ne pas avoir � indiquer les fonctions issues d'includes les plus utilis�s, ici les fonctions des includes standards

void printTextToBin(string charChain); // d�claration des prototypes en amont afin de pouvoir visualiser la fonction main en premier
void printBinToNucleo(string binChain);// sinon nous aurions du cr�er les fonctions au dessus de la fonction main pour aider le compilateur

string binChain, nucleoChainA, nucleoChainB;// en variable globale pour ne pas avoir � mettre trop d'arguments ou de fonctions en chaine


int main()
{
	string charChain;
	char eAccentGrave = 138, eAccentAigu = 130, eAccentCirc = 136; // nous aidons la console � afficher les accents car ils font partis d'une version �tendue de l'ASCII, et le compilateur peut mal interpr�ter nos accents
	cout << "Bonjour, veuillez rentrer une chaine de caract" << eAccentGrave << "res afin de commencer un exemple de conversion" << endl << endl;
	getline(cin,charChain); cout << endl << "Correspondance binnaire : ";
	printTextToBin(charChain);
	cout << "Correspondance en nucl" << eAccentAigu << "otides : " << endl;
	printBinToNucleo(binChain);
	cout << endl << "appuyez sur ENTER pour lancer la fen" << eAccentCirc << "tre de visualisation" << endl;
	while (GetAsyncKeyState(0x0D)) // on attend une premi�re fois que l'utilisateur lache la touche entr�e
		Sleep(1); // pour relacher le cpu, il est inutile de v�rifier la touche des millions de fois par seconde
	while (!GetAsyncKeyState(0x0D)) // 0x0D = touche entr�e (quand l'utilisateur r�appuie pour confirmer
		Sleep(1); // de m�me, nous relachons le CPU
	visualisation maVisualisation; // cr�er une classe de visualisation, permettant de s�parer les codes.
	maVisualisation.start(nucleoChainA, nucleoChainB); // nous donnons l'ordre de lancer la visualisation en donnant nos chaines obtenues. Cette partie du programme continuera pour fermer la console � la fin du programme de visualisation
    return 0;
}

void printTextToBin(string charChain) // notre fonction permettant la conversion de texte en binaire ainsi que l'affichage
{
	char currentChar = NULL;
	const int chainSize = charChain.size();
	for (int i = 0; i < chainSize; i++)
	{
		currentChar = charChain[i];
		for (int j = 7; j >= 0; j--) // on commence avec j � 7 car nous partons de gauche, comme le sens de lecture conventionnel
		{
			if (currentChar & (1u << j)) // ligne importante, voir ducomentation
			{
				binChain.push_back('1');
			}
			else 
			{
				binChain.push_back('0');
			}
		}
	}
	cout << binChain << endl << endl;
}

void printBinToNucleo(string binChain) // notre fonction permettant de convertir le "faux binaire" en deux chaines azot�es et de les afficher s�par�ment
{
	char currentBit[2];
	const int chainSize = binChain.size();
	for (int i = 0; i < chainSize; i++)
	{
		currentBit[0] = binChain[i];
		i++;
		currentBit[1] = binChain[i];
		if (currentBit[0] == '0')				// quand le premier bit est 0
		{
			if (currentBit[1] == '0')			// 00 = AT
			{
				nucleoChainA.push_back('A');
				nucleoChainB.push_back('T');
			}
			else								// 01 = TA
			{
				nucleoChainA.push_back('T');
				nucleoChainB.push_back('A');
			}
		}	
		else									// quand le premier bit est 1
		{
			if (currentBit[1] == 0)
			{
				nucleoChainA.push_back('G');	// 10 = GC
				nucleoChainB.push_back('C');
			}
			else
			{
				nucleoChainA.push_back('C');	// 11 = CG
				nucleoChainB.push_back('G');
			}
		}
	}
	cout << "chaine 1 : " << nucleoChainA << endl << "chaine 2 : " << nucleoChainB << endl;
}