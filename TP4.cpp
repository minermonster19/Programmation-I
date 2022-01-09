/**
* AUTEUR: Alexis Provost
* FICHIER: TP4.cpp
* DESCRIPTION: TP4
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "C:\\cvm.h"

using namespace std;

void main(void) {
	int NbOri, NbExe, NbImpR, NbImpRV, Reste;
	char FormatPapier, TypeImpression, TypePapier, Aperforer, TypeFaconnage;
	float CoutR, CoutRV, CoutPapier, CoutFaconnage, CoutProduction, CoutTotal;

	const float TPS = 0.05, TVQ = 0.09975, PRIX8x11R = 31, PRIX8x11RV = 60, PRIX11x17R = 61, PRIX11x17RV = 100,
				PRIX_PAPIER1 = 20.50, PRIX_PAPIER2 = 67.34, PRIX_PAPIER3 = 122.94, PRIX_BROCHER = 0.03,
				PRIX_ENCOLLER = 0.6, PRIX_TABLETTE = 0.35, PRIX_DOS_CHEVAL = 0.10, PRIX_PERFORER = 3;

	CoutR = 0, CoutRV = 0, CoutPapier = 0, CoutFaconnage = 0, CoutProduction = 0, CoutTotal = 0;

	locale::global(locale{"fr-CA"});

	cout << "Nombre d'originaux : ";

	cin >> NbOri;

	cout << "Nombre d'exemplaires à reproduire : ";

	cin >> NbExe;

	cout << "Type d'impression (R/V) : ";

	TypeImpression = _getche();

	TypeImpression = toupper(TypeImpression);

	cout << '\n' << '\n' << "Format du papier : " << endl;
	cout << '\t' << "1. 8½x11" << endl;
	cout << '\t' << "2. 8½x14" << endl;
	cout << '\t' << "3. 11x17" << endl;
	cout << '\n' << '\t' << "Votre choix : ";

	FormatPapier = _getche();

	cout << '\n' << '\n' << "Type de papier : " << endl;
	cout << '\t' << "1. Repro + gris" << endl;
	cout << '\t' << "2. Rolland évolution glacier" << endl;
	cout << '\t' << "3. Wausau royal, fibre texte étain" << endl;
	cout << '\n' << '\t' << "Votre choix : ";

	TypePapier = _getche();

	cout << '\n' << '\n' << "Souhaitez-vous perforer les documents ? (O/N) : ";

	Aperforer = _getche();

	Aperforer = toupper(Aperforer);

	cout << '\n' << '\n' << "Finition : " << endl;
	cout << '\t' << "1. Broche en coin" << endl;
	cout << '\t' << "2. Encoller avec ruban" << endl;
	cout << '\t' << "3. Tablettes" << endl;
	cout << '\t' << "4. Broche à dos de cheval" << endl;
	cout << '\t' << "5. Aucun" << endl;
	cout << '\n' << '\t' << "Votre choix : ";

	TypeFaconnage = _getche();

	cout << '\n' << '\n' << '\n' << '\t' << '\t' << '\t' << "Presser une touche pour continuer";

	clrscr();

	//Calcul étape 1 & 2
	if (FormatPapier == '1' || FormatPapier == '2') {
		if (TypeImpression == 'R') {
			//Étape 1
			NbImpR = NbOri * NbExe;
			NbImpRV = 0;	
		}
		else {
			//Étape 1
			if (NbOri % 2) {
				NbImpR = NbExe;
				NbImpRV = (NbOri - 1) * NbExe / 2;
			}
			else {
				NbImpR = 0;
				NbImpRV = NbOri * NbExe / 2;
			}
		}
		//Étape 2
		CoutR = PRIX8x11R / 1000;
		CoutRV = PRIX8x11RV / 1000;
	}
	else {
		if (TypeImpression == 'R') {
			// Étape 1
			if (NbOri % 2) {
				NbOri = NbOri + 1;
			}
			
			NbImpR = NbOri * NbExe / 2;
			NbImpRV = 0;
		}
		else {
			// Étape 1
			Reste = NbOri % 4;

			if (Reste == 0) {
				NbImpR = 0;
				NbImpRV = NbOri * NbExe / 4;
			}
			else if (Reste == 1 || Reste == 2) {
				NbImpR = NbExe;
				NbImpRV = (NbOri - Reste) * NbExe / 4;
			}
			else {
				NbImpR = 0;
				NbImpRV = (NbOri + 1) * NbExe / 4;
			}			
		}
		//Étape 2
		CoutR = PRIX11x17R / 1000;
		CoutRV = PRIX11x17RV / 1000;
	}

	CoutR = CoutR * NbImpR;
	CoutRV = CoutRV * NbImpRV;

	//Étape 3
	switch (TypePapier) {
		case '2':
			CoutPapier = PRIX_PAPIER2 / 1000;
			break;
		case '3':
			CoutPapier = PRIX_PAPIER3 / 1000;
			break;
		default:
			CoutPapier = PRIX_PAPIER1 / 1000;
	}

	if (FormatPapier == '1') {
		CoutPapier = CoutPapier / 2;
	}

	CoutPapier = CoutPapier * (NbImpRV + NbImpR);

	//Étape 4
	switch (TypeFaconnage) {
		case '1':
			CoutFaconnage = NbExe * PRIX_BROCHER;
			break;
		case '2':
			if (FormatPapier == '1' || FormatPapier == '2') {
				CoutFaconnage = NbExe * PRIX_ENCOLLER;
			}
			else {
				CoutFaconnage = 0;
			}
			break;
		case '3':
			CoutFaconnage = NbExe * PRIX_TABLETTE;
			break;
		case '4':
			if (FormatPapier == '3') {
				CoutFaconnage = NbExe * PRIX_DOS_CHEVAL;
			}
			else {
				CoutFaconnage = 0;
			}
			break;
		default:
			CoutFaconnage = 0;
	}

	if (Aperforer == 'O') {
		CoutFaconnage = CoutFaconnage + ((PRIX_PERFORER / 1000) * (NbImpR + NbImpRV));
	}

	//Étape 5
	CoutProduction = CoutR + CoutRV + CoutPapier + CoutFaconnage;
	CoutTotal = CoutProduction + (CoutProduction * TPS) + (CoutProduction * TVQ);

	cout << '\n' << '\n' << '\n' << fixed << setprecision(2) << left << setw(40) << "Coût des impression recto : " << right << setw(9) << CoutR << "$" << endl;
	cout << left << setw(40) << "Coût des impressions recto-verso : " << right << setw(9) << CoutRV << "$" << endl;
	cout << left << setw(40) << "Coût du papier : " << right << setw(9) << CoutPapier << "$" << endl;
	cout << left << setw(40) << "Coût du façonnage : " << right << setw(9) << CoutFaconnage << "$" << endl;
	cout << left << setw(41) << "" << right << setw(9) << "---------" << endl;
	cout << '\n' << left << setw(40) << "Coût de production : " << right << setw(9) << CoutProduction << "$" << endl;
	cout << left << setw(41) << "" << right << setw(9) << "=========" << endl;
	cout << '\n' << left << setw(40) << "Coût total : " << right << setw(9) << CoutTotal << "$" << endl;

	_getch();
}