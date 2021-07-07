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
	void setRepo(const Repo&);
	Repo getRepo();
	void addExamen(Examen&);
	void delExamen(Examen&);
	Examen* getAlls();
	Examen updateExamen(Examen, char*, int,int);
	int findOne(Examen);
	int getNumarServ();
	
	~Service();
};
#endif