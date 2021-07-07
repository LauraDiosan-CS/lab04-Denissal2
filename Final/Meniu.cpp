#include "Meniu.h"

void adaugare(Repo& r) {
	char nume[30];
	cout <<"Numele"<<endl;
	cin >> nume;
	int data;
	cout <<"Data"<<endl;
	cin >> data;
	int nota;
	cout <<"Nota" << endl;
	cin >> nota;
	Examen e(nume, data, nota);
	r.add(e);
	cout << "Succes!" << endl;
}
void afisare(Repo& r) {
	r.afisareLista();
}
void stergere(Repo& r) {
	Examen e;
	cout <<"Dati examen:"<<endl;
	cin >> e;
	r.del(e);
}

int cauta(Repo& r) {
	int i;
	Examen e;
	cout << "Dati examenul de cautat" << endl;
	cin >> e;
	i=r.find(e);
	return i;
}
void modifica(Repo& r) {
	Examen e;
	cout << "Dati examen:"<<endl;
	cin >> e;
	char newnume[30];
	cout << "Noul nume" << endl;
	cin >> newnume;
	int newdata;
	cout << "Noua data" << endl;
	cin >> newdata;
	int newnota;
	cout << "Noua nota" << endl;
	cin >> newnota;
	r.update(e, newnume, newdata, newnota);
}