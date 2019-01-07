#include <iostream>
#include <string>
#include "binaerer_suchbaum.h"
using namespace std;
//using namespace fluchbaeumle;

int main()
{
	fluchbaeumle::BaumKot *anker = nullptr;
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
			fluchbaeumle::einfuegen(anker, eingabe);
		}
	}
	while (true);

	fluchbaeumle::ausgabe(anker);

	system("PAUSE");
	return 0;
}