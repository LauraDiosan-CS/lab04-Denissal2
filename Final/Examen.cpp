
#include <string.h>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdlib.h>
#include "Examen.h"


using namespace std;
Examen::Examen() {
	// initializare,constructor implicit
	this->nume = NULL;
	this->data = 0;
	this->nota = 0;
}
Examen::Examen(char* nume, int data, int nota) {
	// contructor cu parametri
	//  new char[strlen(nume)+1 ...Acel new apare din cauza ca dupa cum vedem avem un pointer,strlen(nume)+1 ->lungimea numelui +1 (adica abc -> str(len)+1=4 acel "+1" ->backslash*"
	// Dupa ce scriem prima linie de cod din interior trebuie sa aplicam strcpy_s -> si doar asa reusim sa specificam ca this->nume = nume*
	// strcpy(destinatie,lungime,ceea ce trebuie sa ajunga la destinatie(sa fie aceasta daca e sa o luam asa!)
	// strcpy se aplica aici pentru ca avem un sir de caractere ca parametru 
	//Ca la vectori dinamici ,alocam spatiu care ulterior daca nu gresesc se va dealoca in destructor*
	//Alocarea are loc prin prima linie de cod * ,iar strcpy ->copiem nume in this->nume*
	// la int nu se aplica acelas rationament!
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, 1 + strlen(nume), nume);
	this->data = data;
	this->nota = nota;
}
Examen::Examen(const Examen& e) {
	// Constructorul de copiere , primele 2 linii de cod identice cu cele de la  constructorul cu parametrii
	// doar ca aici avem un Examen e  si this->nume va vrea sa-i ia numele acestuia si de aceea acolo avem e.nume*
	// this->data = e.data (data examenului e *)
	//cout << "copy constructor" << endl;
	this->nume = new char[strlen(e.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(e.nume), e.nume);
	this->data = e.data;
	this->nota = e.nota;
}

//Geteri
//   Voi explica la teste importanta lor *!

Examen::Examen(string linie)
{
	std::istringstream iss(linie);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2 >> tok3;
	nume = new char[tok1.length() + 1];
	strcpy_s(nume, tok1.length() + 1, tok1.c_str());
	data = stoi(tok2);
	nota = stoi(tok3);
}




char* Examen::getNume() {
	return this->nume;
}

int Examen::getData() {
	return this->data;
}

int Examen::getNota() {
	return this->nota;
}

//Seteri


void Examen::setNume(char* nume) {
	// Dezalocare(pentru ca s-ar putea sa existe un nume(in general exista)
	if (this->nume != NULL) {
		delete[] this->nume;
	}
	// realocare si copierea noului nume in this->nume
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);

}

void Examen::setData(int data) {
	this->data = data;
}

void Examen::setNota(int nota) {
	this->nota = nota;
}
char* Examen::toString() {
	if (this->nume != NULL) {
		int noChars = strlen(this->nume) + 13;
		char* s = new char[noChars];
		char* aux = new char[5];
		char* aux2 = new char[5];
		strcpy_s(s, noChars, this->nume);
		strcat_s(s, noChars, " ");
		_itoa_s(this->data, aux2, 5, 10);
		_itoa_s(this->nota, aux, 5, 10);
		strcat_s(s, noChars, aux2);
		strcat_s(s, noChars, " ");
		strcat_s(s, noChars, aux);
		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		strcat_s(s, noChars," ");
		return s;
	}
	else
	{
		char* x = new char[1];
		strcpy_s(x, 1, "");
		return x;
	}
}


Examen& Examen::operator=(const Examen& e) {
	// Aici daca nu gresesc totusi nu e vorba de egalitate si de operatorul de atribuire!(lui this ii se atribuie ceva nou(cu ajutorul Seterilor)!
	this->setNume(e.nume);
	this->setData(e.data);
	this->setNota(e.nota);
	// return *this ->valoarea adresei respective
	return *this;
}


Examen::~Examen() {
	//Destructor (Dupa ce folosim Examenul la ce trebuie , facem putin loc in memorie)
	if (this->nume != NULL) {
		delete[] this->nume;
		this->nume = NULL;
	}
	this->data = 0;
	this->nota = 0;
}
// Compararea ( verificarea egalitatii dintre Examenul curenta si o a doua Examenul)
bool  Examen::compare(Examen& e) {
	// verificarea data this->examen este egal cu examenul e 
	return ((this->data == e.data) && (strcmp(this->nume, e.nume) == 0) && (this->nota == e.nota));
}

bool Examen::operator<(const Examen& e)
{
	return ((strcmp(this->nume, e.nume) < 0) && (this->data < e.data) && (this->nota < e.nota));

}


bool Examen:: operator==(const Examen& e) {
	// la fel ca mai sus * (egalitate)
	return strcmp(this->nume, e.nume) == 0 && this->data == e.data && this->nota == e.nota;
}

bool Examen:: operator!=(const Examen& e) {

	 return strcmp(this->nume, e.nume) == 0 && this->data == e.data && this->nota != e.nota;

}

ostream& operator<<(ostream& os, Examen& e) {
	os <<"[nume:"<< e.nume << "-data:" << e.data << "-nota:" << e.nota << "]" ;
	
	return os;
}

istream& operator>>(istream& is, Examen& e)
{
	cout << "Dati numele: ";
	char* nume = new char[20];
	//char nume[20];
	//is.get(nume,20);
	//cin.get(nume,19);
	cin >> nume;
	cout << "Dati data: ";
	int data;
	cin >> data;
	cout << "Dati nota:";
	int nota;
	cin >> nota;
	e.setNume(nume);
	e.setData(data);
	e.setNota(nota);
	delete[] nume;
	return is;
}



