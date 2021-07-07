#include "testRepo.h"
#include "Repo.h"
#include <assert.h>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void teste() {
	Repo r;
	int n = r.getSize();

	Examen* Studenti;
	Studenti = r.getAll();


	char* x = new char[10];
	strcpy_s(x, 9, "internet");
	Examen e1 = Examen(x, 11, 7);
	r.add(e1);
	assert(r.getSize() == 1);

	char* c = new char[10];
	strcpy_s(c, 4, "Apa");
	Examen e2 = Examen(c, 15, 6);
	r.add(e2);
	assert(r.getSize() == 2);

	char* sir = new char[10];
	strcpy_s(sir, 4, "apa");
	Examen e3 = Examen(sir, 13, 9);
	r.add(e3);
	assert(r.getSize() == 3);
	r.detele(e3);
	assert(r.getSize() == 2);
	r.find(e1);
	int poz_init = r.find(e1);
	assert(r.find(e1) == 0);
	r.find(e2);
	int poz = r.find(e2);
	assert(r.find(e2) == 1);
	cout << "tests repo.xd.." << endl;


}