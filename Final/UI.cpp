#include <iostream>
#include "UI.h"
using namespace std;


void addExamen(Service& s) {
	Examen ex;
	cout << "Dati Examenul:"<<endl ;
	cin >> ex;
	s.addExamen(ex);
	cout << "Examenul a fost adaugat cu succes!" << endl;
}

void findExamen(Service& serv) {
	Examen ex;
	cout << "Dati Examenul:" <<endl;
	cin >> ex;
	int rez = serv.findOne(ex);
	cout <<"Pozitia Examenului sustinut de student este:" << rez;
}




void delExamen(Service& serv) {
	Examen ex;
	cout << "Dati examenul:"<<endl;
	cin >> ex;
	serv.delExamen(ex);
	cout << "Examen sters" << endl;
}

void showAll(Service& serv) {
	//Examen* Examene = serv.getAllserv();
	serv.afisare();
}

void UpdateExamen(Service& serv) {
	Examen student;
	cout << "Dati examenul de modificat:"<<endl ;
	cin >> student;
	char* newnume = new char[25];
	cout << "Noul nume" << endl;
	cin >> newnume;
	int newdata;
	cout << "Noua data" << endl;
	cin >> newdata;
	int newnota;
	cout << "Noua nota" << endl;
	cin >> newnota;
	serv.updateExamen(student, newnume, newdata, newnota);
	cout << "Examenul in cazul existentei acestuia a fost modificat!" << endl;


}

void AfisareNote(Service& serv) {
	int nota_minima = 0;
	cout << "Introduceti nota_minima: ";
	cin >> nota_minima;
	serv.afisareNotaBuna(nota_minima);
	

}

void NotaCeaMaiMare(Service& serv) {
	//int nota_max = 0;
	char* nume_st = new char[25];
	cout << " Introduceti numele elevului :" ;
	cin >> nume_st;
	serv.AfiseazaNotaCeaMaiMareMicaStudent(0,nume_st);
	serv.AfiseazaNotaCeaMaiMareMicaStudent(1, nume_st);
	//cout << " -> ";
	delete[] nume_st;

}

void OrdonareDupaData(Service& serv) {

	char* studentx = new  char[20];
	cout << "Introduceti numele studentului:";
	cin >> studentx;
	cout << "Ordonare crescatoare::";
	serv.OrdonareStudentiData(0,studentx);
	cout << endl;
	cout << "Ordonare descrescatoare->>>{" ;
	serv.OrdonareStudentiData(1, studentx);
	cout << "}";
	delete[] studentx;



}

void SumaNoteStudent(Service& serv) {
	char* nume_stud = new char[40];
	cout << " Introduceti numele studentului :" ;
	cin >> nume_stud;
	int s;
	// suma care va fi (se initializeaza cu 0) si se pune  ->> (nume_stud,s);
	serv.SumaNotelorStudentului(nume_stud,s);
	cout << "Suma este :" << s;
	delete[] nume_stud;

}

void AdaugarePunct(Service& serv) {
	char* nume_elev = new char[25];
	cout << " Introduceti numele elevului :" ;
	cin >> nume_elev;
	int punct_bonus=0;
	//cin >> punct_bonus;
	serv.adaugare_punct(nume_elev, punct_bonus);
	delete[] nume_elev;
	

}
void AfisareCorespunzatoare(Service& serv) {
	int v;
	cout << "Dati nota_minima:";
	cin >> v;

	vector<Examen> ex = serv.ExameneBune(v);
	for (Examen e : ex)
		cout << e;
}

void AdaugarePunctBonusStudent(Service& serv) {
	char* nume_student = new char[25];
	cout << " Introduceti numele elevului :";
	cin >> nume_student;
	int bonus = 0;
	vector<Examen> exam = serv.AdaugaPunct(nume_student,bonus);
	for (Examen e1 : exam)
	cout << e1;
	delete[] nume_student;


}



void showGradeSorted(Service& serv) {
	//int val = 0;
	vector<Examen> studx = serv.sortByNota(0);
	vector<Examen> stuxy = serv.sortByNota(1);
	for (Examen e2 : studx)
		cout << "Ordonare descrescatoare dupa nota: " << e2;
	cout << endl;
	cout << endl;
	for (Examen e3 : stuxy)
		cout << "Ordonare descrescatoare dupa nota cat timp nota >5:  " << e3;

}

void showNameSorted(Service& serv) {

	vector<Examen> study = serv.sortByName();
	for (Examen e3 : study)
		cout << e3;


}

void FiltreazaDupaNumeSiNota(Service& serv) {
	char* n = new char[23];
	cout << " Dati subsirul stringului de nume ";
	cin >> n;
	int vs;
	cout << "Nota minima = ";
	cin >> vs;
	vector<Examen> stdx = serv.filterByNameAndGrade(1,n,vs);
	for (Examen e4 : stdx)
		cout << e4;
	cout << endl;
	cout << endl;
	vector<Examen> stdxa = serv.filterByNameAndGrade(2, n, vs);
	for (Examen e5 : stdx)
		cout << e5 ;
	cout << endl;
	cout << endl;
	vector <Examen> stlx = serv.filterByNameAndGrade(3, n, vs);
	for (Examen e6 : stlx)
		cout << e6;
	cout << endl;
	cout << endl;
	delete[] n;



}


void showUI(Service& serv)
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "1.Adauga examen " << endl;
		cout << "2.Cauta examen " << endl;
		cout << "3.Sterge examen " << endl;
		cout << "4.Update examen" << endl;
		cout << "5.Afiseaza toate examenele " << endl;
		cout << "6.Afisarea notelor mai mari decat o anume nota" << endl;
		cout << "7.Adaugare punct bonus unui elev" << endl;
		cout << "8.Afisare note mai mari decat o nota data" << endl;
		cout << "9.Adaugare punct bonus student" << endl;
		cout << "10.Studenti ordonati descrescator dupa nota" << endl;
		cout << "11.Studenti ordonati crescator dupa nume" << endl;
		cout << "12.Cea mai mare si mica  nota a unui student " << endl;
		cout << "13.Suma note student" << endl;
		cout << "14.Ordonare studenti dupa data examenului sustinut" << endl;
		cout << "15.Afiseaza elevii care continut un anume substring in nume si au nota > a " << endl;
		cout << "0.EXIT!" << endl;
		cout << "Introduceti optiunea (nr): ";
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {addExamen(serv); break; }
		case 2: {findExamen(serv); break; }
		case 3: {delExamen(serv); break; }
		case 4: {UpdateExamen(serv); break;}
		case 5: {showAll(serv); break; }
		case 6: {AfisareNote(serv);break;}
		case 7: {AdaugarePunct(serv); break;}
		case 8: {AfisareCorespunzatoare(serv); break;}
		case 9: {AdaugarePunctBonusStudent(serv); break;}
		case 10: {showGradeSorted(serv); break;}
		case 11: {showNameSorted(serv);break;}
		case 12: {NotaCeaMaiMare(serv);break;}
		case 13: {SumaNoteStudent(serv); break;}
		case 14: {OrdonareDupaData(serv); break;}
		case 15: {FiltreazaDupaNumeSiNota(serv);break;}
		case 0: {gata = true; cout << "LA REVEDERE!" << endl; }
		}
	}
}