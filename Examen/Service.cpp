#include "Repo.h"
#include <string>
#include <algorithm> 
#include "Service.h"

using namespace std;
Service::Service()
{
	//this->repo = Repo();
}
Service::Service( Repo& r)
{
	this->repo = r;
}
Service::Service(const Service& s)
{
	//cout << "constructor de copiere controller" << endl;
	this->repo = s.repo;
}
void Service::setRepo(const Repo& r)
{
	this->repo = r;
}

void Service::addExamen(Examen& e)
{
	repo.add(e);
}

void Service::delExamen(Examen& ex)
{
	repo.detele(ex);
}
Service& Service::operator=(const Service &s)
{
	if (this != &s) this->repo = s.repo;
	return *this;
}

Examen* Service::getAlls()
{
	return this->repo.getAll();
}

Examen Service::updateExamen(Examen e2, char* n, int a,int b)
{
	repo.update(e2, n, a,b);
	return e2;
}
int Service::findOne(Examen e3)
{
	return repo.find(e3);
}

int Service::getNumarServ() {
	return this->repo.getSize();
}
Repo Service::getRepo()
{
	return this->repo;
}


Service::~Service()
{
}
