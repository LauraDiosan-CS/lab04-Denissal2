#include <ostream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <iostream>
using namespace std;
#ifndef EXAMEN_H
#define EXAMEN_H
class Examen {
private:
	// Ceea din ce este constituit examenul (tip sir de caractere ->nume,tip int data si nota*)
	char* nume;
	int data;
	int nota;

public:
	// constructor fara parametrii(explicit se mai numeste daca nu gresesc)
	Examen();
	// constructor cu parametrii
	Examen(char*, int, int);
	// constructor de copiere
	Examen(const Examen&);
	//Examen(string);//constructor de conversie
	char* getNume();
	int getData();
	int getNota();
	// Setteri pentru nume,data si nota
	void setNume(char*);
	void setData(int);
	void setNota(int);
	// Destructorul (Dupa ce te folosesti de ceva si numai ai absolut nevoie de el ->se va sterge ,cam asta e traducerea)
	~Examen();
	// operator de atribuire
	Examen& operator=(const Examen&);
	// Compara 2 examene!(Intr-un fel si asta poate fi ca cei de mai sus!)
	bool operator==(const Examen& e);
	// Compara 2 examene!(Intr-un fel si asta poate fi ca cei de mai sus!)
	bool compare(Examen& e);
	bool operator<(const Examen&);
	char* toString();
	friend ostream& operator<<(ostream&, Examen&);
	friend istream& operator>>(istream&, Examen&);
};

#endif