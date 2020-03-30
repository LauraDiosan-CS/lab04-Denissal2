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
	Repo(const Repo&);
	Repo& operator=(const Repo&);
	//Repo& operator!=(const Repo&);
	// op =
	~Repo();
	// Destructor
	void add(Examen&);
	// Adaugarea unui examen
	Examen* getAll();
	// Toate examenele
	void del(Examen&);
	// Stergere examen
	int find(Examen&);
	//Cauta examen
	int getSize();
	// MARIMEa,nr de examene
	void update(Examen&, char*, int, int);
	void updateData(int, int);
	void updateNota(int, int);
	void updateNume(char*, char*);
	Examen& getItemFromPos(int);
	int cautaPozData(int);
	int cautaPozNota(int);
	int cautaPozNume(char*);
	int cautaData(int);
	int cautaNume(char*);
	int cautaNota(int);
	void afisareLista();
    Examen& getExamen(int);

};
#endif