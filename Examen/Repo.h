#ifndef REPO_H
#define REPO_H
#include "Examen.h"
#include <iostream>
using namespace std;
class Repo {
private:
	// Un vector in care avem 30 de elemente de tip examen sa zic asa
	Examen elem[300];
	// n este dimensiunea sau this->size 
	int n;
public:
	Repo();
	// Constructor implicit
	~Repo();
	// Destructor
	void add(Examen&);
	// Adaugarea unui examen
	Examen* getAll();
	// Toate examenele
	void detele(Examen&);
	// Stergere examen
	int find(Examen&);
	//Cauta examen
	int getSize();
	// MARIMEa,nr de examene
	void update(Examen&, char*, int, int);
	Examen getItemFromPos(int);
	int cautaData(int);
	int cautaNume(char*);
	int cautaNota(int);
	void afisareLista();
	char* toString();

};
#endif