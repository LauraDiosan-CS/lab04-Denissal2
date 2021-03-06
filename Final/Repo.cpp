#include "Repo.h"
Repo::Repo() {
	// e suficient sa spunemca this->n = 0 (n este de tip n !)
	this->n = 0;
}
Repo& Repo::operator=(const Repo& r) {
	if (this != &r)
	{
		this->n = r.n;
		for (int i = 0; i < this->n; i++)
			this->elem[i] = r.elem[i];
	}
	return *this;
}


Repo::Repo(const Repo& r) {
	this->n = r.n;
	for (int i = 0; i < this->n; i++)
		this->elem[i] = r.elem[i];
}
void Repo::add(Examen& e) {
	//   this->elem[this->n++] ( this->n = 0) -> this->elem[0] =e1 ,dupa daca adaugam this->elem[1]=e2,se pune [this->n++] astfel pentru ca sa luam valoarea de la adresa,ci nu adresa,adresa este un numar haotic 322421321 de exemplu!
	this->elem[this->n++] = e;
}


Examen* Repo::getAll() {
	// returnam elementele(examenele)
	return this->elem;
}

Examen& Repo::getExamen(int pos) {
	return this->elem[pos];
}

int Repo::getSize() {
	// Numarul de examene , marimea
	return this->n;
}

int Repo::find(Examen& e) {
	// cautarea unui examen , se aplica un for astfel incat sa nu iesim din vectorul de examene
	for (int i = 0;i < n;i++)
		// returnam i daca acesta este examenul cautat ,altfel -1,nu gasim acest examen!
		if (elem[i] == e) return i;
	return -1;
}

void Repo::del(Examen& e)
// int i = find(e) , Cautam examenul pe care-l stergem , cat timp i != -1 ,adica cat timp exista acest examen
// elem[i] = elem[n-1];n--
{
	int i = find(e);
	if (i != -1) {
		elem[i] = elem[n - 1];
		// de exemplu pentru i =5  si n = 10 -> elem[5] = elem [9] si n  devine 9
		// daca n devine 9,vom avea in vectorii de examene -> elem[0].... elem[8],fara elem[9],deci elem[5] este sters!
		// De la elem[5] incolo elementele vor suferi urmatoarele elem[6] = elem[6-1],...elem[9] = elem[9-1]
		// Sper ca am inteles corect,dar asa cred ca este!
		n--;
	}
}


void Repo::update(Examen& e, char* name, int date,int notare) {

	int i = find(e);
	if (i != -1) {
		elem[i].setNume(name);
		elem[i].setData(date);
		elem[i].setNota(notare);
	}
}


Examen& Repo::getItemFromPos(int i) {
	return elem[i];
}

int Repo::cautaPozData(int data) {
	// se fol pt update data ->de mai jos  (daca as folosi cel de sus ,nu ar merge ,este total ilogic!)
	int pozc = -1;
	
	for (int i = 0; i < this->n; i++) {
		if (elem[i].getData() == data) {
			pozc = i;
		}
	}
	return pozc;
}


int Repo::cautaPozNota(int nota) {
	int pozc = -1;
	for (int i = 0;i < this->n;i++) {
		if (elem[i].getNota() == nota) {
			pozc = i;
		}
	}
	return pozc;
}

int Repo::cautaPozNume(char* nume) {

	int pozc = -1;
		for (int i = 0;i < this->n;i++) {
			if (strcmp(elem[i].getNume(), nume) == 0) {
				pozc = i;
			}
	}
		return pozc;
}

void Repo::updateData(int d1, int d2) {
	int rez ;
	rez = this->cautaPozData(d1);
	//Aici am nevoie neaparata de operatorul = al Repo
	elem[rez].setData(d2);
	
}


void Repo::updateNota(int n1, int n2) {
	int rez;
	rez = this->cautaPozNota(n1);
	elem[rez].setNota(n2);
}

void Repo::updateNume(char* x, char* y) {
	int rez;
	rez = this->cautaPozNume(x);
	elem[rez].setNume(y);
}



int Repo::cautaNume(char* nume)
{   
	int pozc = 0;
	Examen* Examene;
	Examene = getAll();
	for (int i = 0; i < this->n; i++) {
		if (strcmp(elem[i].getNume(), nume) == 0) {
			pozc = i;
		}
	}
	return pozc;
}

int Repo::cautaNota(int nota){
	int pozc = 0;
	Examen* Examene;
	Examene = getAll();
	for (int i = 0; i < this->n; i++) {
		if (elem[i].getNota() == nota) {
			pozc = i;
		}
	}
	return pozc;
}

int Repo::cautaData(int data){
	int pozc = 0;
	Examen* Examene;
	Examene = getAll();
	for (int i = 0;i<this->n;i++)
	{
		if (elem[i].getData() == data) {
			pozc = i;
		}
	}
	return pozc;
}


void Repo::afisareLista()
{
	Examen* e = new Examen[this->n];
     e = this->getAll();
	for (int i = 0; i < this->n; i++)
		cout << e[i];
}

Repo::~Repo() {
	// destructor , se putea si 0 in loc de -1 daca nu gresesc!
	this->n = -1;
}
