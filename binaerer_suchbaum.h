struct BaumKot
{
	int data;
	BaumKot *vater;
	BaumKot *kleinerbruder;
	BaumKot *grosserbruder;
};

void einfuegen(BaumKot *&anker, int wert);

void ausgabe(BaumKot *anker);
