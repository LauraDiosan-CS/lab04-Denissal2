#include "Repo.h"
Repo::Repo() {
	this->n = 0;
}

void Repo::add(Examen& e) {
	this->elem[this->n++] = e;
}
Examen* Repo::getAll() {
	return this->elem;
}
int Repo::getSize() {
	return this->n;
}

int Repo::find(Examen& e) {
	for (int i = 0;i < n;i++)
		if (elem[i] == e) return i;
	return -1;
}

void Repo::detele(Examen& e)
{
	int i = find(e);
	if (i != -1) {
		elem[i] = elem[n - 1];
		n--;
	}
}






Repo::~Repo() {
	this->n = -1;
}
