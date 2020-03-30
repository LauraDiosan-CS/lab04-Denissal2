#include "testRepo.h"
#include "Repo.h"
#include <assert.h>
#include <iostream>
#include <cstring>
#include <string>


using namespace std;

void teste() {
	// Avem nevoie de un Repository r
	Repo r;
	//int n = r.getSize();
	Examen* Studenti;
	Studenti = r.getAll();
	char* x = new char[10];
	strcpy_s(x, 9, "internet");
	Examen e1 = Examen(x, 11, 7);
	r.add(e1);
	assert(strcmp((Studenti[0]).toString(), "internet 11 7 ") == 0);
	r.find(e1);
	int poz_init = r.find(e1);
	assert(r.find(e1) == 0);
	assert(r.getSize() == 1);	
	assert(r.getItemFromPos(0) == Studenti[0]);
	assert(r.cautaPozData(11) == 0);
	assert(r.cautaPozNota(7) == 0);
	assert(r.cautaPozNume(x) == 0);
	// Nu se pune "internet " ! (Eroare! , char* incompatibil..)
	char* b = new char[15];
	strcpy_s(b, 5, "aere");
	r.update(e1, b, 24, 10);
	assert(strcmp((Studenti[0]).toString(), "aere 24 10 ") == 0);
	assert(r.find(Studenti[0]) == 0);
	assert(r.cautaPozData(24) == 0);
	assert(r.cautaPozNota(10) == 0);
	assert(r.cautaPozNume(b) == 0);
	assert(r.cautaNota(10) == 0);
	assert(r.cautaNume(b) == 0);
	// Daca nu pun b ->apare eroare -> convertire de la char * la const char[5] imposibila!
	
	
	
	char* c = new char[10];
	strcpy_s(c, 4, "Apa");
	Examen e2 = Examen(c, 15, 6);
	r.add(e2);
	r.find(e2);
	int pozitie = r.find(e2);
	assert(r.find(e2) == 1);
	assert(strcmp((Studenti[1]).toString(), "Apa 15 6 ") == 0);
	char* a = new char[15];
	strcpy_s(a, 4, "aer");
	r.update(e2, a, 13, 8);
	assert(strcmp((Studenti[1]).toString(), "aer 13 8 ") == 0);
	assert(r.getItemFromPos(1) == Studenti[1]);
	assert(r.find(Studenti[1]) == 1);
	assert(r.cautaNota(8) == 1);
	assert(r.cautaData(13) == 1);
	assert(r.cautaNume(a) == 1);
	r.updateData(13, 18);
	r.updateNota(8, 10);
	char* ax = new char[15];
	strcpy_s(ax, 3, "ar");
	r.updateNume(a, ax);
	assert(strcmp((Studenti[1]).toString(), "ar 18 10 ") == 0);
	assert(r.cautaData(18) == 1);
	assert(r.cautaPozData(18) == 1);



	char* sir = new char[10];
	strcpy_s(sir, 4, "apa");
	Examen e3 = Examen(sir, 13, 9);
	r.add(e3);
	assert(strcmp((Studenti[2]).toString(), "apa 13 9 ") == 0);
	assert(r.getItemFromPos(2) == Studenti[2]);
	r.find(e3);
	assert(r.find(e3) == 2);
	assert(r.getSize() == 3);
	char* q = new char[25];
	strcpy_s(q, 7, "Marius");
	r.update(e3, q, 23, 8);
	assert(strcmp((Studenti[2]).toString(), "Marius 23 8 ") == 0);
	assert(r.find(Studenti[2]) == 2);
	r.del(Studenti[2]);
	assert(r.getSize() == 2);
	assert(r.cautaData(24) == 0);
	r.add(e3);
	assert(strcmp((Studenti[2]).toString(), "apa 13 9 ") == 0);
	assert(r.getItemFromPos(2) == Studenti[2]);
	r.find(e3);
	assert(r.find(e3) == 2);
	assert(r.getSize() == 3);
	r.updateData(13, 19);
	r.updateNota(9, 7);
	assert(strcmp((Studenti[2]).toString(), "apa 19 7 ") == 0);
	
	
	
	
	

	

	Repo re = Repo();
	assert(re.getSize() == 0);
	
	cout << "tests repo..." << endl;
	// cout au rol pentru a vedea daca testele ruleaza ->vom vedea in main

}