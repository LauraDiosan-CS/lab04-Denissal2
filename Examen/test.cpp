#include "Examen.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <cstring>
#include "test.h"

using namespace std;

void teste2() {
	Examen e1 = Examen();
	// Aici se folosesc acele geturi care ne ajuta sa determinam ceea ce ne intereseaza(data examenului de exemplu)!
	// Examenului e1 ii se atribuie constructorul fara parametrii deci e1.getNume este egal cu NUll si int-urile cu 0!
	assert(e1.getNume() == NULL);
	assert(e1.getData() == 0);
	assert(e1.getNota() == 0);
	

	char* x = new char[10];
	//alocare dinamica ,aici vom cuprinde numele Darius
	// il vom copia in x
	strcpy_s(x, 7, "Darius");
	Examen e2 = Examen(x, 30, 8);
	// Examen e2 primeste Examen(x , 30 ,8) , x= numele =Darius, 30 = data,8 -nota
	assert(strcmp(e2.getNume(), x) == 0);
	// in loc de x aici se poate pune si "Darius"
	// strcmp(e2.getNume(),x) == 0 -> asta inseamna ca numele este chiar Darius!
	// Nu se pune assert(e2.getNume() == Darius! gresit total,acesta fiind retinut intr-un this care este x...si asta este forma,nu stiu sa explic corect si nu ma bag,doar sa stii ca unde ai sir de caractere asa faci!)
	assert(e2.getData() == 30);
	//  Data ne asteptam sa fie 30 
	assert(e2.getNota() == 8);
	// Nota ne asteptam sa fie 8 
	assert(strcmp(e2.toString(), "Darius 30 8 ") == 0);
	Examen e3 = Examen(e2);
	// Examenul e3 primeste  Examen(e2)
	assert(strcmp(e3.getNume(), "Darius") == 0);
	// Se poate pune si x in loc de "Darius"
	// Ne asteptam ca numele de la examenul al studentului sa fie chiar Darius
	assert(e3.getData() == 30);
	assert(e3.getNota() == 8);
	assert(strcmp(e3.toString(), "Darius 30 8 ") == 0);
	// Observam ca e2 are aceleasi valori ca e3 ,deci sunt egale!
	assert(e2.compare(e3) == true);

	e3.setData(25);
	// Setam o noua data la examenul 3,astfel e3.getData() == va deveni 25
	assert(e3.getData() == 25);
	// Din cauza schimbarii datii  ,e2 != e3
	assert(e2.compare(e3) == false);
	assert(strcmp(e3.toString(), "Darius 25 8 ") == 0);
	e3.setNota(5);
	assert(e3.getNota() == 5);
	assert(strcmp(e3.toString(), "Darius 25 5 ") == 0);
	char* len = new char[25];
	strcpy_s(len, 9, "Anderson");
	assert(strcmp(len, "Anderson") == 0);
	e3.setNume(len);
	assert(strcmp(e3.toString(), "Anderson 25 5 ") == 0);
	cout << "teste Examen" << endl;
}