/**
* AUTEUR: Alexis Provost
* FICHIER: TP5.cpp
* DESCRIPTION: TP5
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <math.h>
#include "C:\\cvm.h"

using namespace std;

void main(void) {

	int Roll, NumberOfRolls, Rolled1, Rolled2, Rolled3, Rolled4, Rolled5, Rolled6;

	locale::global(locale{ "fr-CA" });

	NumberOfRolls = 0, Rolled1 = 0, Rolled2 = 0, Rolled3 = 0, Rolled4 = 0, Rolled5 = 0, Rolled6 = 0;

	for (int i = 0; i <= 6; i++)
	{
		srand(time(0));
		for (int j = 0; j < pow(10,i); j++)
		{
			Roll = rand() % (6 - 1 + 1) + 1;

			if (Roll == 1) {
				Rolled1++;
			}
			else if (Roll == 2) {
				Rolled2++;
			}
			else if (Roll == 3) {
				Rolled3++;
			}
			else if (Roll == 4) {
				Rolled4++;
			}
			else if (Roll == 5) {
				Rolled5++;
			}
			else if (Roll == 6) {
				Rolled6++;
			}

			NumberOfRolls = j + 1;
		}

		cout << '\n' << "Essai avec " << (int)pow(10, i) << " lancer:"
			<< '\n' << '\n' << setw(4) << right << "Face" << setw(13) << right << "Fréquence" << setw(15) << right << "Pourcentage"
			<< '\n' << setw(4) << right << "1" << setw(13) << right << Rolled1 << setw(14) << right << fixed << setprecision(2) << (float)((Rolled1 * 100) / NumberOfRolls) << "%"
			<< '\n' << setw(4) << right << "2" << setw(13) << right << Rolled2 << setw(14) << right << fixed << setprecision(2) << (float)((Rolled2 * 100) / NumberOfRolls) << "%"
			<< '\n' << setw(4) << right << "3" << setw(13) << right << Rolled3 << setw(14) << right << fixed << setprecision(2) << (float)((Rolled3 * 100) / NumberOfRolls) << "%"
			<< '\n' << setw(4) << right << "4" << setw(13) << right << Rolled4 << setw(14) << right << fixed << setprecision(2) << (float)((Rolled4 * 100) / NumberOfRolls) << "%"
			<< '\n' << setw(4) << right << "5" << setw(13) << right << Rolled5 << setw(14) << right << fixed << setprecision(2) << (float)((Rolled5 * 100) / NumberOfRolls) << "%"
			<< '\n' << setw(4) << right << "6" << setw(13) << right << Rolled6 << setw(14) << right << fixed << setprecision(2) << (float)((Rolled6 * 100) / NumberOfRolls) << "%" << endl;

		cout << '\n' << '\t' << '\t' << '\t' << "Pressez une touche pour continuez";

		_getch();

		clrscr();
	}
	MessageBoxA(NULL, "AU REVOIR!", "Fin du programme", MB_OK | MB_ICONINFORMATION);
}