/********************************************************
* AUTEUR: Alexis Provost
* FICHIER: TP1.cpp
* DESCRIPTION: TP1
********************************************************/

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

void main(void) {
	char Carac = 'A';
	int Entier = 75000;
	short EntierCourt = -42;
	long EntierLong = 57000;
	string Nom, Prenom;
	float Reel = 123.456;
	double ReelDouble = 12.0123456789;
	unsigned int SansSigne = 54321;

	//Support des accents
	locale::global(locale{ "" });

	cout << '\t' << '\t' << "Travail pratique 1 - Pour le cours de Programmation I";

	cout << '\n' << '\n' << "Taper votre nom : ";
	cin >> Nom;

	cout << "Taper votre prénom : ";
	cin >> Prenom;

	cout << '\n' << "Essai du cadrage à gauche et de la notation en virgule flottante:" << '\n';

	cout << left << setw(8) << Entier
		<< left << setw(8) << EntierCourt
		<< left << setw(8) << EntierLong
		<< left << setw(8) << SansSigne
		<< left << setw(8) << Carac
		<< '\n' << fixed << setprecision(2) << left << setw(8) << Reel
		<< left << fixed << setprecision(2) << setw(8) << ReelDouble;

	cout << '\n' << '\n' << "Essai du cadrage à droite et de la notation scientifique:" << '\n';

	cout << right << setw(12) << Entier
		<< right << setw(12) << EntierCourt
		<< right << setw(12) << EntierLong
		<< right << setw(12) << SansSigne
		<< right << setw(12) << Carac
		<< '\n' << fixed << setprecision(5) << scientific << right <<  setw(15) << Reel
		<< fixed << setprecision(5) << right << scientific << setw(15) << ReelDouble;

	cout << '\n' << '\n' << "Essai de mise en page:" << '\n';

	cout << '\t' << left << setw(16) << "Entier" << setw(2) << "=" << setw(10) << hex << Entier
		<< '\n' << '\t' << left << setw(16) << "EntierCourt" << setw(2) << "=" << setw(10) << hex << EntierCourt
		<< '\n' << '\t' << left << setw(16) << "EntierLong" << setw(2) << "=" << setw(10) << hex << EntierLong
		<< '\n' << '\t' << left << setw(16) << "SansSigne" << setw(2) << "=" << setw(10) << hex << SansSigne
		<< '\n' << '\t' << left << setw(16) << "Carac" << setw(2) << "=" << setw(10) << Carac
		<< '\n' << '\t' << left << setw(16) << "Reel" << setw(2) << "=" << right << fixed << setprecision(3) << setw(10) << Reel
		<< '\n' << '\t' << left << setw(16) << "ReelDouble" << setw(2) << "=" << right << fixed << setprecision(3) << setw(10) << ReelDouble;

	_getch();
}