#pragma once
#include "testeService.h"
#include "Service.h"
#include <assert.h>
#include <iostream>
using namespace std;

void TestService::testeaza()
{
	
	
	//Repo repo;
	// //Serv serv = Serv(repo);
	Service serv;
	//serv.setRepo(repo);
	Examen* Situatii;
	Situatii = serv.getAlls();
	char* x = new char[10];
	strcpy_s(x, 9, "internet");
	Examen e1 = Examen(x, 8, 8);
	assert(serv.getNumarServ() == 0);
	serv.addExamen(e1);
	assert(e1.getData() == 8);
	assert(e1.getNota() == 8);
	assert(strcmp(e1.getNume(), x) == 0);
	assert(strcmp((Situatii[0]).toString(), "internet 8 8 ") == 0);
	assert(serv.getNumarServ() == 1);
	assert(serv.findOne(e1) == 0);
	char* xy = new char[28];
	strcpy_s(xy, 5, "mere");
	serv.updateExamen(e1, xy, 21, 8);
	assert(Situatii[0].getData() == 21);
	assert(strcmp((Situatii[0]).toString(), "mere 21 8 ") == 0);
	assert(serv.getNumarServ() == 1);
	assert(serv.findOne(Situatii[0])== 0);


	char* y = new char[19];
	strcpy_s(y, 10, "internetx");
	Examen e2 = Examen(y, 12, 9);
	assert(serv.getNumarServ() == 1);
	serv.addExamen(e2);
	assert(e2.getData() == 12);
	assert(e2.getNota() == 9);
	assert(strcmp(e2.getNume(),y) == 0);
	assert(serv.getNumarServ() == 2);
	assert(strcmp((Situatii[1]).toString(), "internetx 12 9 ") == 0);
	assert(serv.findOne(e2) == 1);
	char* xyz = new char[28];
	strcpy_s(xyz, 6, "xmere");
	serv.updateExamen(e2, xyz, 22, 9);
	assert(strcmp((Situatii[1]).toString(), "xmere 22 9 ") == 0);
	assert(e2.getNota() == 9);
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
	serv.updateExamen(e3, xyza, 2, 10);
	assert(strcmp((Situatii[2]).toString(), "xmerex 2 10 ") == 0);
	assert(strcmp(Situatii[2].getNume(),xyza) == 0);
	assert(serv.getNumarServ() == 3);
	assert(serv.findOne(Situatii[2]) == 2);
	serv.delExamen(Situatii[1]);
	// e2 -> pusca, Acum sunt retinuti in vectorul de Situatii
	assert(serv.getNumarServ() == 2);

	
	cout << "teste ...Service" << endl;
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

