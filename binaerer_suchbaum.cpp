//#include "binaerer_suchbaum.h"
#include <iostream>

namespace fluchbaeumle
{
	struct BaumKot
	{
		int data;
		BaumKot *vater;
		BaumKot *kleinerbruder;
		BaumKot *grosserbruder; //skurr
	};

	void einfuegen(BaumKot *&anker, int wert)
	{
		BaumKot *ptr = anker;
		if (anker == nullptr)	//falls liste leer, füge neuen wert hinzu
		{
			BaumKot *neuer_eintrag = new BaumKot;
			neuer_eintrag->vater = nullptr;
			neuer_eintrag->data = wert;
			neuer_eintrag->kleinerbruder = nullptr;
			neuer_eintrag->grosserbruder = nullptr;
			anker = neuer_eintrag;
		}
		else if (ptr->data == wert)
		{
			return;
		}
		else if (ptr->data > wert)
		{
			if (ptr->kleinerbruder != nullptr)
			{
				einfuegen(ptr->kleinerbruder, wert);
			}
			else
			{
				BaumKot *neuer_eintrag = new BaumKot;
				neuer_eintrag->vater = ptr;
				neuer_eintrag->data = wert;
				neuer_eintrag->kleinerbruder = nullptr;
				neuer_eintrag->grosserbruder = nullptr;
				ptr->kleinerbruder = neuer_eintrag;
			}
		}
		else if (ptr->data < wert)
		{
			if (ptr->grosserbruder != nullptr)
			{
				einfuegen(ptr->grosserbruder, wert);
			}
			else
			{
				BaumKot *neuer_eintrag = new BaumKot;
				neuer_eintrag->vater = ptr;
				neuer_eintrag->data = wert;
				neuer_eintrag->kleinerbruder = nullptr;
				neuer_eintrag->grosserbruder = nullptr;
				ptr->grosserbruder = neuer_eintrag;
			}
		}
	}

	//void ausgabe(BaumKot *&anker)
	//{
	//	int tiefe = 0;
	//	BaumKot *ptr = anker;
	//	if (anker == nullptr)
	//	{
	//		std::cout << "Leerer Baum." << std::endl;
	//	}
	//	else
	//	{
	//		while (ptr->grosserbruder != nullptr)
	//		{
	//			tiefe += 1;
	//			ptr = ptr->grosserbruder;
	//		}
	//		for (int i = 0; i < tiefe; i++)
	//		{
	//			std::cout << "++";
	//		}
	//		std::cout << ptr->data;

	//	}
	//}

	//void ausgabeEinzel(int tiefe, BaumKot *&anker)
	//{
	//	BaumKot *ptr = anker;
	//	for (int i = 0; i < tiefe; i++)
	//	{
	//		std::cout << "++";
	//	}
	//	std::cout << ptr->data;
	//}

	void ausgabeKnoten(BaumKot *knoten)
	{
		if (knoten == nullptr)
		{
			return;
		}
		else
		{
			ausgabeKnoten(knoten->grosserbruder);
			std::cout << knoten->data << std::endl;
			ausgabeKnoten(knoten->kleinerbruder);
		}
	}

	void ausgabe(BaumKot *anker)
	{
		BaumKot *ptr = anker;
		if (anker == nullptr)
		{
			std::cout << "Leerer Baum." << std::endl;
		}
		else
		{
			ausgabeKnoten(anker);
		}
	}
}