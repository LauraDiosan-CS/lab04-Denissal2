#pragma once
#include "testeService.h"
#include "Service.h"
#include <assert.h>
#include <iostream>
using namespace std;

void TestService::testeaza()
{
	Repo r;
	Service serv = Service(r);
	serv.setRepo(r);
	Examen* Situatii;
	Situatii = serv.getAlls();
	char* x = new char[10];
	strcpy_s(x, 9, "internet");
	Examen e1 = Examen(x, 8, 7);
	assert(serv.getNumarServ() == 0);
	serv.addExamen(e1);
	assert(e1.getData() == 8);
	assert(e1.getNota() == 7);
	assert(strcmp(e1.getNume(), x) == 0);
	assert(strcmp((Situatii[0]).toString(), "internet 8 7 ") == 0);
	assert(serv.getNumarServ() == 1);
	assert(serv.findOne(e1) == 0);
	char* xy = new char[28];
	strcpy_s(xy, 5, "mere");
	serv.updateExamen(e1, xy, 21, 7);
	assert(Situatii[0].getData() == 21);
	assert(strcmp((Situatii[0]).toString(), "mere 21 7 ") == 0);
	assert(serv.getNumarServ() == 1);
	assert(serv.findOne(Situatii[0])== 0);


	char* y = new char[19];
	strcpy_s(y, 10, "internetx");
	Examen e2 = Examen(y, 12, 7);
	assert(serv.getNumarServ() == 1);
	serv.addExamen(e2);
	assert(e2.getData() == 12);
	assert(e2.getNota() == 7);
	assert(strcmp(e2.getNume(), y) == 0);
	assert(serv.getNumarServ() == 2);
	assert(strcmp((Situatii[1]).toString(), "internetx 12 7 ") == 0);
	assert(serv.findOne(e2) == 1);
	char* xyz = new char[28];
	strcpy_s(xyz, 6, "xmere");
	serv.updateExamen(e2, xyz, 22, 7);
	assert(strcmp((Situatii[1]).toString(), "xmere 22 7 ") == 0);
	assert(e2.getNota() == 7);
	assert(serv.getNumarServ() == 2);
	assert(serv.findOne(Situatii[1]) == 1);




	char* z = new char[39];
	strcpy_s(z, 11, "xinternetx");
	Examen e3 = Examen(z, 19, 10);
	assert(serv.getNumarServ() == 2);
	serv.addExamen(e3);
	assert(e3.getData() == 19);
	assert(e3.getNota() == 10);
	assert(strcmp(e3.getNume(), z) == 0);
	assert(serv.getNumarServ() == 3);
	assert(strcmp((Situatii[2]).toString(), "xinternetx 19 10 ") == 0);
	assert(serv.findOne(e3) == 2);
	char* xyza = new char[28];
	strcpy_s(xyza, 7, "xmerex");
	serv.updateExamen(e3, xyza, 2, 9);
	assert(strcmp((Situatii[2]).toString(), "xmerex 2 9 ") == 0);
	assert(strcmp(Situatii[2].getNume(), xyza) == 0);
	assert(serv.getNumarServ() == 3);
	assert(serv.findOne(Situatii[2]) == 2);

	//Teste Functionalitati

	//Functionalitate 1 (Punct bonus )
	serv.adaugare_punct(xyz, 8);
	assert(Situatii[1].getNota() == 8);
	// Nota care initial a fost 7!
	serv.delExamen(Situatii[1]);
	// S-a sters elementul numarul 2;
	// e2 -> pusca, Acum sunt retinuti in vectorul de Situatii
	assert(serv.getNumarServ() == 2);
	
	
	//Functionalitate 2
	vector<Examen> rez = serv.ExameneBune(8);
	assert(rez[0] == Situatii[2]);
	vector<Examen> rezultat = serv.AdaugaPunct(xyza, 8);
	assert(rezultat[0].getNota() == 10);
	assert(rezultat[0] != Situatii[2]);
	serv.updateExamen(Situatii[2], xyza, 2, 10);
	assert(rezultat[0] == Situatii[1]);
	// E de fapt Situatii[2] ,dar Situatii[1],stergandu-se,ni-l face pe aceasta sa fie situatii 1!),cand aplicam update!
	//  Se adauga nota doar la afisarea lui rez[0] , nu se retine dupa aceea!
	

	// Si inca putin exercitiu...

	Service servic = Service();
	assert(servic.getNumarServ() == 0);
	cout << endl;
	cout << endl;
	cout << "teste ...Service" << endl;
}


void TestService::testeazaOperatii() {
	
	Service servs = Service();
	assert(servs.getNumarServ() == 0);
	Repo repo;
	Service servss = Service(repo);
	servss.setRepo(repo);
	assert(servss.getNumarServ() == 0);
	Examen* Situatii;
	Situatii = servss.getAlls();
	char* x = new char[10];
	strcpy_s(x, 9, "internet");
	Examen e1 = Examen(x, 8, 7);
	assert(servss.getNumarServ() == 0);
	servss.addExamen(e1);
	assert(e1.getData() == 8);
	assert(e1.getNota() == 7);
	assert(strcmp(e1.getNume(), x) == 0);
	assert(strcmp((Situatii[0]).toString(), "internet 8 7 ") == 0);
	assert(servss.getNumarServ() == 1);
	assert(servss.findOne(e1) == 0);


	char* y = new char[19];
	strcpy_s(y, 10, "internetx");
	Examen e2 = Examen(y, 12, 7);
	assert(servss.getNumarServ() == 1);
	servss.addExamen(e2);
	assert(e2.getData() == 12);
	assert(e2.getNota() == 7);
	assert(strcmp(e2.getNume(), y) == 0);
	assert(servss.getNumarServ() == 2);
	assert(strcmp((Situatii[1]).toString(), "internetx 12 7 ") == 0);
	assert(servss.findOne(e2) == 1);

	char* z = new char[39];
	strcpy_s(z, 11, "xinternetx");
	Examen e3 = Examen(z, 19, 10);
	assert(servss.getNumarServ() == 2);
	servss.addExamen(e3);
	assert(e3.getData() == 19);
	assert(e3.getNota() == 10);
	assert(strcmp(e3.getNume(), z) == 0);
	assert(servss.getNumarServ() == 3);
	assert(strcmp((Situatii[2]).toString(), "xinternetx 19 10 ") == 0);
	assert(servss.findOne(e3) == 2);
	Examen e4 = Examen(z, 20, 8);
	vector <Examen> Ser = servss.filterByNameAndGrade(0, "i", 5);
	assert(Ser[0] == Situatii[0]);
	assert(Ser[1] == Situatii[1]);
	vector <Examen> Sers = servss.filterByNameAndGrade(1, "i", 0);
	assert(Sers[0] == Situatii[0]);
	assert(Sers[2] == Situatii[2]);
	vector <Examen> Serss = servss.filterByNameAndGrade(2, "i", 9);
	assert(Serss[0] == Situatii[0]);
	vector <Examen> Vs = servss.sortByNota(0);
	assert(Vs[0] == Situatii[3]);
	vector <Examen> Vss = servss.sortByNota(1);
	assert(Vss[0] == Situatii[3]);
	vector <Examen> Final = servss.sortByName();
	assert(Final[0] == Situatii[0]);


	
	
	


}


TestService::TestService()
{
}

void TestService::runTest()
{
	testeaza();
	
}

TestService::~TestService()
{
}

