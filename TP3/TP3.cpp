/**
* AUTEUR: Alexis Provost
* FICHIER: TP3.cpp
* DESCRIPTION: TP3
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "C:\\cvm.h"

using namespace std;

void main(void) {
	float MontantInitial, MontantConverti, MontantCanadien;
	char DeviseInitiale, DeviseConversion;

	const float DOLLAR = 1.0193, EURO = 1.3581, BAHT = 0.03311, ROUPIE = 0.01971, COURONNE = 0.1826;

	//Support des accents
	locale::global(locale{ "" });

	cout << "Entrez le montant à convertir : ";
	cin >> MontantInitial;

	cout << '\n' << "Entrez la devise de ce montant : " 
		<< '\n' << '\t' << "$ -> Dollar CAD"
		<< '\n' << '\t' << "D -> Dollar USD"
		<< '\n' << '\t' << "E -> Euro"
		<< '\n' << '\t' << "B -> Baht (Thaïlande)"
		<< '\n' << '\t' << "R -> Roupie(Inde)"
		<< '\n' << '\t' << "C -> Couronne (Danemark)";

	cout << '\n' << '\n' << "    Votre choix : ";

	DeviseInitiale = _getche();

	DeviseInitiale = toupper(DeviseInitiale);

	if (DeviseInitiale == 'D') {
		MontantCanadien = MontantInitial * DOLLAR;
	}
	else if(DeviseInitiale == 'E') {
		MontantCanadien = MontantInitial * EURO;
	}
	else if (DeviseInitiale == 'B') {
		MontantCanadien = MontantInitial * BAHT;
	}
	else if (DeviseInitiale == 'R') {		
		MontantCanadien = MontantInitial * ROUPIE;
	}
	else if (DeviseInitiale == 'C') {
		MontantCanadien = MontantInitial * COURONNE;
	}
	else {
		MontantCanadien = MontantInitial;
	}

	cout << '\n' << '\n' << "Entrez la devise dans laquelle on fera la conversion : "
		<< '\n' << '\t' << "$ -> Dollar CAD"
		<< '\n' << '\t' << "D -> Dollar USD"
		<< '\n' << '\t' << "E -> Euro"
		<< '\n' << '\t' << "B -> Baht (Thaïlande)"
		<< '\n' << '\t' << "R -> Roupie(Inde)"
		<< '\n' << '\t' << "C -> Couronne (Danemark)";

	cout << '\n' << '\n' << "    Votre choix : ";

	DeviseConversion = _getche();

	DeviseConversion = toupper(DeviseConversion);

	if (DeviseConversion == 'D') {
		MontantConverti = MontantCanadien / DOLLAR;
	}
	else if (DeviseConversion == 'E') {
		MontantConverti = MontantCanadien / EURO;
	}
	else if (DeviseConversion == 'B') {
		MontantConverti = MontantCanadien / BAHT;
	}
	else if (DeviseConversion == 'R') {
		MontantConverti = MontantCanadien / ROUPIE;
	}
	else if (DeviseConversion == 'C') {
		MontantConverti = MontantCanadien / COURONNE;
	}
	else {
		MontantConverti = MontantCanadien;
	}

	cout << '\n' << '\n' << '\n' << '\t' << "Montant initial :" << setw(10) << right << MontantInitial << " " << DeviseInitiale << endl;
	cout << '\t' << "Montant converti:" << setw(10) << right << MontantConverti << " " << DeviseConversion;

	_getch();
}