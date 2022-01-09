/**
* AUTEUR: Alexis Provost
* FICHIER: TP2a.cpp
* DESCRIPTION: TP2a
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "C:\\cvm.h"

using namespace std;

void main(void) {
	float PrixKw, Redevance, MontantTps, MontantTvq, TotalFacture;
	int NbKwHres, NbJour;
	string NomClient, PrenomClient;

	const float TPS = 0.05, TVQ = 0.09975, TARIF_JOUR = 0.4064, TARIF_KWH = 0.0608;
	NbKwHres = 1900;
	NbJour = 61;
	PrixKw = NbKwHres * TARIF_KWH;
	Redevance = NbJour * TARIF_JOUR;
	MontantTps = (PrixKw + Redevance) * TPS;
	MontantTvq = (PrixKw + Redevance) * TVQ;
	TotalFacture = PrixKw + Redevance + MontantTps + MontantTvq;
	NomClient = "LeBranché";
	PrenomClient = "Yvon";

	//Support des accents
	locale::global(locale{ "" });

	cout << "Facture électrique de " << NomClient << " " << PrenomClient
		<< '\n' << "Pour une consommation de " << NbKwHres << " kWh sur " << NbJour <<" jours:";

	cout << '\n' << '\n' << setw(25) << left << fixed << setprecision(2) << "Redevance:" << "$" << setw(7) << right << Redevance
		<< '\n' << setw(25) << left << fixed << setprecision(2) << "Consommation:" << "$" << setw(7) << right << PrixKw
		<< '\n' << setw(25) << left << fixed << setprecision(2) << "TPS:" << "$" << setw(7) << right << MontantTps
		<< '\n' << setw(25) << left << fixed << setprecision(2) << "TPS:" << "$" << setw(7) << right << MontantTvq
		<< '\n' << setw(25) << left << fixed << setprecision(2) << "" << "--------"
		<< '\n' << setw(25) << left << fixed << setprecision(2) << "Total:" << "$" << setw(7) << right << TotalFacture;

	_getch();
}