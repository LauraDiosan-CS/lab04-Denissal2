#include "Examen.h"
#include <string.h>
#include <cstddef>
#include <iostream>
#include <ostream>

using namespace std;
Examen::Examen() {
	// initializare,constructor implicit
	this->nume = NULL;
	this->data = 0;
	this->nota = 0;
}
Examen::Examen(char* nume, int data, int nota) {
	// contructor cu parametri
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, 1 + strlen(nume), nume);
	this->data = data;
	this->nota = nota;
}
Examen::Examen(const Examen& e) {
	cout << "copy constructor" << endl;
	this->nume = new char[strlen(e.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(e.nume), e.nume);
	this->data = e.data;
	this->nota = e.nota;
}

//Geteri

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
	if (this->nume != NULL) {
		delete[] this->nume;
	}
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);

}

void Examen::setData(int data) {
	this->data = data;
}

void Examen::setNota(int nota) {
	this->nota = nota;
}


Examen& Examen::operator=(const Examen& e) {
	this->setNume(e.nume);
	this->setData(e.data);
	this->setNota(e.nota);
	return *this;
}


Examen::~Examen() {
	//Destructor (Dupa ce folosim cheltuiala la ce trebuie , facem putin loc in memorie)
	if (this->nume != NULL) {
		delete[] this->nume;
		this->nume = NULL;
		this->data = 0;
		this->nota = 0;
	}
}
// Compararea ( verificarea egalitatii dintre cheltuiala curenta si o a doua cheltuiala)
bool  Examen::compare(Examen& e) {
	return ((this->data == e.data) && (strcmp(this->nume, e.nume) == 0) && (this->nota == e.nota));
}

bool Examen:: operator==(const Examen& e) {
	return strcmp(this->nume, e.nume) == 0 && this->data == e.data && this->nota == e.nota;
}
