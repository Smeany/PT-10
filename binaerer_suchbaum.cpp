#include <iostream>
#include "binaerer_suchbaum.h"

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

void ausgabeKnoten(BaumKot *knoten, int aktuelleTiefe)
{
	if (knoten == nullptr)
	{
		return;
	}
	else
	{
		// Die Kinderknoten bekommen Tiefe+1.
		ausgabeKnoten(knoten->grosserbruder, aktuelleTiefe+1);

		// Entsprechend der aktuellen Tiefe sternchen hinzufügen.
		for (int i = 0; i < aktuelleTiefe; i++)
		{
			std::cout << "**";
		}
		std::cout << knoten->data << std::endl;

		// Die Kinderknoten bekommen Tiefe+1.
		ausgabeKnoten(knoten->kleinerbruder, aktuelleTiefe+1);
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
		// Der oberste Vaterknoten ist tiefe 0.
		ausgabeKnoten(anker, 0);
	}
}
