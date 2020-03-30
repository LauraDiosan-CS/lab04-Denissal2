#ifndef Service_H
#define Service_H
#include "Repo.h"
#include "Examen.h"
#include <vector>
#include <iostream>
// pentru viitorul apropiat
using namespace std;
class Service
{
private:
	Repo repo;
public:
	Service();
	Service(Repo &repo);
	Service(const Service& );
	Service& operator=(const Service&);
	Examen* getAllserv();
	void setRepo(const Repo&);
	Repo getRepo();
	void addExamen(Examen&);
	void delExamen(Examen&);
	void afisare();
	Examen* getAlls();
	Examen updateExamen(Examen, char*, int,int);
	int findOne(Examen);
	//int findOnex(Examen);
	int getNumarServ();
	void afisareNotaBuna(int);
	vector<Examen> ExameneBune(int);
	vector<Examen> AdaugaPunct(char*,int);
	void adaugare_punct(char*,int);
	//void setNumarServ(int);
	Examen& getExamenServ(int);
	vector<Examen> sortByNota(int);
	vector<Examen> sortByName();
	vector<Examen> filterByNameAndGrade(int,const char*,int );
	void AfiseazaNotaCeaMaiMareMicaStudent(int,char*);
	void SumaNotelorStudentului(char*,int &suma);
	void OrdonareStudentiData(int,char*);
	~Service();
};
#endif