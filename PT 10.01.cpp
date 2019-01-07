#include <string>
#include <iostream>
#include "binaerer_suchbaum.h"
using namespace std;

int main()
{
	BaumKot *anker = nullptr;
	do
	{
		int eingabe = 0;
		std::cout << "Naechster Wert(99 beendet) : ? ";
		std::cin >> eingabe;
		if (eingabe == 99)
		{
			break;
		}
		else
		{
			einfuegen(anker, eingabe);
		}
	} while (true);

	ausgabe(anker);

	system("PAUSE");
	return 0;
}