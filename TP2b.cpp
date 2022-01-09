/**
* AUTEUR: Alexis Provost
* FICHER: TP2b.cpp
* DESCRIPTION: TP2b
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "C:\\cvm.h"

using namespace std;

void main(void) {
	const float TPS = 0.05;
	const float TVQ = 0.09975;
	const float TARIF_JOUR = 0.39;
	const float TARIF_1 = 0.0474;
	const float TARIF_2 = 0.0597;
	int NbKwHres, NbJour;
	string NomClient, PrenomClient;
	float Prix_1, Prix_2, Redevance, MontantTps, MontantTvq, TotalFacture;

	//Support des accents
	locale::global(locale{ "" });

	cout << "Quel est votre prénom : ";
	getline(cin, PrenomClient);

	cout << "Quel est votre nom : ";
	getline(cin, NomClient);

	cout << '\n' << "Quelle est votre consommation en KWH : ";
	cin >> NbKwHres;

	cout << "Sur combien de jours : ";
	cin >> NbJour;

	cout << '\n' << '\n' << '\n' << '\n' << '\t' << '\t' << '\t' << "Pressez une touche pour continuer";

	_getch();

	clrscr();

	cout << "Facture électrique de : " << PrenomClient << " " << NomClient;

	cout << '\n' << '\n' << "Consommation de " << NbKwHres << " KWH sur " << NbJour << " jours : ";

	if (NbKwHres > (30*NbJour)) {
		Prix_1 = TARIF_1 * (30 * NbJour);
		Prix_2 = TARIF_2 * (NbKwHres - (30 * NbJour));
	}
	else {
		Prix_1 = NbKwHres * TARIF_1;
		Prix_2 = 0;
	}

	cout << '\n' << '\n' << '\n';

	Redevance = NbJour * TARIF_JOUR;
	MontantTps = (Prix_1 + Prix_2 + Redevance) * TPS;
	MontantTvq = (Prix_1 + Prix_2 + Redevance) * TVQ;
	TotalFacture = Prix_1 + Prix_2 + Redevance + MontantTps + MontantTvq;

	cout << setw(35) << left << "Redevance:" << setw(2) << "$ " << setw(7) << right << fixed << setprecision(2) << Redevance;
	cout << '\n' << "Consommation:";
	cout << '\n' << '\t' << setw(27) << left << "premier 40 KWH par jour" << setw(2) << "$ " << setw(7) << right << fixed << setprecision(2) << Prix_1;
	cout << '\n' << '\t' << setw(27) << left << "KWH supp" << setw(2) << "$ " << setw(7) << right << fixed << setprecision(2) << Prix_2;
	cout << '\n' << setw(35) << left << "TPS:" << setw(2) << "$ " << setw(7) << right << fixed << setprecision(2) << MontantTps;
	cout << '\n' << setw(35) << left << "TVQ:" << setw(2) << "$ " << setw(7) << right << fixed << setprecision(2) << MontantTvq;
	cout << '\n' << setw(35) << left << "" << setw(10) << "---------";
	cout << '\n' << setw(35) << left << "Total:" << setw(2) << "$ " << setw(7) << right << fixed << setprecision(2) << TotalFacture;


	MessageBoxA(NULL, "Au revoir!", "Fin du programme", MB_OK | MB_ICONINFORMATION);
}