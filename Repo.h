#ifndef REPO_H
#define REPO_H
#include "Examen.h"
class Repo {
private:
	Examen elem[30];
	int n;
public:
	Repo();
	~Repo();
	void add(Examen&);
	Examen* getAll();
	void detele(Examen&);
	int find(Examen&);
	int getSize();


};
#endif