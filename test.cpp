#include "Examen.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <cstring>
#include "test.h"

using namespace std;

void teste2() {
	Examen e1 = Examen();
	assert(e1.getNume() == NULL);
	assert(e1.getData() == 0);
	assert(e1.getNota() == 0);


	char* x = new char[10];
	strcpy_s(x, 7, "Darius");
	Examen e2 = Examen(x, 30, 8);
	assert(strcmp(e2.getNume(), x) == 0);
	assert(e2.getData() == 30);
	assert(e2.getNota() == 8);

	Examen e3 = Examen(e2);
	assert(strcmp(e3.getNume(), "Darius") == 0);
	assert(e3.getData() == 30);
	assert(e3.getNota() == 8);
	assert(e2.compare(e3) == true);

	e3.setData(25);
	assert(e3.getData() == 25);

	assert(e2.compare(e3) == false);

	cout << "teste Examen" << endl;
}