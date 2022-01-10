
/**
* AUTEUR: Alexis Provost
* FICHIER: TP6.cpp
* DESCRIPTION: TP6
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <string>
#include <stdlib.h> 
#include <math.h>
#include <time.h>
#include "C:\\cvm.h"

using namespace std;

void main(void) {
	string Password1, Password2;
	char Letter;
	time_t NbSecondes;
	int SpacingX, SpacingY;

	locale::global(locale{ "fr-CA" });

	SpacingX = 0, SpacingY = 0;

	for (size_t i = 0; i < 10; i++)
	{
		cout << "\n";
	}

	cout << '\t' << '\t' << '\t' << "Entrer votre mot de passe (6 caractères):" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "xxxxxx";

	while ((Password1 != Password2) || (Password1.size() < 6 && Password2.size() < 6)) {

		Password1 = "", Password2 = "";

		for (size_t i = 0; i < 6; i++)
		{
			gotoxy(40 + i, 11);

			Password1 += _getch();

			cout << '*';
		}

		clrscr();

		for (size_t i = 0; i < 10; i++)
		{
			cout << "\n";
		}

		cout << '\t' << '\t' << '\t' << "Taper votre mot de passe encore une fois:" << endl;
		cout << '\t' << '\t' << '\t' << '\t' << '\t' << "xxxxxx";

		for (size_t i = 0; i < 6; i++)
		{
			gotoxy(40 + i, 11);

			Password2 += _getch();

			cout << '*';
		}

		clrscr();

		for (size_t i = 0; i < 10; i++)
		{
			cout << "\n";
		}

		cout << '\t' << '\t' << '\t' << "Recommencez, vous devez entrer le même mot deux fois:" << endl;
		cout << '\t' << '\t' << '\t' << '\t' << '\t' << "xxxxxx";
	}

	clrscr();

	while (!_kbhit()) {
		SpacingX = abs((rand() % (120 - 1 + 1) + 1) - 32);
		SpacingY = abs((rand() % (20 - 1 + 1) + 1) - 5);

		for (size_t i = 0; i < SpacingY; i++)
		{
			cout << "\n";
		}

		for (size_t i = 0; i < SpacingX; i++)
		{
			cout << " ";
		}

		cout << "********************************\n";

		for (size_t i = 0; i < SpacingX; i++)
		{
			cout << " ";
		}

		cout << "*                              *\n";

		for (size_t i = 0; i < SpacingX; i++)
		{
			cout << " ";
		}

		cout << "*       Écran de Veille        *\n";

		for (size_t i = 0; i < SpacingX; i++)
		{
			cout << " ";
		}

		cout << "*                              *\n";


		for (size_t i = 0; i < SpacingX; i++)
		{
			cout << " ";
		}

		cout << "********************************";

		NbSecondes = time(NULL);

		while (time(NULL) < NbSecondes + 1) {
			//Nothing
		}
		
		clrscr();
	}

	clrscr();

	_getch();

	Password2 = "";

	while ((Password1 != Password2) || (Password1.size() < 6 && Password2.size() < 6)) {
		Password2 = "";

		clrscr();

		for (size_t i = 0; i < 10; i++)
		{
			cout << "\n";
		}

		cout << '\t' << '\t' << '\t' << '\t' << "Mot de passe: xxxxxx";

		for (size_t i = 0; i < 6; i++)
		{
			gotoxy(46 + i, 10);

			Password2 += _getch();

			cout << '*';
		}
	}
	
	for (size_t i = 0; i < 5; i++)
	{
		cout << "\n";
	}

	cout << '\t' << '\t' << '\t' << '\t' << "Connection réussi!";

	_getch();
}