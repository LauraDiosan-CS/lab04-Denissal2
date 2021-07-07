#include <iostream>
#include <cstring>
#include <string>
#include "Examen.h"
#include "Repo.h"
#include "test.h"
#include "testRepo.h"
#include "testeService.h"
#include "stdlib.h"
#include "Meniu.h"
#include <conio.h>

using namespace std;



int main() {
	cout << " start main ..." << endl;
	teste2();
	teste();
	TestService ts;
	ts.runTest();
	int i = 0;
	Repo r;
	
	cout << "Trec testele?" << endl;
	cout << "au trecut testele!" << endl;
	cout << "Succes!" << endl;
	char opt;
	
	//Examen e;
	do
	{
		cout << endl << endl << "a.citire Examen+ adaugare Examen" << endl;
		cout << "b.afisarea Examenelor" << endl;
		cout << "c.stergere Examen " << endl;
		cout << "d.cauta Examen " << endl;
		cout << "e.modifica Examen" << endl;
		cout << "x.exit" << endl;
		cin >> opt;
		switch (opt)
		{

		case 'a':
			adaugare(r);
			break;
		case 'b':
			afisare(r);
			break;

		case 'c':
			stergere(r);

			break;

		case 'd':
			
			cout<<"Examinarea se afla pe pozitia :"<< "->" << cauta(r);
			break;
		case 'e' :
			modifica(r);
			break;
		case 'x':exit(1);
		default: 	cout << "can't" << endl;

		}
	} while (opt != 'x');
}


	


